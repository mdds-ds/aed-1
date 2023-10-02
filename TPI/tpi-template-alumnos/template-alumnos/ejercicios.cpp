//
// Este archivo contiene las definiciones de las funciones que implementan los ejercicios
//

#include <stdio.h>
#include <iostream>
#include <utility>

#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

using namespace std;

/******++++**************************** EJERCICIO minasAdyacentes ***********+++***********************/

int minasAdyacentes(tablero& t, pos p) {
    // Complejidad de peor caso constante, del orden de O(3*3) = O(9), es decir, O(1).
    int suma=0;
    for(int i=-1;i<=1;i++){ // Itera 3 veces por posicion dada (O(3))
        int subsuma = 0;
        for(int j=-1;j<=1;j++){ // Itera 3 veces por posicion dada (O(3))
            if(esAdyacenteValida(p,i,j,t) && t[p.first + i][p.second + j]){
                subsuma = subsuma + 1;
            }
        }
        suma = suma + subsuma;
    }
    return suma;
}

/******++++**************************** EJERCICIO plantarBanderita ***********+++***********************/

void cambiarBanderita(tablero& t, jugadas& j, pos p, banderitas& b) {
    // Complejidad de peor caso es del orden O(g) + O(g+m), es decir O(2g+m) con g = b.size() y m = j.size().
    // El siguiente ciclo tiene complejidad temporal de peor caso del orden O(g) con
    // g = b.size() puesto que recorre toda la secuencia b para encontrar si p es banderita y si lo es sacarla.
    bool found = false;
    for(int i=0;i<b.size();i++){ // Sacar la banderita.
        if(b[i] == p){ // Los accesos a la secuencia y demás operaciones elementales se consideran de orden O(1).
            found = true;
            pos c = b[b.size()-1];
            b[b.size()-1] = b[i];
            b[i]=c;
            b.pop_back();
        }
    }
    // Hacer la comparación que exige la guarda siguiente tiene complejidad de peor caso del orden O(g+m)
    // con g = b.size() y m = j.size() (más justificación en auxiliares.cpp)
    if(esPosicionSinJugarYSinBanderita(p,j,b,t) && !found){ // Poner la banderita.
        b.push_back(p); // O(1)
    }
}

/******++++**************************** EJERCICIO perdio ***********+++***********************/
bool perdio(tablero& t, jugadas& j) {
    // Complejidad de peor caso es O(m) con m = j.size()
    bool res = juegoPerdido(t,j); // Itera en el peor caso m veces, con m = j.size()
    // buscando si hay alguna posición en la que haya una mina (más justificación en auxiliares.cpp)
    return res;
}

/******++++**************************** EJERCICIO gano ***********+++***********************/
bool gano(tablero& t, jugadas& j){
    // (Más justificaciones en auxiliares.cpp, en la función juegoGanado)
    // El algoritmo tiene complejidad de peor caso O(n^2), puesto que itera n veces en la secuencia por cada
    // iteración del segundo loop, el cual está dentro de otro loop que itera también n veces en el peor caso.
    bool res = juegoGanado(t,j);
    return res;
}

