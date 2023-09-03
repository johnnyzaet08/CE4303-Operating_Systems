# Usa la imagen base de CentOS
FROM centos:latest
RUN cd /etc/yum.repos.d/
RUN sed -i 's/mirrorlist/#mirrorlist/g' /etc/yum.repos.d/CentOS-*
RUN sed -i 's|#baseurl=http://mirror.centos.org|baseurl=http://vault.centos.org|g' /etc/yum.repos.d/CentOS-*

# Actualiza el sistema y instala las dependencias necesarias
RUN yum -y update && yum -y install gcc

# Copia el código fuente del cliente al contenedor
COPY client.c /client.c

# Compila el cliente
RUN gcc -Wall -o /client /client.c -pthread

# Establece el directorio de trabajo
WORKDIR /

# Comando por defecto para ejecutar el cliente
CMD ["/client"]
