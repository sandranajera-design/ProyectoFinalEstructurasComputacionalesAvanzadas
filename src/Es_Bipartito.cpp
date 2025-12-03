/*
Sandra Lizeth Nájera Quesada
José Adrián Martínez Pérez

    Estructuras Computacionales Avanzadas
    Tercer semestre
    Algoritmo de Bicoloración (BFS)
    Objetivo: Determinar si un grafo es bipartito y mostrar sus dos conjuntos.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <windows.h>
using namespace std;

using lista = vector<vector<int>>;   // Lista de adyacencia

// ---------------------------------------------------------
// BFS para intentar colorear el grafo y detectar conflictos
// ---------------------------------------------------------
bool bfs(int inicio, const lista& grafo, vector<int>& color) {
    queue<int> q;
    q.push(inicio);

    if (color[inicio] == 0)
        color[inicio] = 1;

    while (!q.empty()) {
        int nodo = q.front();
        q.pop();

        for (int vecino : grafo[nodo]) {
            if (color[vecino] == 0) {
                color[vecino] = -color[nodo];
                q.push(vecino);
            }
            else if (color[vecino] == color[nodo]) {
                cout << "\nNo es un grafo bipartito porque los nodos "
                     << min(nodo + 1, vecino + 1) << " y "
                     << max(nodo + 1, vecino + 1)
                     << " pertenecen al mismo conjunto y están conectados "
                        "(ciclo impar detectado).\n";
                return false;
            }
        }
    }
    return true;
}

// ---------------------------------------------------------
// Imprime los dos conjuntos (componentes bipartitas)
// ---------------------------------------------------------
void imprimirComponentes(const lista& grafo, const vector<int>& color) {
    cout << "\nConjunto A (color 1):\n";
    for (size_t i = 0; i < grafo.size(); i++) {
        if (color[i] == 1) {
            cout << "Nodo " << i + 1 << " → vecinos: ";
            for (int v : grafo[i]) cout << v + 1 << " ";
            cout << "\n";
        }
    }

    cout << "\nConjunto B (color -1):\n";
    for (size_t i = 0; i < grafo.size(); i++) {
        if (color[i] == -1) {
            cout << "Nodo " << i + 1 << " → vecinos: ";
            for (int v : grafo[i]) cout << v + 1 << " ";
            cout << "\n";
        }
    }
}

// ---------------------------------------------------------
// Programa principal
// ---------------------------------------------------------
int main() {

    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int n, m;
    bool dirigido;

    cout << "Número de nodos del grafo: ";
    cin >> n;

    cout << "Número de aristas: ";
    cin >> m;

    cout << "¿Es dirigido? (1 = Sí, 0 = No): ";
    cin >> dirigido;

    lista grafo(n);

    cout << "\nIngrese las " << m << " aristas (formato: u v):\n";
    cout << "(Los nodos se numeran desde 1 hasta " << n << ")\n";

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        grafo[u].push_back(v);
        if (!dirigido) grafo[v].push_back(u);
    }

    vector<int> color(n, 0);

    // Procesar todas las componentes
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            if (!bfs(i, grafo, color)) {
                return 0;
            }
        }
    }

    cout << "\nEl grafo SÍ es bipartito.\n";
    imprimirComponentes(grafo, color);

    return 0;
}
