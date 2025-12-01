
## c Componentes Conexas

El programa (`src/ComponentesConexas.cpp`) permite:

- Elegir si el grafo es dirigido o no dirigido
- Elegir si es ponderado (el peso no afecta las componentes)
- Ingresar las aristas
- Mostrar:
  - Componentes Conexas (si es grafo no dirigido)
  - Componentes Fuertemente Conexas por Kosaraju (si es dirigido)

---

##  Pruebas

En `/tests/test_componentes_conexas.cpp` se incluyen **tres pruebas automáticas**:

### Test 1 — Componentes Conexas  
Comprueba que en un grafo no dirigido se detecten exactamente 2 componentes.

###  Test 2 — Grafo Invertido  
Valida que el grafo inverso (`adj_rev`) se construya correctamente.

###  Test 3 — Kosaraju para SCC  
Evalúa un grafo dirigido con dos ciclos para confirmar que el algoritmo detecta 2 SCC.

---

# e Verificar si un grafo es un árbol

Este proyecto implementa un algoritmo sencillo para determinar si un **grafo no dirigido** es un **árbol**.

## ¿Qué condiciones debe cumplir un árbol?

Un grafo es un árbol si y solo si cumple:

1. Está **conectado**
2. No tiene **ciclos**
3. Tiene exactamente **n − 1** aristas

El programa verifica estas tres condiciones usando DFS.

---

## ¿Por qué **NO** puede ser un grafo dirigido?

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

# h Pareo (Matching) en Grafos


- **Matching maximal** en grafos no dirigidos  
- **Matching máximo** para grafos bipartitos usando el algoritmo de **Kuhn**

Incluye:
- Implementación en C++ 
- Compatible con grafos ponderados y no ponderados (los pesos se ignoran para el pareo)
- Menú interactivo

---

## ¿Por qué este programa NO soporta grafos dirigidos?

El *matching* (pareo) se define **solo en grafos no dirigidos**, porque un matching consiste en seleccionar **aristas que no compartan vértices**, y esa definición **asume relaciones bidireccionales**.

En grafos dirigidos:

- Las aristas tienen dirección, así que la relación no es simétrica.
- Una arista `u → v` no representa un emparejamiento natural.
- Los algoritmos clásicos (Maximal, Kuhn, Hungarian, Blossom) **requieren aristas no dirigidas**.

Por lo tanto, el pareo **no tiene sentido matemático** en grafos dirigidos, y el proyecto se limita a grafos no dirigidos.

---

## Funcionalidades

### Matching maximal
Método greedy:
- Recorre todas las aristas
- Agrega la arista al matching si ninguno de sus extremos está emparejado

### Matching máximo (bipartitos)
Implementado con:
- **Algoritmo de Kuhn** (DFS que expande el matching)

Requiere que el usuario indique las dos particiones **L** y **R** del grafo.

---
## i Pareos Perfectos y Maximales

Este programa es Capaz de calcular **pareos (matchings)** en grafos tanto **bipartitos** como **no bipartitos**
---

## ¿Qué hace el programa?

El programa construye un grafo a partir de la **lista de adyacencia que ingresa el usuario**, y después permite obtener:

###  Matching maximal  
Usando un algoritmo **greedy**, el programa busca formar tantas parejas como sea posible, sin permitir que un nodo participe en más de un emparejamiento.  
Este matching:

- Funciona en **bipartitos y no bipartitos**  
- Es **válido** para cualquier grafo  
- Siempre garantiza que no se puede agregar otra arista al matching sin romper la validez

### Detecta un matching perfecto  
Si durante el matching maximal todos los nodos logran emparejarse, entonces concluimos que existe un **matching perfecto**.  
Si al menos un nodo queda libre, el grafo **no tiene** matching perfecto detectable con el método aplicado.

---

## ¿Por qué NO usamos Kuhn ni Blossom?

### Kuhn (DFS para matching máximo)  
 no lo implementamos porque:

- Kuhn **solo funciona en grafos bipartitos**  
- Nuestro programa debe aceptar grafos **generales**, donde no existe una división L y R  
- El usuario no proporciona una bipartición del grafo  
- Agregar Kuhn habría hecho el menú más complejo sin aportar a la parte de grafos no bipartitos  

Por lo tanto, no cumple con el objetivo del proyecto.

---

### Blossom (Edmonds)  
Este algoritmo sí funciona en grafos no bipartitos y sirve para matching máximo, pero:

- Es **considerablemente complejo**  
- Requiere manejo avanzado de ciclos impares y contracciones.

Así que, decidimos no incluir Blossom para evitar complicar el código.

---

## Así logramos

### Matching maximal  
En bipartitos y no bipartitos.  

### Verificación de matching perfecto  
Si todos los nodos quedaron emparejados entonces es perfecto.

---

##  Para compilar

Debes de tener **g++** instalado (MinGW en Windows o GNU/G++ en Linux/Mac).

