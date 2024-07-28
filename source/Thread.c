#include "Thread.h"
#include <stdlib.h>

Thread_t * create_thread()
{
    Thread_t * new_thread = (Thread_t *)malloc(sizeof(Thread_t));
    new_thread->tid = 0;
    new_thread->startRoutine = NULL;
    new_thread->ptrArgs = NULL;
    new_thread->running = false;
    return new_thread;
}

bool destroy_thread(Thread_t * arg_thread)
{
    if (arg_thread == NULL)
        return false;
    if (arg_thread->running)
        thread_cancel_job(arg_thread);
    free(arg_thread);
    return false;
}

bool thread_assign_job(Thread_t * arg_thread, void * (*job) (void *), void * args)
{
    if (arg_thread->running)
        return false;
    arg_thread->startRoutine = job;
    arg_thread->ptrArgs = args;
    return true;
}

bool thread_start_job(Thread_t * arg_thread)
{
    if (arg_thread->running || arg_thread->startRoutine == NULL)
        return false;
    pthread_create(
        &(arg_thread->tid),
        NULL,
        arg_thread->startRoutine,
        arg_thread->ptrArgs
    );
    arg_thread->running = true;
}

bool thread_finish_job(Thread_t * arg_thread)
{
    pthread_join(arg_thread->tid, NULL);
    arg_thread->tid = 0;
    arg_thread->running = false;
}

bool thread_cancel_job(Thread_t * arg_thread)
{
    if (arg_thread->running) {
        pthread_cancel(arg_thread->tid);
        arg_thread->tid = 0;
        arg_thread->running = false;
    }
    arg_thread->startRoutine = NULL;
    arg_thread->ptrArgs = NULL;
    return true;
}