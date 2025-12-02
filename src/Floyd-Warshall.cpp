/*
Sandra Lizeth Nájera Quesada
José Adrián Martínez Pérez    

    Estructuras Computacionales Avanzadas
    Tercer semestre
    Algoritmo Floyd-Warshall para distancias más cortas
    
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <windows.h>
using namespace std;

using matriz = vector<vector<int>>;
const int INF = numeric_limits<int>::max();

int n;

void llenarPonderadoNoDirigido(matriz& dist) {
    cout << "\nIngresa la distancia entre los nodos (usa -1 si no hay conexión):\n";
    for (int i = 0; i < n; i++) dist[i][i] = 0;

    for (int i = 0, d; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "Distancia entre " << i + 1 << " y " << j + 1 << ": ";
            cin >> d;
            if (d == -1) dist[i][j] = dist[j][i] = INF;
            else dist[i][j] = dist[j][i] = d;
        }
    }
}

void llenarPonderadoDirigido(matriz& dist) {
    cout << "\nIngresa la distancia entre los nodos (usa -1 si no hay conexión):\n";
    for (int i = 0; i < n; i++) dist[i][i] = 0;

    for (int i = 0, d; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            cout << "Distancia de " << i + 1 << " a " << j + 1 << ": ";
            cin >> d;
            if (d == -1) dist[i][j] = INF;
            else dist[i][j] = d;
        }
    }
}

void llenarNoPonderadoNoDirigido(matriz& dist) {
    cout << "\n¿Existe arista entre los nodos? (1 = Sí, 0 = No)\n";
    for (int i = 0; i < n; i++) dist[i][i] = 0;

    for (int i = 0, a; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "Arista entre " << i + 1 << " y " << j + 1 << ": ";
            cin >> a;
            if (a == 1) dist[i][j] = dist[j][i] = 1;
            else dist[i][j] = dist[j][i] = INF;
        }
    }
}

void llenarNoPonderadoDirigido(matriz& dist) {
    cout << "\n¿Existe arista entre los nodos? (1 = Sí, 0 = No)\n";
    for (int i = 0; i < n; i++) dist[i][i] = 0;

    for (int i = 0, a; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            cout << "Arista de " << i + 1 << " a " << j + 1 << ": ";
            cin >> a;
            if (a == 1) dist[i][j] = 1;
            else dist[i][j] = INF;
        }
    }
}

void floydWarshall(matriz& dist) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
}

void imprimirResultados(const matriz& dist) {
    cout << "\nDistancias más cortas entre pares de nodos:\n\n";

    cout << setw(20) << " ";
    for (int j = 1; j <= n; j++) cout << setw(10) << j;
    cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << setw(20) << ("Desde nodo " + to_string(i + 1) + ":");
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) cout << setw(10) << "INF";
            else cout << setw(10) << dist[i][j];
        }
        cout << "\n";
    }
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    cout << "Número de nodos del grafo: ";
    cin >> n;

    matriz dist(n, vector<int>(n, INF));

    int dirigido, ponderado;

    cout << "¿El grafo es dirigido? (1 = Sí, 0 = No): ";
    cin >> dirigido;

    cout << "¿El grafo es ponderado? (1 = Sí, 0 = No): ";
    cin >> ponderado;

    if (ponderado && dirigido) llenarPonderadoDirigido(dist);
    else if (ponderado && !dirigido) llenarPonderadoNoDirigido(dist);
    else if (!ponderado && dirigido) llenarNoPonderadoDirigido(dist);
    else llenarNoPonderadoNoDirigido(dist);

    floydWarshall(dist);
    imprimirResultados(dist);

    return 0;
}
