/*
Sandra Lizeth Nájera Quesada
José Adrián Martínez Pérez

    Estructuras Computacionales Avanzadas
    Tercer semestre
    Algoritmo para pareos perfectos y maximales.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    cout << "Ingrese el numero de nodos: ";
    cin >> n;

    vector<vector<int> > adj(n);

    cout << "Ingrese la lista de adyacencia:\n";
    for (int i = 0; i < n; i++) {
        int cant;
        cout << "¿Cuantos vecinos tiene el nodo " << i + 1 << "?: ";
        cin >> cant;
        cout << "Ingrese los vecinos del nodo " << i + 1 << ": ";
        for (int j = 0; j < cant; j++) {
            int v;
            cin >> v;
            if (v >= 1 && v <= n && v != i + 1)
                adj[i].push_back(v - 1);
        }
    }

    cout << "\nLista de adyacencia ingresada:\n";
    for (int i = 0; i < n; i++) {
        cout << "Nodo " << i + 1 << ": ";
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] + 1 << " ";
        cout << endl;
    }

    cout << "\nSeleccione una opcion:\n";
    cout << "1. Matching maximal (greedy)\n";
    cout << "2. Buscar matching perfecto (si existe)\n";
    int opcion;
    cin >> opcion;

    // Matching maximal (greedy)
    if (opcion == 1) {
        vector<int> pareja(n, -1);

        for (int i = 0; i < n; i++) {
            if (pareja[i] == -1) {
                for (int j = 0; j < adj[i].size(); j++) {
                    int v = adj[i][j];
                    if (pareja[v] == -1) {
                        pareja[i] = v;
                        pareja[v] = i;
                        break;
                    }
                }
            }
        }

        cout << "\nMATCHING MAXIMAL\n";
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (pareja[i] != -1 && i < pareja[i]) {
                cout << "Nodo " << i + 1 << " <--> Nodo " << pareja[i] + 1 << endl;
                total++;
            }
        }

        cout << "\nNodos sin pareja:\n";
        bool libre = false;
        for (int i = 0; i < n; i++) {
            if (pareja[i] == -1) {
                cout << "Nodo " << i + 1 << endl;
                libre = true;
            }
        }
        if (!libre) cout << "Todos los nodos tienen pareja.\n";
        cout << "\nTotal de emparejamientos: " << total << endl;
        return 0;
    }

    // Buscar matching perfecto (si existe)
    if (opcion == 2) {
        vector<int> pareja(n, -1);

        // Greedy inicial
        for (int i = 0; i < n; i++) {
            if (pareja[i] == -1) {
                for (int j = 0; j < adj[i].size(); j++) {
                    int v = adj[i][j];
                    if (pareja[v] == -1) {
                        pareja[i] = v;
                        pareja[v] = i;
                        break;
                    }
                }
            }
        }

        // Verificar si es perfecto
        bool perfecto = true;
        for (int i = 0; i < n; i++) {
            if (pareja[i] == -1) {
                perfecto = false;
                break;
            }
        }

        cout << "\nMATCHING (VERIFICACIÓN DE PERFECTO)\n";
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (pareja[i] != -1 && i < pareja[i]) {
                cout << "Nodo " << i + 1 << " <--> Nodo " << pareja[i] + 1 << endl;
                total++;
            }
        }

        if (perfecto) {
            cout << "\n>>> SI EXISTE MATCHING PERFECTO <<<\n";
        } else {
            cout << "\n>>> NO EXISTE MATCHING PERFECTO <<<\n";
        }

        cout << "\nTotal de emparejamientos: " << total << endl;
        return 0;
    }

    return 0;
}
