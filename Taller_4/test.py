import threading
from PIL import Image, ImageOps
from sklearn.datasets import fetch_openml
import numpy as np

class ImagenFiltrada:
    def __init__(self, nombre: str, data: np.ndarray):
        self.nombre = nombre
        # Convertir el vector de 784 elementos a una matriz 28x28
        self.imagen = Image.fromarray((data.values.reshape(28, 28) * 255).astype(np.uint8))

    def aplicar_filtro_gris(self):
        """Aplica un filtro de escala de grises a la imagen."""
        self.imagen = ImageOps.grayscale(self.imagen)

    def guardar_imagen(self, ruta_salida: str):
        """Guarda la imagen en la ruta especificada."""
        self.imagen.save(ruta_salida)

def procesar_imagenes(inicio, fin, data):
    for i in range(inicio, fin):
        imagen = ImagenFiltrada(f"mnist_{i}", data.iloc[i])
        imagen.aplicar_filtro_gris()
        imagen.guardar_imagen(f"mnist_{i}.png")

# Cargar el conjunto de datos mnist_784
mnist = fetch_openml('mnist_784', version=1, parser='auto')

# Dividir el trabajo entre 10 hilos
num_hilos = 10
hilos = []
num_imagenes = len(mnist.data)
imagenes_por_hilo = num_imagenes // num_hilos

for i in range(num_hilos):
    inicio = i * imagenes_por_hilo
    fin = (i + 1) * imagenes_por_hilo if i != num_hilos - 1 else num_imagenes
    hilo = threading.Thread(target=procesar_imagenes, args=(inicio, fin, mnist.data))
    hilo.start()
    hilos.append(hilo)

# Esperar a que todos los hilos terminen
for hilo in hilos:
    hilo.join()

print("Procesamiento completado.")