/******++++**************************** EJERCICIO jugarPlus ***********+++***********************/
void jugarPlus(tablero& t, banderitas& b, pos p, jugadas& j) {
    // Complejidad de peor caso: O(h^n)
    jugada c = jugada(p, minasAdyacentes(t, p));
    j.push_back(c);
    for (int i = p.first - 1; i <= p.first + 1; i++) { // Itera 3 veces por posicion dada (orden O(1) )
        for (int k = p.second - 1; k <= p.second + 1; k++) { // Itera 3 veces por posicion dada (orden O(1) )
            pos q = pos(i, k);  // O(1)
            // Complejidad de peor caso de esPosicionSinJugarYSinBanderita es O(g+m) con g = b.size() y m = j.size()
            // Complejidad de peor caso de minasAdyacentes es O(1)
            // renombro g + m = h, es decir O(g+m) = O(h)
            if (esPosicionSinJugarYSinBanderita(q, j, b, t) && (!t[q.first][q.second]) &&
                (minasAdyacentes(t, q) == 0)) {
                // Hasta acá la complejidad de peor caso de la función es del orden O(h*h + h*jugarPlus) (ver abajo que se chequea de nuevo la guarda)
                // Acá reviso las posiciones adyacentes a la posicion encontrada del camino libre, y si son la posicion final, las agrego.
                for (int x = q.first - 1; x <= q.first + 1; x++) { // Itera 3 veces por posicion dada (orden O(1) )
                    for (int y = q.second - 1; y <= q.second + 1; y++) { // Itera 3 veces por posicion dada (orden O(1) )
                        pos r = pos(x, y);  // O(1)
                        if (esPosicionSinJugarYSinBanderita(r, j, b, t) && (!t[r.first][r.second]) &&
                            (minasAdyacentes(t, r) > 0)) { // Hasta acá la complejidad de peor caso de los ciclos es del orden O(h)
                            jugada z = jugada(r, minasAdyacentes(t, r));
                            j.push_back(z); // Agrego posiciones finales del camino libre (con minas adyacentes)
                        }
                    }
                }
                jugarPlus(t, b, q, j);
                // El peor caso de todos es descubrir el tablero entero de una sola jugada (por ejemplo, si todos tienen 0 minas adyacentes).
                // Es decir, cuando ejecutamos el primer if, el cual tiene un coste de h, debemos ejecutar el segundo if (también coste h)
                // seguido del llamado recursivo a jugarPlus hasta el último llamado a la función (O(h*h + h*jugarPlus)),
                // el cual tendrá coste h ya que estarán todas las posiciones jugadas y no se entra al primer if, ya que,
                // al ser un llamado recursivo,
                // coloca al final de la secuencia de jugadas a la posición q descubierta
                // que ya sabemos es una posición que forma parte del camino.
                // Hace esto hasta que no entra más al if dentro del segundo for.
                // Por lo tanto la complejidad nos quedará O(h*(h+h*(h+...h*h)), y este polinomio queda con h elevado n veces (con n el tamaño del tablero)
                // y queda con complejidad polinómica, pero simplificadamente quedaría algo con complejidad O(h^n).
            }
        }
    }
}

/******++++**************************** EJERCICIO sugerirAutomatico121 ***********+++***********************/
bool sugerirAutomatico121(tablero& t, banderitas& b, jugadas& j, pos& p) {
    // El algoritmo tiene complejidad de peor caso del orden O(m*n^2), para ser más exactos O((g+m)*n^2)
    // con m = j.size(), g = b.size() y n = t.size().
    bool hay = hayPosicionSugerible(j,b,t); // hayPosicionSugerible(j,b,t) tiene complejidad de peor caso O(m*n^2)
    if(hay){
        for(int i = 0; i < t.size(); i++){ // En el peor caso itera t.size() = n veces, y por cada iteración
            // vuelve a iterar n veces. Es decir, la complejidad en el peor caso es O((g+m)*n^2).
            for(int k = 0; k < t.size(); k++){ // En total, este ciclo tiene complejidad de peor caso del orden O(n*(g+m)).
                // En el peor caso itera t.size() = n veces. A su vez, cada
                // iteración de estas tiene complejidad de peor caso del orden O(g+m)+O(m) con m = j.size() y g = b.size().
                pos x = make_pair(i, k);
                if(esPosicionSinJugarYSinBanderita(x, j, b, t) && esAdyacenteA121(x, j)){
                    // La complejidad de peor caso de esta comparación es O(t+m)+O(m) con m = j.size() y g = b.size() (más justificación en auxiliares.cpp).
                    p = x;
                }
            }
        }
    }
    //cout << "Posición sugerida para jugar: " << "(" <<  p.first << "," << p.second << ")";
    return hay;
}
