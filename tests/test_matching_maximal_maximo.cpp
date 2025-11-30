#include <iostream>
#include <vector>
using namespace std;


//  MATCHING MAXIMAL
vector<int> ejecutarMatchingMaximal(int n, vector<vector<int>> adj) {
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

// MATCHING MÁXIMO (KUHN)
vector<vector<int>> adjB;
vector<int> emparejamiento;
vector<bool> usado;

bool dfs(int u) {
    if (usado[u]) return false;
    usado[u] = true;

    for (int i = 0; i < adjB[u].size(); i++) {
        int v = adjB[u][i];

        if (emparejamiento[v] == -1 || dfs(emparejamiento[v])) {
            emparejamiento[v] = u;
            return true;
        }
    }
    return false;
}

int ejecutarKuhn(int nL, int nR, vector<vector<int>> adj) {
    adjB = adj;
    emparejamiento.assign(nR, -1);

    int emp = 0;
    for (int u = 0; u < nL; u++) {
        usado.assign(nL, false);
        if (dfs(u))
            emp++;
    }
    return emp;
}

int main() {

    cout << "===== TESTS MATCHING MAXIMAL =====\n";

    vector<vector<int>> adj1 = {
        {1},      
        {0,2},    
        {1,3},    
        {2},     
        {5},      
        {4}       
    };

    vector<int> res = ejecutarMatchingMaximal(6, adj1);

    int emp = 0;
    for (int i = 0; i < 6; i++)
        if (res[i] != -1 && i < res[i])
            emp++;

    if (emp == 3)
        cout << "OK: Matching maximal correcto (esperado 3)\n";
    else
        cout << "ERROR: Matching maximal incorrecto\n";


    cout << "\n===== TESTS MATCHING MÁXIMO (KUHN) =====\n";



    vector<vector<int>> adj2 = {
        {0,1},   
        {1},     
        {2}     
    };

    int emp2 = ejecutarKuhn(3, 3, adj2);

    if (emp2 == 3)
        cout << "OK: Matching máximo correcto (esperado 3)\n";
    else
        cout << "ERROR: Matching máximo incorrecto\n";

    return 0;
}
