/*
Sandra Lizeth Nájera Quesada
José Adrián Martínez Pérez

    Estructuras Computacionales Avanzadas
    Tercer semestre
    Algoritmo para emparejamiento maximal y máximo.
*/

#include <iostream>
#include <vector>
using namespace std;

// Matching maximal (greedy) 

void matchingMaximal() {
    int n;
    cout << "Ingrese el numero de nodos del grafo: ";
    cin >> n;

    vector<vector<int> > adj(n); // Lista de adyacencia para el grafo

    cout << "Ingrese la lista de adyacencia:\n";
    for (int i = 0; i < n; i++) {
        int cant;
        cout << "Cuantos vecinos tiene el nodo " << i + 1 << "?: ";
        cin >> cant;
        cout << "Ingrese los vecinos del nodo " << i + 1 << ": ";
        for (int j = 0; j < cant; j++) {
            int v;
            cin >> v;
            if (v >= 1 && v <= n && v != i + 1)
                adj[i].push_back(v - 1);
        }
    }

    // Vector que indica con quién está emparejado cada nodo
    // -1 significa que no tiene pareja
    vector<int> pareja(n, -1);

    // Algoritmo greedy
    for (int i = 0; i < n; i++) {
         // Solo se emparejan los nodos libres
        if (pareja[i] == -1) {
            for (int j = 0; j < adj[i].size(); j++) {
                int v = adj[i][j];
                if (pareja[v] == -1) { // Si el vecino también está libre, los emparejamos
                    pareja[i] = v;
                    pareja[v] = i;
                    break;
                }
            }
        }
    }

    // Mostrar resultados
    cout << "\nMATCHING MAXIMAL\n";
    int total = 0;

    for (int i = 0; i < n; i++) {
        // Mostrar cada pareja solo una vez
        if (pareja[i] != -1 && i < pareja[i]) {
            cout << "Nodo " << i + 1 << " <--> Nodo " << pareja[i] + 1 << "\n";
            total++;
        }
    }

    cout << "Total de emparejamientos: " << total << "\n\n";
}

// Matching maximo (khun)
vector<vector<int> > adjB;  // Lista de adyacencia del lado izquierdo
vector<int> emparejamiento; // Indica quién está emparejado con cada nodo derecho
vector<bool> usado;         // Marca si un nodo izquierdo ya fue usado en la DFS
int nL, nR;                 // Tamaños de los lados izquierdo y derecho

// DFS para encontrar aumentos en el matching
bool dfs(int u) {
    if (usado[u]) return false;
    usado[u] = true;

     // Revisamos todos los vecinos de u
    for (int i = 0; i < adjB[u].size(); i++) {
        int v = adjB[u][i];
        // Si v está libre, lo emparejamos
        // O si v ya tiene pareja, intentamos reasignarla (aumento)
        if (emparejamiento[v] == -1 || dfs(emparejamiento[v])) {
            emparejamiento[v] = u;
            return true;
        }
    }
    return false;
}

void matchingMaximoKuhn() {
    int E;
    cout << "Ingrese cantidad de nodos IZQUIERDA: ";
    cin >> nL;
    cout << "Ingrese cantidad de nodos DERECHA: ";
    cin >> nR;
    cout << "Ingrese cantidad de aristas: ";
    cin >> E;

    adjB.assign(nL, vector<int>());
    emparejamiento.assign(nR, -1);

    cout << "Ingrese las aristas (u v) donde u es nodo izquierdo y v derecho:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adjB[u].push_back(v);
    }

    int emp = 0;

    // Intentamos emparejar cada nodo del lado izquierdo
    for (int u = 0; u < nL; u++) {
        usado.assign(nL, false);
        if (dfs(u)) emp++;
    }

    cout << "\nMATCHING MÁXIMO (KUHN)\n";
    cout << "Emparejamientos encontrados: " << emp << "\n";

    for (int v = 0; v < nR; v++) {
        if (emparejamiento[v] != -1)
            cout << "Izq " << emparejamiento[v] << " <--> Der " << v << "\n";
    }

    cout << "\n";
}

int main() {
    int opcion;

    cout << "=== MENU DE MATCHING EN GRAFOS ===\n";
    cout << "1. Matching MAXIMAL (Greedy) Grafos generales\n";
    cout << "2. Matching MAXIMO (Kuhn) Grafos bipartitos\n";
    cout << "Elija opcion: ";
    cin >> opcion;

    if (opcion == 1) {
        matchingMaximal();
    } else if (opcion == 2) {
        matchingMaximoKuhn();
    } else {
        cout << "Opcion invalida.\n";
    }

    return 0;
}
