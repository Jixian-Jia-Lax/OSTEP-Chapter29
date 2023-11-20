#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>

// Thread function
void* threadFunction(void* arg) {
    // Put your concurrent code here
    return NULL;
}

int main() {
    struct timeval start, end;
    long seconds, useconds;    
    int num_threads = 5; // Number of threads

    // Get start time
    gettimeofday(&start, NULL);

    // Create and run threads
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; ++i) {
        pthread_create(&threads[i], NULL, threadFunction, NULL);
    }

    // Join threads
    for (int i = 0; i < num_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    // Get end time
    gettimeofday(&end, NULL);

    // Calculate elapsed time
    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    double elapsed = ((seconds) + useconds/1e6);

    printf("Elapsed time: %f seconds\n", elapsed);

    return 0;
}
