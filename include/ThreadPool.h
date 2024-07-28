#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <stdbool.h>
#include <pthread.h>

struct Task {
    void * (*job) (void *);
    void * args;
    struct Task * next;
};

typedef struct {
    int numThread;
    pthread_t * threads;
    struct Task * taskhead;
    struct Task * tasktail;
    int numTask;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    bool terminate;
} ThreadPool_t;

ThreadPool_t * create_threadpool(int thread_numer);
bool destroy_threadpool(ThreadPool_t * thread_pool);
bool threadpool_add_job(ThreadPool_t * thread_pool, void * (*job_addr)(void *), void *args_addr);

#endif // THREAD_POOL_H  ThreadPool.h