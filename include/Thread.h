#ifndef THREAD_H
#define THREAD_H

#include <stdbool.h>
#include <pthread.h>

typedef struct {
    pthread_t tid;
    void * (*startRoutine) (void *);
    void * ptrArgs;
    bool running;
} Thread_t;

Thread_t * create_thread();
bool destroy_thread(Thread_t * thread);
bool thread_assign_job(Thread_t * arg_thread, void * (*job) (void *), void * args);
bool thread_start_job(Thread_t * arg_thread);
bool thread_finish_job(Thread_t * arg_thread);
bool thread_cancel_job(Thread_t * arg_thread);

#endif // THREAD_H  Thread.h