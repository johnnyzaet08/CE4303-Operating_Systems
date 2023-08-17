import time

def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n - 1)

num = int(input("Ingrese un número entero no negativo: "))

start_time = time.time()
result = factorial(num)
end_time = time.time()

execution_time = end_time - start_time

print(f"El factorial de {num} es {result}")
print(f"Tiempo de ejecución: {execution_time} segundos")