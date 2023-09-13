def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

# Solicitar al usuario un número entero no negativo
try:
    num = int(input("Ingrese un número entero no negativo: "))
    if num < 0:
        print("Por favor, ingrese un número no negativo.")
    else:
        resultado = factorial(num)
        print(f"El factorial de {num} es {resultado}")
except ValueError:
    print("Por favor, ingrese un número entero válido.")
