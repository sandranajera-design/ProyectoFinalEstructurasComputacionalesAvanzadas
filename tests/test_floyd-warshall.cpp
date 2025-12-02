#include <iostream>
#include <vector>
#include <limits>
#include <windows.h>
using namespace std;

const int INF = numeric_limits<int>::max();

void floydWarshall(vector<vector<int>>& dist, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "  TEST 1: Grafo no dirigido simple\n";

    int n = 4;
    vector<vector<int>> dist1 = {
        {0,   3, INF, 7},
        {3,   0,   1, INF},
        {INF, 1,   0,   2},
        {7, INF,  2,   0}
    };

    vector<vector<int>> expected1 = {
        {0, 3, 4, 6},
        {3, 0, 1, 3},
        {4, 1, 0, 2},
        {6, 3, 2, 0}
    };

    floydWarshall(dist1, n);

    bool ok1 = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist1[i][j] != expected1[i][j])
                ok1 = false;

    if (ok1)
        cout << "OK: Floyd–Warshall calculó correctamente las distancias\n";
    else
        cout << "ERROR: El resultado no coincide con el esperado\n";


    cout << "  TEST 2: Grafo dirigido con pesos\n";

    n = 4;
    vector<vector<int>> dist2 = {
        {0,   5, INF, 10},
        {INF, 0,   3, INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    vector<vector<int>> expected2 = {
        {0, 5, 8, 9},
        {INF, 0, 3, 4},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    floydWarshall(dist2, n);

    bool ok2 = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist2[i][j] != expected2[i][j])
                ok2 = false;

    if (ok2)
        cout << "OK: Floyd–Warshall funciona correctamente en grafos dirigidos\n";
    else
        cout << "ERROR: Resultado incorrecto en el grafo dirigido\n";


    cout << "  TEST 3: Verificar resistencia a pesos negativos\n";

    n = 3;
    vector<vector<int>> dist3 = {
        {0,   4, INF},
        {INF, 0,  -2},
        {1, INF,   0}
    };

    vector<vector<int>> expected3 = {
        {0, 4, 2},
        {-1, 0, -2},
        {1, 5, 0}
    };

    floydWarshall(dist3, n);

    bool ok3 = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dist3[i][j] != expected3[i][j])
                ok3 = false;

    if (ok3)
        cout << "OK: Manejados correctamente los pesos negativos (sin ciclos)\n";
    else
        cout << "ERROR: Resultado incorrecto con pesos negativos\n";

    return 0;
}
