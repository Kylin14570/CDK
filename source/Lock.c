#include "Lock.h"
#include <stdlib.h>

Lock_t * create_lock()
{
    Lock_t * lock = (Lock_t *)malloc(sizeof(Lock_t));
    pthread_mutex_init(lock, NULL);
    return lock;
}

bool destroy_lock(Lock_t * lock)
{
    if (lock == NULL)
        return false;
    pthread_mutex_destroy(lock);
    free(lock);
    return true;
}

bool obtain_lock(Lock_t * lock)
{
    pthread_mutex_lock(lock);
    return true;
}

bool release_lock(Lock_t * lock)
{
    pthread_mutex_unlock(lock);
    return true;
}