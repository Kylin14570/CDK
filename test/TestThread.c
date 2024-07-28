#include <stdio.h>
#include <stdlib.h>
#include "Thread.h"
#include "Lock.h"
#include "Timer.h"

#define N    10000000
#define MAXT 1024
int a = 0;
Lock_t * lock = NULL;
int T = 4;
Thread_t threads[MAXT];

void * job(void * args)
{
    for (int i = 0; i < N / T; i++) {
        obtain_lock(lock);
        a++;
        release_lock(lock);
    }
    return NULL;
}

int main(int argc, char * argv[])
{
    if (argc > 1) {
        T = atoi(argv[1]);
        if (T > MAXT)
            T = MAXT;
    }
    Timer_t * timer = create_timer();
    start_timer(timer);
    lock = create_lock();
    Thread_t * threads[T];
    for (int i = 0; i < T; i++){
        threads[i] = create_thread();
        thread_assign_job(threads[i], job, NULL);
    }
    for(int i = 0; i < T; i++) {
        thread_start_job(threads[i]);
    }
    for(int i = 0; i < T; i++) {
        thread_finish_job(threads[i]);
    }
    stop_timer(timer);
    double sec = get_time_of_timer_seconds(timer);
    printf("Test Thread: %.2fms\n", sec * 1000.0);
    if (a == (N / T) * T)
        printf("\033[32mPass\033[0m\n");
    else
        printf("\033[31mFailed!\033[0m\n");
}