//
// Created by benam on 27/11/2024.
//
// File: lab4/race.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 20

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

long accum = 0;

void *square(void *param) {
    int x = *(int *)param;
    pthread_mutex_lock(&mutex);
    accum += x * x;
    pthread_mutex_unlock(&mutex);
    //sleep(1);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int *params[NUM_THREADS];

    for (long t = 0; t < NUM_THREADS; t++) {
        params[t] = malloc(sizeof(int));
        *params[t] = t + 1;
        pthread_create(&threads[t], NULL, square, (void *)params[t]);
    }

    for (long t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
        free(params[t]);
    }

    printf("%ld\n", accum);
    pthread_exit(NULL);
}