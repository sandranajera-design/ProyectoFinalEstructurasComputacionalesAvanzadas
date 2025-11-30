#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj_test;
vector<bool> visitado_test;
bool hayCiclo_test;

void dfs_test(int u, int padre) {
    visitado_test[u] = true;
    for (int i = 0; i < adj_test[u].size(); i++) {
        int v = adj_test[u][i];
        if (!visitado_test[v]) dfs_test(v, u);
        else if (v != padre) hayCiclo_test = true;
    }
}

bool esArbol_test(int n, vector<pair<int,int>>& aristas) {
    adj_test = vector<vector<int>>(n);
    visitado_test = vector<bool>(n, false);
    hayCiclo_test = false;

    for (int i = 0; i < aristas.size(); i++) {
        int a = aristas[i].first;
        int b = aristas[i].second;
        adj_test[a].push_back(b);
        adj_test[b].push_back(a);
    }

    if (aristas.size() != n - 1) return false;

    dfs_test(0, -1);

    if (hayCiclo_test) return false;

    for (int i = 0; i < n; i++)
        if (!visitado_test[i]) return false;

    return true;
}

int main() {
    // TEST 1: Árbol correcto
    {
        int n = 5;
        vector<pair<int,int>> aristas;

        aristas.push_back({0,1});
        aristas.push_back({1,2});
        aristas.push_back({1,3});
        aristas.push_back({3,4});

        cout << "TEST 1 - Arbol valido: ";
        if (esArbol_test(n, aristas)) cout << "OK\n";
        else cout << "ERROR\n";
    }

    // TEST 2: Ciclo presente
    {
        int n = 4;
        vector<pair<int,int>> aristas;

        aristas.push_back({0,1});
        aristas.push_back({1,2});
        aristas.push_back({2,0}); 
        aristas.push_back({2,3});

        cout << "TEST 2 - Ciclo detectado: ";
        if (!esArbol_test(n, aristas)) cout << "OK\n";
        else cout << "ERROR\n";
    }

    // TEST 3: Grafo desconectado
    {
        int n = 4;
        vector<pair<int,int>> aristas;

        aristas.push_back({0,1});
        aristas.push_back({2,3}); 

        cout << "TEST 3 - Grafo desconectado: ";
        if (!esArbol_test(n, aristas)) cout << "OK\n";
        else cout << "ERROR\n";
    }

    return 0;
}
