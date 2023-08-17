#include <stdio.h>
#include <time.h>

long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    printf("Ingrese un numero entero no negativo: ");
    scanf("%u", &num);
    clock_t start_time = clock();
    long long result = factorial(num);
    clock_t end_time = clock();
    
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    
    printf("El factorial de %u es %llu\n", num, result);
    printf("Tiempo de ejecucion: %f segundos\n", execution_time);
    
    return 0;
}
