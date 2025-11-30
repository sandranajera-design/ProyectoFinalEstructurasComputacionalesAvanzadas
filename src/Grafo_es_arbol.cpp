#include <iostream>
#include <vector>
using namespace std;

//lista de adyacencia para el grafo
vector<vector<int>> adj;
vector<bool> visitado; //vector de nodos visitados
bool hayCiclo;

//DFS para detectar ciclos, u es el nodo actual, padre es el nodo desde el que llegamos
void dfs(int u, int padre) {
    visitado[u] = true;

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];

        // Si no está visitado, seguimos
        if (!visitado[v]) {
            dfs(v, u);
        }
        // Si está visitado y NO es el padre → ciclo
        else if (v != padre) {
            hayCiclo = true;
        }
    }
}

bool esArbol(int n, vector<pair<int,int>>& aristas) {
    adj = vector<vector<int>>(n);
    visitado = vector<bool>(n, false);
    hayCiclo = false;

    //Construye al grafo 
    for (int i = 0; i < aristas.size(); i++) {
        int a = aristas[i].first;
        int b = aristas[i].second;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //  Condición 1: #aristas = n - 1
    if (aristas.size() != n - 1) {
        return false;
    }

    // Condición 2 y 3: conectado sin ciclos
    dfs(0, -1);

    if (hayCiclo) {
        return false;
    }

    // verificar que todos estén visitados
    for (int i = 0; i < n; i++) {
        if (!visitado[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, m;

    cout << "VERIFICAR SI UN GRAFO ES UN ARBOL\n\n";

    cout << "Ingresa el numero de nodos: ";
    cin >> n;

    cout << "Ingresa el numero de aristas: ";
    cin >> m;

    vector<pair<int,int>> aristas;

    cout << "\nIngresa las aristas (formato: u v):\n";
    cout << "(nodos desde 0 hasta " << n - 1 << ")\n\n";

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        aristas.push_back({u, v});
    }


    if (esArbol(n, aristas)) {
        cout << "Resultado: EL GRAFO ES UN ARBOL\n";
    } else {
        cout << "Resultado: EL GRAFO NO ES UN ARBOL\n";
    }

    return 0;
}
