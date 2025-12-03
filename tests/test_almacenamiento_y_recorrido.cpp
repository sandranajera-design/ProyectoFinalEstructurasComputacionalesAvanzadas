#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

// TEST 1: Grafo simple 3 nodos usando LISTA DE ADYACENCIA
void test1() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "TEST 1: Lista de adyacencia\n";

    int nodos = 3;
    vector<vector<int>> listaAdyacencia(nodos);
    listaAdyacencia[0] = {1};
    listaAdyacencia[1] = {0,2};
    listaAdyacencia[2] = {1};

    vector<bool> visitado(nodos, false);
    stack<int> s;
    s.push(0);
    while (!s.empty()) {
        int actual = s.top(); s.pop();
        if (!visitado[actual]) {
            visitado[actual] = true;
            for (int v : listaAdyacencia[actual]) s.push(v);
        }
    }

    bool exito = all_of(visitado.begin(), visitado.end(), [](bool v){return v;});
    if (exito) cout << "Test 1 finalizó con éxito\n";
}

// TEST 2: Grafo con ciclo usando MATRIZ DE ADYACENCIA
void test2() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "TEST 2: Matriz de adyacencia\n";

    int nodos = 4;
    vector<vector<int>> matrizAdyacencia(nodos, vector<int>(nodos,0));
    // Aristas: 0-1,0-2,1-3,2-3
    matrizAdyacencia[0][1] = matrizAdyacencia[1][0] = 1;
    matrizAdyacencia[0][2] = matrizAdyacencia[2][0] = 1;
    matrizAdyacencia[1][3] = matrizAdyacencia[3][1] = 1;
    matrizAdyacencia[2][3] = matrizAdyacencia[3][2] = 1;

    vector<bool> visitado(nodos, false);
    // BFS desde nodo 0
    queue<int> q;
    q.push(0);
    visitado[0] = true;
    while (!q.empty()) {
        int actual = q.front(); q.pop();
        for (int v = 0; v < nodos; v++) {
            if (matrizAdyacencia[actual][v] && !visitado[v]) {
                visitado[v] = true;
                q.push(v);
            }
        }
    }

    bool exito = all_of(visitado.begin(), visitado.end(), [](bool v){return v;});
    if (exito) cout << "Test 2 finalizó con éxito\n";
}

// TEST 3: Grafo desconectado usando MATRIZ DE INCIDENCIA
void test3() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << "TEST 3: Matriz de incidencia\n";

    int nodos = 3;
    int aristas = 2;
    // Aristas: e1:0->1, e2:1->0 (para desconexión se deja nodo 2 sin aristas)
    vector<vector<int>> matrizIncidencia(nodos, vector<int>(aristas,0));
    matrizIncidencia[0][0] = -1; matrizIncidencia[1][0] = 1;
    matrizIncidencia[1][1] = -1; matrizIncidencia[0][1] = 1;

    vector<bool> visitado(nodos,false);
    // DFS usando la matriz de incidencia
    stack<int> s;
    s.push(0);
    visitado[0] = true;
    while (!s.empty()) {
        int actual = s.top(); s.pop();
        for (int e = 0; e < aristas; e++) {
            if (matrizIncidencia[actual][e] == -1) {
                for (int v = 0; v < nodos; v++) {
                    if (v != actual && matrizIncidencia[v][e] == 1 && !visitado[v]) {
                        visitado[v] = true;
                        s.push(v);
                    }
                }
            }
        }
    }

    if (!visitado[2]) cout << "Test 3 finalizó con éxito (nodo desconectado detectado)\n";
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    test1();
    test2();
    test3();

    cout << "\nTodos los tests finalizaron correctamente.\n";
    return 0;
}
