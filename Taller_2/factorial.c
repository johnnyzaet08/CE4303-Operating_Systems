#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define NUM_THREADS 5

// Estructura para pasar argumentos al hilo
typedef struct {
    int n;
    int priority;
    double elapsed_time;
} ThreadArgs;

// Función factorial
void *factorial(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg;
    struct timeval start, end;

    gettimeofday(&start, NULL);

    int result = 1;
    for (int i = 1; i <= args->n; i++) {
        result *= i;
    }

    gettimeofday(&end, NULL);
    args->elapsed_time = (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000;

    printf("Factorial de %d calculado en %f segundos con prioridad %d\n", args->n, args->elapsed_time, args->priority);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadArgs thread_args[NUM_THREADS];
    int priorities[NUM_THREADS] = {1, 2, 3, 4, 5};

    // Crear y ejecutar los hilos
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_args[i].n = 335;
        thread_args[i].priority = priorities[i];
        pthread_create(&threads[i], NULL, factorial, &thread_args[i]);
        pthread_join(threads[i], NULL);
    }

    // Agregar una instrucción de salida
    char respuesta;
    printf("El programa ha terminado. ¿Desea salir? (y/n): ");
    scanf(" %c", &respuesta);

    if (respuesta == 'y' || respuesta == 'Y') {
        return 0; // Salir del programa
    }

    return 0;
}
