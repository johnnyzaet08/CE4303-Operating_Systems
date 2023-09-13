#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 5

char archivo[100];
char palabra[100];
char linea[1000];
int contador = 0;
FILE *archivo_txt;

// Estructura para pasar argumentos al hilo
typedef struct {
    int inicio;
    int fin;
} ThreadArgs;

void *buscarPalabra(void *arg) {
    ThreadArgs *args = (ThreadArgs *)arg;

    for (int i = args->inicio; i < args->fin; i++) {
        char *token = strtok(linea + i, " \t\n");

        while (token != NULL) {
            if (strcmp(token, palabra) == 0) {
                contador++;
            }
            token = strtok(NULL, " \t\n");
        }
    }

    return NULL;
}

int main() {
    printf("Ingrese el nombre del archivo (.txt): ");
    scanf("%s", archivo);

    printf("Ingrese la palabra que desea contar: ");
    scanf("%s", palabra);

    archivo_txt = fopen(archivo, "r");

    if (archivo_txt == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    fgets(linea, sizeof(linea), archivo_txt);  // Leer una línea para obtener el tamaño del archivo
    int tamano_archivo = strlen(linea);
    rewind(archivo_txt);

    pthread_t threads[MAX_THREADS];
    ThreadArgs thread_args[MAX_THREADS];
    int num_hilos[] = {2, 3, 4, 5};  // Número de hilos

    // Tomar el tiempo de inicio
    clock_t inicio = clock();

    for (int i = 0; i < sizeof(num_hilos) / sizeof(num_hilos[0]); i++) {
        int hilos = num_hilos[i];
        int tamano_seccion = tamano_archivo / hilos;

        for (int j = 0; j < hilos; j++) {
            int inicio = j * tamano_seccion;
            int fin = (j == hilos - 1) ? tamano_archivo : (j + 1) * tamano_seccion;

            thread_args[j].inicio = inicio;
            thread_args[j].fin = fin;

            pthread_create(&threads[j], NULL, buscarPalabra, &thread_args[j]);
        }

        for (int j = 0; j < hilos; j++) {
            pthread_join(threads[j], NULL);
        }

        printf("Con %d hilos, la palabra '%s' aparece %d veces.\n", hilos, palabra, contador);
    }

    // Tomar el tiempo de finalización
    clock_t fin = clock();
    double tiempo = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecución total: %f segundos\n", tiempo);

    fclose(archivo_txt);

    return 0;
}
