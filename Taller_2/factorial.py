import threading
import time
import matplotlib.pyplot as plt

def factorial(n, priority):
    start_time = time.time()
    result = 1
    for i in range(1, n+1):
        result *= i
    end_time = time.time()
    elapsed_time = end_time - start_time
    print(f"Factorial de {n} calculado en {elapsed_time} segundos con prioridad {priority}")
    return elapsed_time

prioridades = [1, 2, 3, 4, 5]
tiempos = []

for p in prioridades:
    thread = threading.Thread(target=factorial, args=(335, p))
    thread.start()
    thread.join()
    tiempos.append(factorial(335, p))

plt.plot(prioridades, tiempos, marker='o')
plt.xlabel('Prioridad')
plt.ylabel('Tiempo (s)')
plt.title('Prioridad vs. Tiempo')
plt.show()
