#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Sort.h"

bool bubble_sort_int(int * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    for (int i = 0; i < n - 1; i++) {
        bool all_sorted = true;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                all_sorted = false;
            }
        }
        if (all_sorted)
            break;
    }
    return true;
}

bool bubble_sort_float(float * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    for (int i = 0; i < n - 1; i++) {
        bool all_sorted = true;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j+1]) {
                float tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                all_sorted = false;
            }
        }
        if (all_sorted)
            break;
    }
    return true;
}

bool bubble_sort_double(double * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    for (int i = 0; i < n - 1; i++) {
        bool all_sorted = true;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j+1]) {
                double tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                all_sorted = false;
            }
        }
        if (all_sorted)
            break;
    }
    return true;
}

bool bubble_sort_longlong(long long * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    for (int i = 0; i < n - 1; i++) {
        bool all_sorted = true;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j+1]) {
                long long tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                all_sorted = false;
            }
        }
        if (all_sorted)
            break;
    }
    return true;
}

bool select_sort_int(int * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[k])
                k = j;
        }
        if (k != i) {
            int tmp = a[k];
            a[k] = a[i];
            a[i] = tmp;
        }
    }
    return true;
}

bool select_sort_float(float * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[k])
                k = j;
        }
        if (k != i) {
            float tmp = a[k];
            a[k] = a[i];
            a[i] = tmp;
        }
    }
    return true;
}

bool select_sort_double(double * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[k])
                k = j;
        }
        if (k != i) {
            double tmp = a[k];
            a[k] = a[i];
            a[i] = tmp;
        }
    }
    return true;
}

bool select_sort_longlong(long long * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[k])
                k = j;
        }
        if (k != i) {
            long long tmp = a[k];
            a[k] = a[i];
            a[i] = tmp;
        }
    }
    return true;
}

bool insert_sort_int(int * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    for (int i = 1; i < n; i++) {
        int temp = a[i];
        int j = i - 1;
        for ( ; j >= 0; j--) {
            if (a[j] > temp)
                a[j+1] = a[j];
            else
                break;
        }
        a[j+1] = temp;
    }
    return true;
}

bool insert_sort_float(float * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    for (int i = 1; i < n; i++) {
        float temp = a[i];
        int j = i - 1;
        for ( ; j >= 0; j--) {
            if (a[j] > temp)
                a[j+1] = a[j];
            else
                break;
        }
        a[j+1] = temp;
    }
    return true;
}

bool insert_sort_double(double * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    for (int i = 1; i < n; i++) {
        double temp = a[i];
        int j = i - 1;
        for ( ; j >= 0; j--) {
            if (a[j] > temp)
                a[j+1] = a[j];
            else
                break;
        }
        a[j+1] = temp;
    }
    return true;
}

bool insert_sort_longlong(long long * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    for (int i = 1; i < n; i++) {
        long long temp = a[i];
        int j = i - 1;
        for ( ; j >= 0; j--) {
            if (a[j] > temp)
                a[j+1] = a[j];
            else
                break;
        }
        a[j+1] = temp;
    }
    return true;
}

bool merge_sort_int(int * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    if (n == 1) {
        return true;
    }
    int ln = n / 2;
    int rn = n - ln;
    int * l = a;
    int * r = a + ln;
    merge_sort_int(l, ln);
    merge_sort_int(r, rn);
    int * buf = (int *)malloc(sizeof(int) * n);
    int i = 0, li = 0, ri = 0;
    while(li < ln && ri < rn) {
        if (l[li] < r[ri]) {
            buf[i] = l[li];
            li++;
        }
        else {
            buf[i] = r[ri];
            ri++;
        }
        i++;
    }
    while (li < ln) {
        buf[i] = l[li];
        i++;
        li++;
    }
    while(ri < rn) {
        buf[i] = r[ri];
        i++;
        ri++;
    }
    memcpy(a, buf, n * sizeof(int));
    free(buf);
    return true;
}

bool merge_sort_float(float * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    if (n == 1) {
        return true;
    }
    int ln = n / 2;
    int rn = n - ln;
    float * l = a;
    float * r = a + ln;
    merge_sort_float(l, ln);
    merge_sort_float(r, rn);
    float * buf = (float *)malloc(sizeof(float) * n);
    int i = 0, li = 0, ri = 0;
    while(li < ln && ri < rn) {
        if (l[li] < r[ri]) {
            buf[i] = l[li];
            li++;
        }
        else {
            buf[i] = r[ri];
            ri++;
        }
        i++;
    }
    while (li < ln) {
        buf[i] = l[li];
        i++;
        li++;
    }
    while(ri < rn) {
        buf[i] = r[ri];
        i++;
        ri++;
    }
    memcpy(a, buf, n * sizeof(float));
    free(buf);
    return true;
}

