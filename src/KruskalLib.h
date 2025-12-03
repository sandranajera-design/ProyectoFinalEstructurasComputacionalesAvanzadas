#ifndef KRUSKAL_LIB_H
#define KRUSKAL_LIB_H

#include <vector>
#include <algorithm>
using namespace std;

struct Arista {
    int u, v, peso;
};

int encontrar(vector<int>& padre, int x) {
    if (padre[x] == x) return x;
    return padre[x] = encontrar(padre, padre[x]);
}

bool unir(vector<int>& padre, int a, int b) {
    int ra = encontrar(padre, a);
    int rb = encontrar(padre, b);
    if (ra == rb) return false;
    padre[rb] = ra;
    return true;
}

vector<Arista> kruskal(int n, vector<Arista>& aristas, bool maxST=false) {
    vector<int> padre(n);
    for (int i = 0; i < n; i++) padre[i] = i;
    vector<Arista> resultado;
    if (!maxST) sort(aristas.begin(), aristas.end(), [](Arista a, Arista b){ return a.peso < b.peso; });
    else sort(aristas.begin(), aristas.end(), [](Arista a, Arista b){ return a.peso > b.peso; });
    for (auto& ar : aristas) {
        if (unir(padre, ar.u, ar.v)) resultado.push_back(ar);
    }
    return resultado;
}

#endif
