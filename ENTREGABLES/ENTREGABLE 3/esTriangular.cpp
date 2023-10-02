#include <iostream>
#include <vector>

using namespace std;

bool esTriangular(const vector<vector<int> > &m){
    bool triangularSuperior = true;
    bool triangularInferior = true;
    // Triangular inferior
    int i = 0;
    while(i<m.size()){
        int j = i+1;
        while(j<m[i].size()){
            if(m[i][j] != 0){
                triangularInferior = false;
            }
            j++;
        }
        i++;
    }
    // Triangular superior
    int k = 1;
    while(k<m.size()){
        int j = k-1;
        while(j>=0){
            if(m[k][j] != 0){
                triangularSuperior = false;
            }
            j--;
        }
        k++;
    }
    bool triangular = triangularInferior || triangularSuperior;
    return triangular;
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    int n; // Cantidad de filas y columnas de la matriz
    cin >> n;
    int x;
    int filas = n, columnas = n;
    vector<vector<int> > m(filas, vector<int>(columnas, 0)); // En m leo la matriz
    
    for (int f = 0; f < filas; ++f) {
        for (int c = 0; c < columnas; ++c) {
            cin >> x;
            m[f][c] = x;
        }
    }

    bool res = esTriangular(m);
    cout << (res ? "true" : "false");    
    return 0;
}
