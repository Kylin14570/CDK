#ifndef LOCK_H
#define LOCK_H

#include <stdbool.h>
#include <pthread.h>

typedef pthread_mutex_t Lock_t;

Lock_t * create_lock();
bool destroy_lock(Lock_t * lock);
bool obtain_lock(Lock_t * lock);
bool release_lock(Lock_t * lock);

#endif // LOCK_H Lock.h