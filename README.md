
# Instrucciones para ejecutar
## Requisitos

Compilador de C++ compatible con C++17 o superior (por ejemplo, g++, MinGW, o Visual Studio Code con extensión C++).

Sistema operativo: Windows (por el uso de windows.h para UTF-8 en consola).

## Compilar y ejecutar programas principales

Todos los algoritmos principales están en la carpeta src y pueden ejecutarse de forma independiente.

Abrir la terminal en la carpeta raíz del proyecto.

### Compilar el archivo deseado. Por ejemplo, para el grafo con DFS/BFS:

g++ src/Grafos.cpp -o Grafos.exe


### Ejecutar el programa:

./Grafos.exe   # En Windows también puede ser Grafos.exe


Seguir el menú interactivo para crear grafos, mostrar representaciones y realizar DFS o BFS.

Nota: Los nodos se ingresan de 1 a n. Los recorridos DFS y BFS se ejecutan sobre la lista de adyacencia por defecto.

## Ejecutar pruebas automáticas

Todos los tests se encuentran en la carpeta tests. Cada test puede ejecutarse individualmente.

Compilar el test correspondiente. Por ejemplo, para Componentes Conexas:

g++ tests/test_componentes_conexas.cpp -o TestComponentes.exe


### Ejecutar:

./TestComponentes.exe


El programa mostrará resultados automáticos indicando si el test finalizó con éxito.

Cada test verifica diferentes aspectos de los algoritmos: conectividad, recorridos, ciclos, etc.

## Kruskal (MST y MaxST)

Los archivos de Kruskal requieren la librería KruskalLib.h incluida en src.

### Compilar el archivo principal de Kruskal:

g++ src/Kruskal.cpp -o Kruskal.exe


### Ejecutar:

./Kruskal.exe


Para correr las pruebas automáticas de Kruskal, modificar la ruta de la librería si es necesario, o compilar directamente con la ruta absoluta:

g++ tests/test_kruskal.cpp -o TestKruskal.exe
./TestKruskal.exe


Esto permitirá verificar MST y MaxST en varios grafos de prueba.

## Recomendaciones

Para Windows, asegúrate de tener MinGW instalado y agregado a la variable de entorno PATH.

Para Visual Studio Code, abre la terminal integrada en la carpeta raíz y usa los comandos anteriores.

Ejecuta primero los programas principales (src) antes de los tests si quieres ingresar tus propios grafos.