cmake_minimum_required(VERSION 3.26)
project(Tare2_CE4303_SO C)

set(CMAKE_C_STANDARD 11)
set(PORT 5000)  # Cambiar por el puerto a utilizar
configure_file(
        ${CMAKE_SOURCE_DIR}/run.sh.in
        ${CMAKE_BINARY_DIR}/run.sh
)
add_executable(Tare2_CE4303_SO main.c client.c server.c)
