#include <stdio.h>
#include <gmp.h>

int main() {
    int num;

    printf("Ingrese un número entero no negativo: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Por favor, ingrese un número no negativo.\n");
    } else {
        mpz_t result;
        mpz_init(result);

        mpz_set_ui(result, 1);

        for (int i = 1; i <= num; i++) {
            mpz_mul_ui(result, result, i);
        }

        gmp_printf("El factorial de %d es %Zd\n", num, result);

        mpz_clear(result);
    }

    return 0;
}

