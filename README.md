# Grafos — Representaciones y recorridos

## a Representaciones de grafos

### Matriz de adyacencia
Es una matriz de tamaño nxn que nos indica si existe un arco entre dos nodos.  
Ventajas: búsqueda O(1).  
Desventajas: mucho espacio para grafos dispersos.  

### Lista de adyacencia
Cada nodo tiene una lista de vecinos.  
Ventajas: eficiente en espacio O(V+E), ideal para DFS/BFS.  
Desventajas: preguntar si existe un arco específico no es O(1).  

### Lista de arcos (Edge List)
Se enumeran todas las aristas.  
Ventajas: fácil de leer y almacenar.  
Desventajas: no eficiente para recorridos.  

### Matriz de incidencia
Matriz V×E donde filas=vertices, columnas=aristas.  
- -1 en origen  
- +1 en destino  
Ventajas: útil en flujos y ciclos.  
Desventajas: mucho espacio O(VE).  

### Diccionario / Hash Map
Similar a la lista de adyacencia, pero dinámica y flexible.

---

## b Representaciones de Grafos y Recorridos (DFS y BFS)

### ¿Cómo funciona?


Este programa implementa los algoritmos de recorrido en profundidad (DFS) y recorrido en anchura (BFS) para explorar los nodos de un grafo.

### El programa (src/Grafos.cpp) permite:

Crear un grafo indicando número de nodos y aristas.

Ingresar aristas manualmente (con nodos de inicio y fin).

Mostrar el grafo usando diferentes representaciones: lista de adyacencia, matriz de adyacencia, matriz de incidencia, lista de arcos o diccionario.

Recorrer el grafo usando DFS o BFS desde cualquier nodo de inicio.

Identificar nodos conectados o componentes exploradas mediante los recorridos.

### ¿Qué tipo de grafos soporta?

Dirigidos: el programa puede representar grafos dirigidos si se ajusta la entrada de aristas (actualmente la implementación agrega la arista en ambos sentidos por defecto para no dirigidos).

No dirigidos: totalmente soportados por defecto.

Ponderados: no necesario; los recorridos se basan únicamente en la conectividad.

No ponderados: soportados de manera natural.

#### Limitaciones importantes:

Los recorridos DFS y BFS solo exploran nodos alcanzables desde el nodo de inicio.

Para grafos desconectados, algunos nodos pueden permanecer sin visitar si no se ejecuta el recorrido desde cada componente.

La matriz de incidencia y diccionario se manejan como herramientas de visualización; no se usan directamente para los recorridos.

### Pruebas

En /tests se incluyen tres pruebas automáticas:

#### Test 1 — Lista de adyacencia

Crea un grafo simple de 3 nodos y verifica que un DFS recorra todos los nodos conectados.

#### Test 2 — Matriz de adyacencia

Crea un grafo con ciclo de 4 nodos y verifica que un BFS recorra correctamente todos los nodos conectados.

#### Test 3 — Matriz de incidencia

Crea un grafo con un nodo desconectado y confirma que el DFS detecte nodos no conectados al inicio del recorrido.
 
---

## c Componentes Conexas

El programa (`src/ComponentesConexas.cpp`) permite:

- Elegir si el grafo es dirigido o no dirigido
- Elegir si es ponderado (el peso no afecta las componentes)
- Ingresar las aristas
- Mostrar:
  - Componentes Conexas (si es grafo no dirigido)
  - Componentes Fuertemente Conexas por Kosaraju (si es dirigido)

---

###  Pruebas

En `/tests/test_componentes_conexas.cpp` se incluyen **tres pruebas automáticas**:

#### Test 1 — Componentes Conexas  
Comprueba que en un grafo no dirigido se detecten exactamente 2 componentes.

#### Test 2 — Grafo Invertido  
Valida que el grafo inverso (`adj_rev`) se construya correctamente.

#### Test 3 — Kosaraju para SCC  
Evalúa un grafo dirigido con dos ciclos para confirmar que el algoritmo detecta 2 SCC.

---

## d Floyd–Warshall — Caminos más cortos entre todos los pares

### ¿Cómo funciona?:

Actualiza iterativamente la matriz de distancias probando si un camino i -> k -> j es mejor que el actual i -> j

### El programa (src/FloydWarshall.cpp) permite:

-Elegir si el grafo es dirigido o no dirigido
-Trabajar con grafos ponderados con pesos positivos, cero o negativos
-Ingresar las distancias manualmente
-Obtener la matriz completa de distancias más cortas entre cada par de nodos

