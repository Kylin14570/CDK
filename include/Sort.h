#ifndef SORT_H
#define SORT_H

#include <stdbool.h>

bool bubble_sort_int(int * a, size_t n);
bool select_sort_int(int * a, size_t n);
bool insert_sort_int(int * a, size_t n);
bool merge_sort_int(int * a, size_t n);
bool quick_sort_int(int * a, size_t n);

bool bubble_sort_float(float * a, size_t n);
bool select_sort_float(float * a, size_t n);
bool insert_sort_float(float * a, size_t n);
bool merge_sort_float(float * a, size_t n);
bool quick_sort_float(float * a, size_t n);

bool bubble_sort_double(double * a, size_t n);
bool select_sort_double(double * a, size_t n);
bool insert_sort_double(double * a, size_t n);
bool merge_sort_double(double * a, size_t n);
bool quick_sort_double(double * a, size_t n);

bool bubble_sort_longlong(long long * a, size_t n);
bool select_sort_longlong(long long * a, size_t n);
bool insert_sort_longlong(long long * a, size_t n);
bool merge_sort_longlong(long long * a, size_t n);
bool quick_sort_longlong(long long * a, size_t n);

#endif // SORT_H  Sort.h