#ifndef TIMER_H
#define TIMER_H

#include <stdbool.h>
#include <sys/time.h>

typedef struct {
    struct timeval lastTime;
    double elapsedTime;
    bool running;
} Timer_t;

Timer_t * create_timer();
bool destroy_timer(Timer_t * timer);
bool start_timer(Timer_t * timer);
bool stop_timer(Timer_t * timer);
bool reset_timer(Timer_t * timer);
double get_time_of_timer_seconds(Timer_t * timer);

#endif // TIMER_H  Timer.h