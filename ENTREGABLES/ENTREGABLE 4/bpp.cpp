#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void ordenar(vector<int> &items){
    // Poner aca una implementación de ordenar
    // Implementaré COUNTING SORT descendente:
    // Busco elemento máximo de la secuencia:
    vector<int> b = items;
    int max = b[0];
    for(int i = 0; i<b.size(); i++){
        if(b[i] > max){
            max = b[i];
        }
    }
    // Inicializo un vector C que guardará el número de veces que se repite cada elemento.
    // Cada posicion de C corresponde con el elemento en b.
    vector <int> c(max+1, 0);
    for(int i=0; i<b.size(); i++){
        c[b[i]] = c[b[i]] + 1;
    }
    // Una vez construido C, procedemos a reemplazar los valores de items.
    for(int i=c.size()-1; i>0; i--){
        int j = c[i];
        int sumaIndices = 0;
        if(c[i] > 0){
            for(int k = c.size()-1; k>i; k--){
                sumaIndices = sumaIndices + c[k];
            }
        }
        while(j>0){
            items[j+sumaIndices-1] = i;
            j--;
        }
    }

    // Atencion: no todas las implementaciones son
    // suficientemente rápidas para resolver en el
    // tiempo máximo permitido de la prueba automatizada.
    // Elegir entre las implementaciones vistas en
    // clase.
    //
    // Observación:
    // No vale usar std::sort()
}


int bestFit(int W, vector<int> &items){
    multiset<int> restos;
    for(int i=0; i<(int)items.size(); ++i){
        restos.insert(W);
    }
    int res = 0;
    for(int i=0; i<(int)items.size(); ++i){
        multiset<int>::iterator it = restos.lower_bound(items[i]);
        int restoAct = *it;
        if(restoAct==W){
            res++;
        }
        restoAct -= items[i];
        restos.erase(it);
        restos.insert(restoAct);
    }
    return res;
}

int main(){
    int N, W, aux;

    //Se levantan los items y la capacidad del contenedor
    cin >> N >> W;
    vector<int> items;
    for(int i=0; i<N; ++i){
        cin >> aux;
        items.push_back(aux);
    }
    //Se corre best-fit
    int cant1 = bestFit(W, items);
    cout << "Con la idea bestFit, se consigue una asignacion con " << cant1 << " contenedores" << endl;

    //Se ordenan los items
    ordenar(items);
    //Se corre best-fit-decreasing
    int cant2 = bestFit(W, items);
    cout << "Con la idea bestFitDecreasing, se consigue una asignacion con " << cant2 << " contenedores" << endl;

    return 0;
}

