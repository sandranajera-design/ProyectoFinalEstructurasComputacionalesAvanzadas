#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;
using lista = vector<vector<int>>;

bool bfs(int inicio, const lista& grafo, vector<int>& VColor) {
    queue<int> q;
    q.push(inicio);
    if (VColor[inicio] == 0) VColor[inicio] = 1;

    while (!q.empty()) {
        int nodo = q.front();
        q.pop();
        for (int vecino : grafo[nodo]) {
            if (VColor[vecino] == 0) {
                q.push(vecino);
                VColor[vecino] = -VColor[nodo];
            }
            if (VColor[nodo] == VColor[vecino]) {
                return false;
            }
        }
    }
    return true;
}

bool esBipartito(const lista& grafo) {
    vector<int> VColor(grafo.size(), 0);
    for (size_t i = 0; i < grafo.size(); i++) {
        if (VColor[i] == 0) {
            if (!bfs(i, grafo, VColor)) return false;
        }
    }
    return true;
}

int main() {
    // TEST 1: Grafo bipartito simple
    {
        lista g = {
            {1},
            {0, 2},
            {1, 3},
            {2}
        };
        assert(esBipartito(g) == true);
    }

    // TEST 2: Grafo no bipartito (ciclo impar)
    {
        lista g = {
            {1, 2},
            {0, 2},
            {0, 1}
        };
        assert(esBipartito(g) == false);
    }

    // TEST 3: Grafo con componentes bipartitas
    {
        lista g = {
            {1},
            {0},
            {3, 4},
            {2},
            {2}
        };
        assert(esBipartito(g) == true);
    }

    // TEST 4: Grafo con componente no bipartita
    {
        lista g = {
            {1},
            {0},
            {3, 4},
            {2, 4},
            {2, 3}
        };
        assert(esBipartito(g) == false);
    }

    cout << "Todos los tests de bipartito pasaron correctamente.\n";
    return 0;
}
