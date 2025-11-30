#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//Listas de adyacencia para el grafo y el vector para visitados
vector<vector<int> > adj;       
vector<vector<int> > adj_rev;   
vector<bool> visitado;

//Función BFS para componentes conexas en grafos no dirigidos
void bfs(int inicio, vector<int>& componente, const vector<vector<int> >& g) {
    queue<int> q;
    q.push(inicio);
    visitado[inicio] = true;

    while (!q.empty()) {
        int u = q.front(); 
        q.pop();
        componente.push_back(u); //se agrega el nodo a la componente actual

        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (!visitado[v]) {
                visitado[v] = true;
                q.push(v); //continua con el BFS
            }
        }
    }
}

//Se crea la pila para kosaraju
stack<int> pila;

//Función DFS1 para primera parte del algoritmo de Kosaraju, llena la pila
void dfs1(int u) {

    visitado[u] = true;
    //explora vecinos
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!visitado[v]) dfs1(v);
    }
    //cuando termina el DFS en u, se mete en la pila
    pila.push(u);
}

//Función DFS2 para el grafo invertido, extrae una SCC
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

    //En componentes conexas no afecta si un grafo es ponderado o no para el resultado
    cout << "¿Es ponderado? (1 = si, 0 = no): ";
    cin >> ponderado;

    //inicializa las listas de adyacencia
    adj.assign(n, vector<int>());
    adj_rev.assign(n, vector<int>());

    cout << "\nIngresa las aristas:\n";
    if (ponderado)
        cout << "(formato: u v w)\n";
    else
        cout << "(formato: u v)\n";

        //lee el grafo
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
        cout << "\nComponentes Conexas\n";
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
        //DFS para llenar la pila
        for (int i = 0; i < n; i++)
            if (!visitado[i]) dfs1(i);

        //DFS en el grafo invertido, con el orden de la pila
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