### ¿Qué tipo de grafos soporta?

Dirigidos: totalmente soportados

No dirigidos: totalmente soportados

Ponderados: permitido (los pesos pueden ser positivos, cero o negativos)

No ponderados: también funciona usando 1 como peso de cada arista

#### Limitación importante:
El algoritmo no puede detectar ciclos negativos y no funciona correctamente si existen.
Floyd–Warshall asume que las distancias disminuyen de manera controlada; un ciclo negativo produciría mejoras infinitas.

### ¿Por qué se eligió Floyd–Warshall?

Resuelve el problema de caminos más cortos entre todos los pares de nodos.
Es fácil de implementar y entender en comparación con alternativas más complejas.
Produce una matriz completa de distancias, útil para análisis posteriores.
Útil cuando el grafo es denso o el número de nodos es moderado.

### Pruebas

En /tests/test_floyd_warshall.cpp se incluyen tres pruebas automáticas:

#### Test 1 — Grafo no dirigido

Comprueba que el algoritmo produzca las distancias correctas en un grafo simple.

#### Test 2 — Grafo dirigido

Valida que el programa funcione correctamente cuando las direcciones afectan los caminos.

#### Test 3 — Pesos negativos (sin ciclos negativos)

Verifica que Floyd–Warshall maneje correctamente pesos negativos siempre que no haya ciclos negativos.

---

## e Verificar si un grafo es un árbol

Este proyecto implementa un algoritmo sencillo para determinar si un **grafo no dirigido** es un **árbol**.

### ¿Qué condiciones debe cumplir un árbol?

Un grafo es un árbol si y solo si cumple:

1. Está **conectado**
2. No tiene **ciclos**
3. Tiene exactamente **n − 1** aristas

El programa verifica estas tres condiciones usando DFS.

---

### ¿Por qué **NO** puede ser un grafo dirigido?

Porque el concepto formal de **árbol** solo existe para grafos **no dirigidos**.

- En grafos dirigidos, la conectividad se divide en *conectado*, *fuertemente conectado* y *débilmente conectado*.
- Un árbol **siempre** es una estructura en la que las aristas **no tienen dirección**.

Si el grafo fuera dirigido, habría que usar definiciones distintas como:
- *arborescencia*
- *arborescencia enraizada*
- *directed spanning tree*

Esos conceptos se consideran aparte y **no equivalen a un árbol tradicional**.

Por eso, este programa funciona únicamente para **grafos no dirigidos**, que es la definición clásica usada en teoría de grafos.

---

## f Árbol de expansión mínima/máxima — Kruskal

### ¿Cómo funciona?

El algoritmo construye un árbol de expansión mínima (MST) o máxima (MaxST) usando Kruskal:
- Ordena todas las aristas por peso
- Agrega cada arista al árbol si no genera ciclo
- Usa unión de conjuntos (Union-Find simple) sin optimización avanzada

### El programa (src/Kruskal.cpp) permite:

- Elegir nodos y aristas
- Calcular MST y MaxST
- Mostrar aristas seleccionadas y peso total

### ¿Qué tipo de grafos soporta?

- Dirigidos: no aplica, Kruskal se usa solo para no dirigidos
- No dirigidos: totalmente soportados
- Ponderados: obligatorio para calcular peso
- No ponderados: no tiene sentido, peso se ignora

### Importante

- Nodos ingresados del 1 a n para facilidad de usuario
- Validación de índices y formato de entrada
- MaxST se obtiene invirtiendo orden de pesos
- MST y MaxST funcionan independientemente de la densidad del grafo

### Pruebas

En /tests/test_kruskal.cpp se incluyen tres pruebas:

#### Test 1 — Grafo de 4 nodos

Verifica MST y MaxST

#### Test 2 — Grafo de 5 nodos

Verifica MST y MaxST con aristas más complejas

#### Test 3 — Grafo de 3 nodos

Comprueba casos con aristas grandes y MST vs MaxST

---

## g Bicoloración — Verificación de grafo bipartito con BFS

### ¿Cómo funciona?

El algoritmo usa BFS para intentar asignar colores 1 y –1.
Si algún nodo intenta recibir el mismo color que su vecino, existe un ciclo impar y el grafo no es bipartito.

### El programa (src/Bipartito.cpp) permite:

Elegir si el grafo es dirigido o no dirigido

Ingresar nodos y aristas manualmente

Detectar si el grafo es bipartito

Mostrar los dos conjuntos bipartitos

Procesar grafos con múltiples componentes

