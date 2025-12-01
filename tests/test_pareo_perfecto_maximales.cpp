#include <iostream>
#include <vector>
using namespace std;

vector<int> matchingMaximal(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> pareja(n, -1);

    for (int i = 0; i < n; i++) {
        if (pareja[i] == -1) {
            for (int j = 0; j < adj[i].size(); j++) {
                int v = adj[i][j];
                if (pareja[v] == -1) {
                    pareja[i] = v;
                    pareja[v] = i;
                    break;
                }
            }
        }
    }
    return pareja;
}

void testPerfecto() {
    cout << "\nTEST 1: MATCHING PERFECTO\n";

    vector<vector<int>> adj = {
        {1},      
        {0},      
        {3},      
        {2}       
    };

    vector<int> p = matchingMaximal(adj);

    bool perfecto = true;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == -1) perfecto = false;
    }

    if (perfecto)
        cout << "OK: El matching es perfecto.\n";
    else
        cout << "ERROR: Debería ser perfecto.\n";
}

void testNoPerfecto() {
    cout << "\nTEST 2: MATCHING NO PERFECTO\n";

    vector<vector<int>> adj = {
        {1},      
        {0,2},    
        {1}       
    };

    vector<int> p = matchingMaximal(adj);

    bool libre = false;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == -1) libre = true;
    }

    if (libre)
        cout << "OK: Detectó nodos sin pareja.\n";
    else
        cout << "ERROR: Debe haber nodos libres.\n";
}

void testBipartitoChiquito() {
    cout << "\nTEST 3: BIPARTITO SIMPLE\n";

    vector<vector<int>> adj = {
        {2},     
        {3},     
        {0},     
        {1}      
    };

    vector<int> p = matchingMaximal(adj);

    if (p[0] == 2 && p[1] == 3 && p[2] == 0 && p[3] == 1)
        cout << "OK: Matching bipartito correcto.\n";
    else
        cout << "ERROR: Matching bipartito incorrecto.\n";
}

void testNoBipartitoTriangulo() {
    cout << "\nTEST 4: GRAFO NO BIPARTITO (TRIÁNGULO)\n";
    vector<vector<int>> adj = {
        {1,2},
        {0,2},
        {0,1}
    };

    vector<int> p = matchingMaximal(adj);

    // En un triángulo siempre queda uno libre
    int libres = 0;
    for (int i = 0; i < 3; i++)
        if (p[i] == -1) libres++;

    if (libres == 1)
        cout << "OK: Uno queda libre como debe ser.\n";
    else
        cout << "ERROR: Debe haber exactamente 1 nodo libre.\n";
}

void testMaximal() {
    cout << "\nTEST 5: VERIFICAR QUE EL MATCHING SEA MAXIMAL\n";

    vector<vector<int>> adj = {
        {1},      
        {0,2},    
        {1,3},    
        {2}       
    };

    vector<int> p = matchingMaximal(adj);

    if (p[0] == 1 && p[2] == 3)
        cout << "OK: Matching maximal correcto.\n";
    else
        cout << "ERROR: Debió emparejar (1-2) y (3-4).\n";
}


int main() {
    testPerfecto();
    testNoPerfecto();
    testBipartitoChiquito();
    testNoBipartitoTriangulo();
    testMaximal();

    return 0;
}
