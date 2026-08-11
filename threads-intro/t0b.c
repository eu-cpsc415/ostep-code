#include "../include/common_threads.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* mythread(void* arg)
{
    printf("%s\n", (char*)arg);

    for (int i = 0; i < 100; i++) {
        printf("%s: %d\n", (char*)arg, i);
    }

    return NULL;
}

int main(int argc, char* argv[])
{
    if (argc != 1) {
        fprintf(stderr, "usage: main\n");
        exit(1);
    }

    pthread_t p1, p2;
    printf("main: begin\n");
    Pthread_create(&p1, NULL, mythread, "A");
    Pthread_create(&p2, NULL, mythread, "B");
    // join waits for the threads to finish
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    printf("main: end\n");
    return 0;
}
