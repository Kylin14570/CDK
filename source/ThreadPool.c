#include "ThreadPool.h"
#include <stdlib.h>
#include <stdio.h>
static void * loopWork(void * arg)
{
    pthread_t tid = pthread_self();
    ThreadPool_t * tp = (ThreadPool_t *)arg;
    while(true) {
        pthread_mutex_lock(&(tp->mutex));
        while(tp->terminate == false && tp->numTask == 0) {
            pthread_cond_wait(&(tp->cond), &(tp->mutex));
        }
        if (tp->terminate) {
            pthread_mutex_unlock(&(tp->mutex));
            break;
        }
        struct Task * firstTask = tp->taskhead->next;
        void * (*task_addr)(void *);
        task_addr = firstTask->job;
        void * task_arg = firstTask->args;
        tp->taskhead->next = firstTask->next;
        if (tp->tasktail == firstTask)
            tp->tasktail = tp->taskhead;
        free(firstTask);
        tp->numTask--;
        pthread_mutex_unlock(&(tp->mutex));
        task_addr(task_arg);
    }
    return NULL;
}

ThreadPool_t * create_threadpool(int thread_numer)
{
    if (thread_numer < 1) {
        return NULL;
    }
    ThreadPool_t * threadpool = (ThreadPool_t *)malloc(sizeof(ThreadPool_t));
    threadpool->terminate = false;
    pthread_cond_init(&(threadpool->cond), NULL);
    pthread_mutex_init(&(threadpool->mutex), NULL);
    threadpool->taskhead = (struct Task *)malloc(sizeof(struct Task));
    threadpool->taskhead->next = NULL;
    threadpool->tasktail = threadpool->taskhead;
    threadpool->numTask = 0;
    threadpool->numThread = thread_numer;
    threadpool->threads = (pthread_t *)malloc(thread_numer * sizeof(pthread_t));
    for (int i = 0; i < thread_numer; i++){
        pthread_create(&(threadpool->threads[i]), NULL, loopWork, threadpool);
    }
    return threadpool;
}

bool destroy_threadpool(ThreadPool_t * thread_pool)
{
    if (thread_pool == NULL) {
        return false;
    }
    while (true) {
        pthread_mutex_lock(&(thread_pool->mutex));
        if (thread_pool->numTask != 0) {
            pthread_mutex_unlock(&(thread_pool->mutex));
            continue;
        }
        else {
            thread_pool->terminate = true;
            pthread_mutex_unlock(&(thread_pool->mutex));
            pthread_cond_broadcast(&(thread_pool->cond));
            for (int i = 0; i < thread_pool->numThread; i++) {
                pthread_join(thread_pool->threads[i], NULL);
            }
            break;
        }
    }
    free(thread_pool->threads);
    free(thread_pool->taskhead);
    pthread_mutex_destroy(&(thread_pool->mutex));
    pthread_cond_destroy(&(thread_pool->cond));
    free(thread_pool);
    return true;
}

bool threadpool_add_job(ThreadPool_t * thread_pool, void * (*job_addr)(void *), void *args_addr)
{
    if (thread_pool == NULL || job_addr == NULL) {
        return false;
    }
    struct Task * newTask = (struct Task *)malloc(sizeof(struct Task));
    newTask->job = job_addr;
    newTask->args = args_addr;
    newTask->next = NULL;
    pthread_mutex_lock(&(thread_pool->mutex));
    thread_pool->tasktail->next = newTask;
    thread_pool->tasktail = newTask;
    thread_pool->numTask++;
    pthread_mutex_unlock(&(thread_pool->mutex));
    pthread_cond_signal(&(thread_pool->cond));
    return true;
}