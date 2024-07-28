#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ThreadPool.h"
#include "Lock.h"
#include "Timer.h"
#define N 10000
int T = 4;
int a = 0;
int b = 0;
int c = 0;
Lock_t * locka;
Lock_t * lockb;
Lock_t * lockc;
void * add_a(void * arg) {
    obtain_lock(locka);
    a++;
    release_lock(locka);
    return NULL;
}
void * add_b(void * arg) {
    obtain_lock(lockb);
    b++;
    release_lock(lockb);
    return NULL;
}
void * add_c(void * arg) {
    obtain_lock(lockc);
    c++;
    release_lock(lockc);
    return NULL;
}
int main(int argc, char * argv[])
{
    if (argc > 1) {
        T = atoi(argv[1]);
    }
    locka = create_lock();
    lockb = create_lock();
    lockc = create_lock();
    Timer_t * timer = create_timer();
    start_timer(timer);
    ThreadPool_t * tp  =create_threadpool(T);
    for (int i = 0; i < N; i++) {
        threadpool_add_job(tp, add_a, NULL);
        threadpool_add_job(tp, add_c, NULL);
        threadpool_add_job(tp, add_b, NULL);
    }
    for (int i = 0; i < N; i++) {
        threadpool_add_job(tp, add_c, NULL);
        threadpool_add_job(tp, add_a, NULL);
        threadpool_add_job(tp, add_b, NULL);
    }
    for (int i = 0; i < N; i++) {
        threadpool_add_job(tp, add_b, NULL);
        threadpool_add_job(tp, add_a, NULL);
        threadpool_add_job(tp, add_c, NULL);
    }
    destroy_threadpool(tp);
    stop_timer(timer);
    double sec = get_time_of_timer_seconds(timer);
    printf("Test Thread Pool: %.2fms\n", sec * 1000.0);
    if (a == 3*N && b == 3*N) 
        printf("\033[32mPass\033[0m\n");
    else
        printf("\033[31mFailed!\033[0m\n");
    destroy_lock(locka);
    destroy_lock(lockb);
    destroy_lock(lockc);
    destroy_timer(timer);
    return 0;
}