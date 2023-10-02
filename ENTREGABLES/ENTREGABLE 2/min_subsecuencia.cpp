#include <vector>
#include <iostream>

using namespace std;

int indiceMinSubsec(vector<int> v, int l, int r){
    int i = l;
    int min = i;
    while(i<=r){
        if(v[i] < v[min]){
            min = i;
        }
        i++;
    }
    return min;
}

int main() {
    /* No hace falta modificar el main */
    // Leo las entradas
    int n; //Longitud del vector a rotar
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }
    
    int l,r;
    cin >> l >> r;
    // Calculo el minimo
    int min = indiceMinSubsec(v,l,r);
    
    // Impimo salida
    cout << min;
        
    return 0;
}
