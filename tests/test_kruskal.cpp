#include <iostream>
#include <vector>
#include <cassert>
#include "C:\Users\adria\Documents\ProyectoFinalEstructurasComputacionalesAvanzadas-1\src\KruskalLib.h"
using namespace std;

void test1() {
    int n = 4;
    vector<Arista> aristas = {{0,1,1},{0,2,2},{1,2,3},{1,3,4},{2,3,5}};
    vector<Arista> MST = kruskal(n, aristas,false);
    int suma = 0;
    for(auto& a: MST) suma += a.peso;
    assert(suma == 7);
    vector<Arista> MaxST = kruskal(n, aristas,true);
    suma = 0;
    for(auto& a: MaxST) suma += a.peso;
    assert(suma == 11);
    cout << "TEST 1 OK\n";
}

void test2() {
    int n = 5;
    vector<Arista> aristas = {{0,1,2},{0,2,3},{1,2,4},{1,3,5},{3,4,1}};
    vector<Arista> MST = kruskal(n, aristas,false);
    int suma = 0;
    for(auto& a: MST) suma += a.peso;
    assert(suma == 11);
    vector<Arista> MaxST = kruskal(n, aristas,true);
    suma = 0;
    for(auto& a: MaxST) suma += a.peso;
    assert(suma == 13);
    cout << "TEST 2 OK\n";
}

void test3() {
    int n = 3;
    vector<Arista> aristas = {{0,1,5},{1,2,10},{0,2,15}};
    vector<Arista> MST = kruskal(n, aristas,false);
    int suma = 0;
    for(auto& a: MST) suma += a.peso;
    assert(suma == 15);
    vector<Arista> MaxST = kruskal(n, aristas,true);
    suma = 0;
    for(auto& a: MaxST) suma += a.peso;
    assert(suma == 25);
    cout << "TEST 3 OK\n";
}

int main() {
    test1();
    test2();
    test3();
    cout << "Todos los tests fueron exitosos.";
    return 0;
}
