/*
Sandra Lizeth Nájera Quesada
José Adrián Martínez Pérez

    Estructuras Computacionales Avanzadas
    Tercer semestre
    Representaciones de grafos y recorridos (DFS y BFS)
    
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <windows.h>
using namespace std;

vector<vector<int>> listaAdyacencia;
vector<vector<int>> matrizAdyacencia;
vector<vector<int>> matrizIncidencia;
vector<pair<int,int>> listaArcos;
map<int, vector<int>> diccionarioGrafo;
vector<bool> visitado;
int nodos, aristas;

void dfs(int nodo, const vector<vector<int>>& grafo) {
    visitado[nodo] = true;
    cout << nodo << " ";
    for (int vecino : grafo[nodo]) {
        if (!visitado[vecino]) dfs(vecino, grafo);
    }
}

void bfs(int inicio, const vector<vector<int>>& grafo) {
    queue<int> cola;
    visitado[inicio] = true;
    cola.push(inicio);
    while (!cola.empty()) {
        int actual = cola.front();
        cola.pop();
        cout << actual << " ";
        for (int vecino : grafo[actual]) {
            if (!visitado[vecino]) {
                visitado[vecino] = true;
                cola.push(vecino);
            }
        }
    }
}

void crearGrafo() {
    system("cls");
    cout << "Vamos a crear un grafo.\n";
    cout << "Número de nodos: ";
    cin >> nodos;
    cout << "Número de aristas: ";
    cin >> aristas;

    listaAdyacencia.assign(nodos, vector<int>());
    matrizAdyacencia.assign(nodos, vector<int>(nodos, 0));
    matrizIncidencia.assign(nodos, vector<int>(aristas, 0));
    listaArcos.clear();
    diccionarioGrafo.clear();

    cout << "Ingresa las conexiones (u v) para cada arista:\n";
    for (int i = 0; i < aristas; i++) {
        int u, v;
        cout << "Arista " << i+1 << ": ";
        cin >> u >> v;
        u--; v--; // indices 0-based

        listaAdyacencia[u].push_back(v);
        listaAdyacencia[v].push_back(u); // opcional si es no dirigido
        matrizAdyacencia[u][v] = 1;
        matrizAdyacencia[v][u] = 1;
        listaArcos.push_back({u,v});
        matrizIncidencia[u][i] = -1;
        matrizIncidencia[v][i] = 1;
        diccionarioGrafo[u].push_back(v);
        diccionarioGrafo[v]; // inicializa
    }

    cout << "\n¡Grafo creado con éxito!\n";
}

void mostrarLista() {
    system("cls");
    cout << "Lista de adyacencia:\n";
    for (int i = 0; i < nodos; i++) {
        cout << i+1 << ": ";
        for (int vecino : listaAdyacencia[i]) cout << vecino+1 << " ";
        cout << "\n";
    }
}

void mostrarMatriz() {
    system("cls");
    cout << "Matriz de adyacencia:\n   ";
    for (int i = 0; i < nodos; i++) cout << i+1 << " ";
    cout << "\n";
    for (int i = 0; i < nodos; i++) {
        cout << i+1 << ": ";
        for (int j = 0; j < nodos; j++) cout << matrizAdyacencia[i][j] << " ";
        cout << "\n";
    }
}

void mostrarMatrizIncidencia() {
    system("cls");
    cout << "Matriz de incidencia:\n   ";
    for (int i = 0; i < aristas; i++) cout << "e" << i+1 << " ";
    cout << "\n";
    for (int i = 0; i < nodos; i++) {
        cout << i+1 << ": ";
        for (int j = 0; j < aristas; j++) cout << matrizIncidencia[i][j] << " ";
        cout << "\n";
    }
}

void mostrarListaArcos() {
    system("cls");
    cout << "Lista de arcos (origen -> destino):\n";
    for (auto [u,v] : listaArcos) cout << u+1 << " -> " << v+1 << "\n";
}

void mostrarDiccionario() {
    system("cls");
    cout << "Representación tipo diccionario:\n";
    for (auto &[nodo, vecinos] : diccionarioGrafo) {
        cout << nodo+1 << ": ";
        for (int v : vecinos) cout << v+1 << " ";
        cout << "\n";
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int opcion;
    do {
        cout << "\n==============================\n";
        cout << "        MENÚ PRINCIPAL\n";
        cout << "==============================\n";
        cout << "1. Crear grafo\n";
        cout << "2. Mostrar lista de adyacencia\n";
        cout << "3. Mostrar matriz de adyacencia\n";
        cout << "4. Mostrar matriz de incidencia\n";
        cout << "5. Mostrar lista de arcos\n";
        cout << "6. Mostrar diccionario\n";
        cout << "7. DFS\n";
        cout << "8. BFS\n";
        cout << "9. Salir\n";
        cout << "Opción: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: crearGrafo(); break;
            case 2: mostrarLista(); break;
            case 3: mostrarMatriz(); break;
            case 4: mostrarMatrizIncidencia(); break;
            case 5: mostrarListaArcos(); break;
            case 6: mostrarDiccionario(); break;
            case 7:
                if (listaAdyacencia.empty()) cout << "Crea primero el grafo\n";
                else {
                    int inicio;
                    cout << "Nodo inicio DFS: ";
                    cin >> inicio;
                    visitado.assign(nodos, false);
                    dfs(inicio-1, listaAdyacencia);
                    cout << "\n";
                }
                break;
            case 8:
                if (listaAdyacencia.empty()) cout << "Crea primero el grafo\n";
                else {
                    int inicio;
                    cout << "Nodo inicio BFS: ";
                    cin >> inicio;
                    visitado.assign(nodos, false);
                    bfs(inicio-1, listaAdyacencia);
                    cout << "\n";
                }
                break;
            case 9: cout << "¡Hasta luego!\n"; break;
            default: cout << "Opción inválida\n";
        }
    } while(opcion != 9);
    return 0;
}
