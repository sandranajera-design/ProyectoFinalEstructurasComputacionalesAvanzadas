#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

vector<vector<int> > adj;       
vector<vector<int> > adj_rev;   
vector<bool> visitado;

void bfs(int inicio, vector<int>& componente, const vector<vector<int> >& g) {
    queue<int> q;
    q.push(inicio);
    visitado[inicio] = true;

    while (!q.empty()) {
        int u = q.front(); 
        q.pop();
        componente.push_back(u);

        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (!visitado[v]) {
                visitado[v] = true;
                q.push(v);
            }
        }
    }
}

stack<int> pila;

void dfs1(int u) {
    visitado[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!visitado[v]) dfs1(v);
    }
    pila.push(u);
}

void dfs2(int u, vector<int>& componente) {
    visitado[u] = true;
    componente.push_back(u);
    for (int i = 0; i < adj_rev[u].size(); i++) {
        int v = adj_rev[u][i];
        if (!visitado[v]) dfs2(v, componente);
    }
}

int main() {
    int n, m;
    int dirigido, ponderado;

    cout << "Numero de nodos: ";
    cin >> n;
    cout << "Numero de aristas: ";
    cin >> m;

    cout << "¿Es dirigido? (1 = si, 0 = no): ";
    cin >> dirigido;

    cout << "¿Es ponderado? (1 = si, 0 = no): ";
    cin >> ponderado;

    adj.assign(n, vector<int>());
    adj_rev.assign(n, vector<int>());

    cout << "\nIngresa las aristas:\n";
    if (ponderado)
        cout << "(formato: u v w)\n";
    else
        cout << "(formato: u v)\n";

    for (int i = 0; i < m; i++) {
        int u, v, w = 1;
        if (ponderado) cin >> u >> v >> w;
        else cin >> u >> v;

        adj[u].push_back(v);

        if (!dirigido) {
            
            adj[v].push_back(u);
        } else {
            adj_rev[v].push_back(u);
        }
    }

    if (!dirigido) {
        visitado.assign(n, false);
        cout << "\n=== Componentes Conexas ===\n";
        int comp = 0;

        for (int i = 0; i < n; i++) {
            if (!visitado[i]) {
                vector<int> componente;
                bfs(i, componente, adj);

                comp++;
                cout << "Componente " << comp << ": { ";
                for (int j = 0; j < componente.size(); j++)
                    cout << componente[j] << " ";
                cout << "}\n";
            }
        }
    }

    else {
        visitado.assign(n, false);
        for (int i = 0; i < n; i++)
            if (!visitado[i]) dfs1(i);

        visitado.assign(n, false);
        int comp = 0;

        cout << "\nComponentes Fuertemente Conexas (SCC)\n";

        while (!pila.empty()) {
            int u = pila.top();
            pila.pop();

            if (!visitado[u]) {
                vector<int> componente;
                dfs2(u, componente);

                comp++;
                cout << "SCC " << comp << ": { ";
                for (int j = 0; j < componente.size(); j++)
                    cout << componente[j] << " ";
                cout << "}\n";
            }
        }
    }

    return 0;
}
