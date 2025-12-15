#include <stdio.h>
#include <pthread.h>


int g_value = 0;
int N = 100000; 


void* worker(void* arg) {
    
    for(int i = 0 ; i < N; i++)
        g_value++;
    return NULL;
}

int main() {
    pthread_t threads[2]  = {0};


    
    pthread_create(&threads[0], NULL, worker, NULL);
    pthread_create(&threads[1], NULL, worker, NULL);

    
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    
    printf("Final value: %d (Expected at least: %d)\n", g_value, N);

    return 0;
}