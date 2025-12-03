#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<vector<int>> adj;      // grafo normal
vector<vector<int>> adj_rev;  // grafo invertido
vector<bool> visited;
stack<int> pila;

// DFS para componentes conexas (NO dirigido)
void dfs(int u, vector<int>& comp) {
    visited[u] = true;
    comp.push_back(u);

    for (int v : adj[u]) {
        if (!visited[v]) dfs(v, comp);
    }
}

vector<vector<int>> componentesConexas(int n) {
    visited.assign(n, false);
    vector<vector<int>> comps;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> comp;
            dfs(i, comp);
            comps.push_back(comp);
        }
    }
    return comps;
}

// Primera pasada de Kosaraju
void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs1(v);
    }
    pila.push(u);
}

// Segunda pasada en el grafo invertido
void dfs2(int u, vector<int>& comp) {
    visited[u] = true;
    comp.push_back(u);

    for (int v : adj_rev[u]) {
        if (!visited[v]) dfs2(v, comp);
    }
}

vector<vector<int>> SCC(int n) {
    visited.assign(n, false);
    while (!pila.empty()) pila.pop(); // limpiar pila

    // 1) DFS normal para llenar pila
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs1(i);

    // 2) DFS en el grafo invertido
    visited.assign(n, false);
    vector<vector<int>> comps;

    while (!pila.empty()) {
        int u = pila.top();
        pila.pop();

        if (!visited[u]) {
            vector<int> comp;
            dfs2(u, comp);
            comps.push_back(comp);
        }
    }

    return comps;
}

int main() {
    cout << "  TEST 1: Componentes conexas (Grafo NO dirigido)\n";

    int n = 5;
    adj = vector<vector<int>>(n);

    // Grafo:
    // 0 - 1 - 2    y    3 - 4

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[3].push_back(4);
    adj[4].push_back(3);

    vector<vector<int>> compsND = componentesConexas(n);

    if (compsND.size() == 2)
        cout << "OK: Se detectaron 2 componentes\n";
    else
        cout << "ERROR: Se esperaban 2 componentes, se obtuvieron: "
             << compsND.size() << "\n";


    cout << "  TEST 2: Grafo invertido\n";

    adj_rev = vector<vector<int>>(n);

    adj_rev[1].push_back(0);
    adj_rev[2].push_back(1);

    if (adj_rev[1][0] == 0 && adj_rev[2][0] == 1)
        cout << "OK: El grafo invertido está correcto\n";
    else
        cout << "ERROR en grafo invertido\n";


    cout << "  TEST 3: SCC con Kosaraju\n";

    n = 5;
    adj = vector<vector<int>>(n);
    adj_rev = vector<vector<int>>(n);

    // Aristas
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);

    adj[3].push_back(4);
    adj[4].push_back(3);

    // Invertido
    adj_rev[1].push_back(0);
    adj_rev[2].push_back(1);
    adj_rev[0].push_back(2);

    adj_rev[4].push_back(3);
    adj_rev[3].push_back(4);

    vector<vector<int>> compsSCC = SCC(n);

    if (compsSCC.size() == 2)
        cout << "OK: SCC detectó correctamente 2 componentes\n";
    else
        cout << "ERROR: Se esperaban 2 SCC, se obtuvieron: "
             << compsSCC.size() << "\n";

    return 0;
}