### ¿Qué tipo de grafos soporta?

Dirigidos: permitido, pero no tiene utilidad práctica para bipartición (explicado abajo)
No dirigidos: totalmente soportados
Ponderados: no importa, la bipartición solo depende de la estructura
No ponderados: igualmente válido

#### Importante:

La bipartición solo tiene sentido en grafos NO dirigidos.
Si el usuario elige “dirigido”, el programa funciona técnicamente, pero se aclara que no es una aplicación realista de bipartición.

### ¿Por qué se eligió BFS?

Rápido y simple de implementar

Funciona perfectamente para detectar ciclos impares

Más intuitivo para estudiantes que DFS recursivo

Permite procesar componentes desconectadas sin problemas


### Pruebas

En /tests/test_bipartito.cpp se incluyen tres pruebas:

#### Test 1 — Grafo bipartito simple

Verifica que el algoritmo detecte correctamente la bipartición.

#### Test 2 — Ciclo impar

Comprueba que el programa detecte que el grafo NO es bipartito.

#### Test 3 — Grafo con varias componentes

Asegura que se procesen correctamente todos los subgrafos.

---

## h Pareo (Matching) en Grafos


- **Matching maximal** en grafos no dirigidos  
- **Matching máximo** para grafos bipartitos usando el algoritmo de **Kuhn**

Incluye:
- Implementación en C++ 
- Compatible con grafos ponderados y no ponderados (los pesos se ignoran para el pareo)
- Menú interactivo

---

### ¿Por qué este programa NO soporta grafos dirigidos?

El *matching* (pareo) se define **solo en grafos no dirigidos**, porque un matching consiste en seleccionar **aristas que no compartan vértices**, y esa definición **asume relaciones bidireccionales**.

En grafos dirigidos:

- Las aristas tienen dirección, así que la relación no es simétrica.
- Una arista `u → v` no representa un emparejamiento natural.
- Los algoritmos clásicos (Maximal, Kuhn, Hungarian, Blossom) **requieren aristas no dirigidas**.

Por lo tanto, el pareo **no tiene sentido matemático** en grafos dirigidos, y el proyecto se limita a grafos no dirigidos.

---

### Funcionalidades

#### Matching maximal
Método greedy:
- Recorre todas las aristas
- Agrega la arista al matching si ninguno de sus extremos está emparejado

#### Matching máximo (bipartitos)
Implementado con:
- **Algoritmo de Kuhn** (DFS que expande el matching)

Requiere que el usuario indique las dos particiones **L** y **R** del grafo.

---
## i Pareos Perfectos y Maximales

Este programa es Capaz de calcular **pareos (matchings)** en grafos tanto **bipartitos** como **no bipartitos**
---

### ¿Qué hace el programa?

El programa construye un grafo a partir de la **lista de adyacencia que ingresa el usuario**, y después permite obtener:

####  Matching maximal  
Usando un algoritmo **greedy**, el programa busca formar tantas parejas como sea posible, sin permitir que un nodo participe en más de un emparejamiento.  
Este matching:

- Funciona en **bipartitos y no bipartitos**  
- Es **válido** para cualquier grafo  
- Siempre garantiza que no se puede agregar otra arista al matching sin romper la validez

#### Detecta un matching perfecto  
Si durante el matching maximal todos los nodos logran emparejarse, entonces concluimos que existe un **matching perfecto**.  
Si al menos un nodo queda libre, el grafo **no tiene** matching perfecto detectable con el método aplicado.

---

### ¿Por qué NO usamos Kuhn ni Blossom?

#### Kuhn (DFS para matching máximo)  
 no lo implementamos porque:

- Kuhn **solo funciona en grafos bipartitos**  
- Nuestro programa debe aceptar grafos **generales**, donde no existe una división L y R  
- El usuario no proporciona una bipartición del grafo  
- Agregar Kuhn habría hecho el menú más complejo sin aportar a la parte de grafos no bipartitos  

Por lo tanto, no cumple con el objetivo del proyecto.

---

#### Blossom (Edmonds)  
Este algoritmo sí funciona en grafos no bipartitos y sirve para matching máximo, pero:

- Es **considerablemente complejo**  
- Requiere manejo avanzado de ciclos impares y contracciones.

Así que, decidimos no incluir Blossom para evitar complicar el código.

---

### Así logramos

#### Matching maximal  
En bipartitos y no bipartitos.  

#### Verificación de matching perfecto  
Si todos los nodos quedaron emparejados entonces es perfecto.

---


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