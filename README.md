
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
- En grafos dirigidos, la existencia de aristas como \( u \rightarrow v \) y \( v \rightarrow u \) altera la definición tradicional de árbol.
- Un árbol **siempre** es una estructura en la que las aristas **no tienen dirección**.

Si el grafo fuera dirigido, habría que usar definiciones distintas como:
- *arborescencia*
- *arborescencia enraizada*
- *directed spanning tree*

Esos conceptos se consideran aparte y **no equivalen a un árbol tradicional**.

Por eso, este programa funciona únicamente para **grafos no dirigidos**, que es la definición clásica usada en teoría de grafos.

---




##  Cómo Compilar

Debes de tener **g++** instalado (MinGW en Windows o GNU/G++ en Linux/Mac).

