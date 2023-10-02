#include <vector>
#include <iostream>

using namespace std;

void ordenar1(vector<int>& v){ //Insertion Sort
    int i = 1;
    int j;
    int x;
    while(i<v.size()){
        x = v[i];
        j = i-1;
        while(j>=0 && v[j] > x){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = x;
        i++;
    }
}

int main() {
    /* No hace falta modificar el main */

    // Leo las entradas
    int n; //Longitud del vector
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }

    // Hago el ordenamiento
    ordenar1(v);

    // Imprimo el vector resultado
    i = 0;
    while (i < v.size()){
        cout << v[i] << " ";
        i++;
    }

    return 0;
}