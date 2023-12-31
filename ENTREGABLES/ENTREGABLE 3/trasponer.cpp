#include <iostream>
#include <vector>

using namespace std;

void trasponer(vector<vector<int> > &m) {
    int i = 0;
    while(i<m.size()){
        int j = i;
        while(j<m[i].size()){
            int temp = m[j][i];
            m[j][i] = m[i][j];
            m[i][j] = temp;
            j++;
        }
        i++;
    }
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

    trasponer(m); 
    
    cout << filas << " " << columnas << endl;
    for (int f = 0; f < filas; ++f) {
        for (int c = 0; c < columnas; ++c) {
            cout << m[f][c] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

