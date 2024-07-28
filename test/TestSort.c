#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "Timer.h"
#include "Sort.h"

int N = 10000;

int cmp(const void * p1, const void * p2) {
    return *((int *)p1) - *((int *)p2);
}

bool check(int * a, int * b, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

void print(int * a, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    putchar('\n');
}

int main(int argc, char * argv[])
{
    if (argc > 1) {
        N = atoi(argv[1]);
    }
    int * a = (int *)malloc(N * sizeof(int));
    int * result = (int *)malloc(N * sizeof(int));
    int * myResult = (int *)malloc(N * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        a[i] = rand() % N;
    // print(a, N);
    memcpy(result, a, N * sizeof(int));
    qsort((void *)result, N, sizeof(int), cmp);
    
    Timer_t * timer = create_timer();

    // bubble sort
    memcpy(myResult, a, N * sizeof(int));
    start_timer(timer);
    bubble_sort_int(myResult, N);
    stop_timer(timer);
    double sec = get_time_of_timer_seconds(timer);
    reset_timer(timer);
    printf("Test Bubble Sort: %.2fms\n", sec * 1000.0);
    if (check(result, myResult, N)) 
        printf("\033[32mPass\033[0m\n");
    else
        printf("\033[31mFailed!\033[0m\n");

    // select sort
    memcpy(myResult, a, N * sizeof(int));
    start_timer(timer);
    select_sort_int(myResult, N);
    stop_timer(timer);
    sec = get_time_of_timer_seconds(timer);
    reset_timer(timer);
    printf("Test Select Sort: %.2fms\n", sec * 1000.0);
    if (check(result, myResult, N)) 
        printf("\033[32mPass\033[0m\n");
    else
        printf("\033[31mFailed!\033[0m\n");

    // insert sort
    memcpy(myResult, a, N * sizeof(int));
    start_timer(timer);
    insert_sort_int(myResult, N);
    stop_timer(timer);
    sec = get_time_of_timer_seconds(timer);
    reset_timer(timer);
    printf("Test Insert Sort: %.2fms\n", sec * 1000.0);
    if (check(result, myResult, N)) 
        printf("\033[32mPass\033[0m\n");
    else
        printf("\033[31mFailed!\033[0m\n");
    
    // merge sort
    memcpy(myResult, a, N * sizeof(int));
    start_timer(timer);
    merge_sort_int(myResult, N);
    stop_timer(timer);
    sec = get_time_of_timer_seconds(timer);
    reset_timer(timer);
    printf("Test Merge Sort: %.2fms\n", sec * 1000.0);
    if (check(result, myResult, N)) 
        printf("\033[32mPass\033[0m\n");
    else
        printf("\033[31mFailed!\033[0m\n");
    
    // quick sort
    memcpy(myResult, a, N * sizeof(int));
    start_timer(timer);
    quick_sort_int(myResult, N);
    stop_timer(timer);
    sec = get_time_of_timer_seconds(timer);
    reset_timer(timer);
    printf("Test Quick Sort: %.2fms\n", sec * 1000.0);
    if (check(result, myResult, N)) 
        printf("\033[32mPass\033[0m\n");
    else
        printf("\033[31mFailed!\033[0m\n");
    

    // print(myResult, N);
    free(a);
    free(result);
    free(myResult);
    destroy_timer(timer);
    return 0;
}