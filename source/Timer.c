#include "Timer.h"
#include <stdlib.h>

Timer_t * create_timer()
{
    Timer_t * timer = (Timer_t *)malloc(sizeof(Timer_t));
    timer->elapsedTime = 0.0;
    timer->running = false;
    return timer;
}

bool destroy_timer(Timer_t * timer)
{
    if (timer == NULL)
        return false;
    free(timer);
    return true;
}

bool start_timer(Timer_t * timer)
{
    if(timer->running == true) 
        return false;
    gettimeofday(&(timer->lastTime), NULL);
    timer->running = true;
    return true;
}

bool stop_timer(Timer_t * timer)
{
    if (timer->running == false)
        return false;
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    time_t sec = currentTime.tv_sec - timer->lastTime.tv_sec;
    time_t us = currentTime.tv_usec - timer->lastTime.tv_usec;
    timer->elapsedTime += sec + us * 0.000001;
    timer->running = false;
    return true;
}

bool reset_timer(Timer_t * timer)
{
    timer->elapsedTime = 0.0;
    if(timer->running) {
        gettimeofday(&(timer->lastTime), NULL);
    }
    return true;
}

double get_time_of_timer_seconds(Timer_t * timer)
{
    return timer->elapsedTime;
}