/*
Sandra Lizeth Nájera Quesada
José Adrián Martínez Pérez

    Estructuras Computacionales Avanzadas
    Tercer semestre
    Algoritmo Kruskal para el árbol de expansión mínima y máxima
    
*/

#include <iostream>
#include <vector>
#include "KruskalLib.h"
using namespace std;

int main() {
    int n, m;
    cout << "Ingrese numero de nodos: ";
    cin >> n;
    cout << "Ingrese numero de aristas: ";
    cin >> m;
    vector<Arista> aristas(m);
    cout << "Ingrese aristas en formato: nodo1 nodo2 peso\n";
    for (int i = 0; i < m; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        a--; b--;
        aristas[i] = {a, b, p};
    }
    vector<Arista> MST = kruskal(n, aristas, false);
    int pesoMST = 0;
    cout << "\n--- MST ---\n";
    for (auto& ar : MST) {
        cout << "Arista seleccionada: " << ar.u+1 << " - " << ar.v+1 << " Peso: " << ar.peso << "\n";
        pesoMST += ar.peso;
    }
    cout << "Peso total: " << pesoMST << "\n";

    vector<Arista> MaxST = kruskal(n, aristas, true);
    int pesoMax = 0;
    cout << "\n--- MaxST ---\n";
    for (auto& ar : MaxST) {
        cout << "Arista seleccionada: " << ar.u+1 << " - " << ar.v+1 << " Peso: " << ar.peso << "\n";
        pesoMax += ar.peso;
    }
    cout << "Peso total: " << pesoMax << "\n";
    return 0;
}