bool merge_sort_double(double * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    if (n == 1) {
        return true;
    }
    int ln = n / 2;
    int rn = n - ln;
    double * l = a;
    double * r = a + ln;
    merge_sort_double(l, ln);
    merge_sort_double(r, rn);
    double * buf = (double *)malloc(sizeof(double) * n);
    int i = 0, li = 0, ri = 0;
    while(li < ln && ri < rn) {
        if (l[li] < r[ri]) {
            buf[i] = l[li];
            li++;
        }
        else {
            buf[i] = r[ri];
            ri++;
        }
        i++;
    }
    while (li < ln) {
        buf[i] = l[li];
        i++;
        li++;
    }
    while(ri < rn) {
        buf[i] = r[ri];
        i++;
        ri++;
    }
    memcpy(a, buf, n * sizeof(double));
    free(buf);
    return true;
}

bool merge_sort_longlong(long long * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    if (n == 1) {
        return true;
    }
    int ln = n / 2;
    int rn = n - ln;
    long long * l = a;
    long long * r = a + ln;
    merge_sort_longlong(l, ln);
    merge_sort_longlong(r, rn);
    long long * buf = (long long *)malloc(sizeof(long long) * n);
    int i = 0, li = 0, ri = 0;
    while(li < ln && ri < rn) {
        if (l[li] < r[ri]) {
            buf[i] = l[li];
            li++;
        }
        else {
            buf[i] = r[ri];
            ri++;
        }
        i++;
    }
    while (li < ln) {
        buf[i] = l[li];
        i++;
        li++;
    }
    while(ri < rn) {
        buf[i] = r[ri];
        i++;
        ri++;
    }
    memcpy(a, buf, n * sizeof(long long));
    free(buf);
    return true;
}

bool quick_sort_int(int * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    if (n == 1) {
        return true;
    }
    srand(time(NULL));
    int idx = rand() % n;
    int tmp = a[0];
    a[0] = a[idx];
    a[idx] = tmp;
    int l = 0, r = n - 1;
    while (l < r) {
        while (r > l && a[r] >= a[l])
            r--;
        if (r <= l)
            break;
        tmp = a[r];
        a[r] = a[l];
        a[l] = tmp;
        while (l < r && a[l] <= a[r])
            l++;
        if (l >= r)
            break;
        tmp = a[r];
        a[r] = a[l];
        a[l] = tmp;
    }
    int mid = l;
    quick_sort_int(a, mid);
    quick_sort_int(a + mid + 1, n - mid - 1);
}

bool quick_sort_float(float * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    if (n == 1) {
        return true;
    }
    srand(time(NULL));
    int idx = rand() % n;
    float tmp = a[0];
    a[0] = a[idx];
    a[idx] = tmp;
    int l = 0, r = n - 1;
    while (l < r) {
        while (r > l && a[r] >= a[l])
            r--;
        if (r <= l)
            break;
        tmp = a[r];
        a[r] = a[l];
        a[l] = tmp;
        while (l < r && a[l] <= a[r])
            l++;
        if (l >= r)
            break;
        tmp = a[r];
        a[r] = a[l];
        a[l] = tmp;
    }
    int mid = l;
    quick_sort_float(a, mid);
    quick_sort_float(a + mid + 1, n - mid - 1);
}

bool quick_sort_double(double * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    if (n == 1) {
        return true;
    }
    srand(time(NULL));
    int idx = rand() % n;
    double tmp = a[0];
    a[0] = a[idx];
    a[idx] = tmp;
    int l = 0, r = n - 1;
    while (l < r) {
        while (r > l && a[r] >= a[l])
            r--;
        if (r <= l)
            break;
        tmp = a[r];
        a[r] = a[l];
        a[l] = tmp;
        while (l < r && a[l] <= a[r])
            l++;
        if (l >= r)
            break;
        tmp = a[r];
        a[r] = a[l];
        a[l] = tmp;
    }
    int mid = l;
    quick_sort_double(a, mid);
    quick_sort_double(a + mid + 1, n - mid - 1);
}

bool quick_sort_longlong(long long * a, size_t n)
{
    if (a == NULL || n < 1) {
        return false;
    }
    if (n == 1) {
        return true;
    }
    srand(time(NULL));
    int idx = rand() % n;
    long long tmp = a[0];
    a[0] = a[idx];
    a[idx] = tmp;
    int l = 0, r = n - 1;
    while (l < r) {
        while (r > l && a[r] >= a[l])
            r--;
        if (r <= l)
            break;
        tmp = a[r];
        a[r] = a[l];
        a[l] = tmp;
        while (l < r && a[l] <= a[r])
            l++;
        if (l >= r)
            break;
        tmp = a[r];
        a[r] = a[l];
        a[l] = tmp;
    }
    int mid = l;
    quick_sort_longlong(a, mid);
    quick_sort_longlong(a + mid + 1, n - mid - 1);
}