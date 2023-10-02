//
// Este archivo contiene las definiciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con las 
// declaraciones de auxiliares.h
//

#include <stdio.h>
#include <iostream>
#include <utility>


#include "definiciones.h"
#include "auxiliares.h"
#include "ejercicios.h"

using namespace std;

bool coordenadaValida(int c, int n){
    return ((0<=c) && (c<n));
}

bool esAdyacenteValida(pos p, int i, int k, tablero &t){
    bool res = false;
    if (coordenadaValida(p.first + i, t.size()) && coordenadaValida(p.second + k, t[0].size()) && (i!=0 || k!=0)){
        res = true;
    }
    return res;
}


// ##############################################################################################################################################################


bool esPermutacion(banderitas &b1, banderitas &b2){
    bool mismoTamano = (b1.size() == b2.size());
    bool banderitasAparecenMismasVeces = true;
    for(int i=0;i<b1.size();i++){
        int apariciones_b1 = 1;
        int apariciones_b2 = 0;
        for(int k = 0; k < b2.size(); k++){
            if(b2[k] == b1[i]){
                apariciones_b2++;
            }
        }
        if(apariciones_b1 != apariciones_b2){
            banderitasAparecenMismasVeces = false;
        }
    }
    bool permutacion = mismoTamano && banderitasAparecenMismasVeces;
    return permutacion;
}

bool plantaBanderita(pos p_plantar, banderitas &b, banderitas &b0){
    bool agregaPosicion = esBanderita(p_plantar,b);
    bool todaBanderaDeB0EstaEnB = true;
    for(int i=0;i<b0.size();i++){
        int apariciones_b0 = 1;
        int apariciones_b = 0;
        for(int k=0;k<b.size();k++){
            if(b0[i] == b[i]){
                apariciones_b++;
            }
        }
        if(apariciones_b0 > apariciones_b){
            todaBanderaDeB0EstaEnB = false;
        }
    }
    bool res = (b.size() == b0.size()+1) && agregaPosicion && todaBanderaDeB0EstaEnB;
    return res;
}

bool sacaBanderita(pos p_sacar, banderitas &b, banderitas &b0){
    bool eliminaPosicion = true;
    for(int i = 0;i<b0.size();i++){
        if(p_sacar!=b0[i] && !esBanderita(b0[i],b)){
            eliminaPosicion = false;
        }
    }
    bool res = (b.size() == b0.size()-1) && eliminaPosicion;
    return res;
}


// ##############################################################################################################################################################

bool hayMinaEnPosicion(pos p, tablero &t){
    bool hayMina = false;
    if(t[p.first][p.second]){
        hayMina = true;
    }
    return hayMina;
}

bool juegoPerdido(tablero &t, jugadas &j){
    bool perdio=false;
    for(int i=0;i<j.size();i++){ // Itera en el peor caso m veces, con m = j.size().
        if(hayMinaEnPosicion(j[i].first,t)){ // Cada comparación y acceso a la secuencia tiene tiempo constante O(1)
            perdio = true;
        }
    }
    return perdio;
}


// ##############################################################################################################################################################


bool posicionValida(pos p, int n){
    bool res = (coordenadaValida(p.first,n) && coordenadaValida(p.second,n));
    return res;
}

bool fueJugada(pos p, jugadas &j){
    // Complejidad de peor caso es O(m) con m = j.size(), ya que en peor caso itera en
    // toda la secuencia j buscando si j[i] == p.
    bool res = false;
    for(int i = 0; i<j.size(); i++){
        if((j[i]).first == p){
            res = true;
        }
    }
    return res;
}

bool juegoGanado(tablero &t, jugadas &j){
    bool res = true;
    for(int i = 0; i<t.size(); i++){ // A partir de acá llamaremos n = t.size(). Este loop itera n veces en peor caso.
        for(int k = 0; k<t.size(); k++){ // Este loop itera n veces por iteración en peor caso del loop anterior.
            pos p = make_pair(i,k);
            if(posicionValida(p,t.size()) &&
            ((!t[i][k] && !fueJugada(p, j)) || // Caso en el que todavía tiene posiciones por jugar.
            (t[i][k] && fueJugada(p, j))) // Caso en el que toca una mina.
            ){
                res = false; // En la guarda y en esta línea, solo hace comparaciones, que consideramos operaciones de tiempo O(1)
            }
        } // Este loop tiene complejidad O(n)
    } // Este loop tiene complejidad O(n*n) = O(n^2), puesto que recorre n veces en el peor caso la secuencia por cada iteración del anterior loop, el cual también itera n veces en el peor caso.
    return res;
}


// ##############################################################################################################################################################


bool esPermutacionDeJugadas(jugadas &j1, jugadas &j2){
    bool mismoTamano = (j1.size() == j2.size());
    bool jugadasAparecenMismasVeces = true;
    for(int i=0;i<j1.size();i++){
        int apariciones_j1 = 1;
        int apariciones_j2 = 0;
        for(int k = 0; k < j2.size(); k++){
            if(j1[i] == j2[k]){
                apariciones_j2++;
            }
        }
        if(apariciones_j1 != apariciones_j2){
            jugadasAparecenMismasVeces = false;
        }
    }
    bool permutacion = mismoTamano && jugadasAparecenMismasVeces;
    return permutacion;
}

bool mantieneJugadas(jugadas &j0, jugadas &js){
    bool mantiene = true;
    for(int i = 0; i<j0.size(); i++){
        int apariciones_j0_en_js = 0;
        for(int k = 0; k<js.size(); k++){
            if(js[k] == j0[i]){
                apariciones_j0_en_js++;
            }
        }
        if(apariciones_j0_en_js == 0){
            mantiene = false;
            //cout << j0[i].first.first << "," << j0[i].first.second;
        }
    }
    return mantiene;
}

bool jugadasNoRepetidas(jugadas &j){
    bool noRepite = true;
    for(int i = 0; i<j.size(); i++) {
        int apariciones = 0;
        for(int k = 0; k<j.size(); k++){
            if(j[i] == j[k]){
                apariciones++;
            }
        }
        if (apariciones > 1) {
            noRepite = false;
        }
    }
    return noRepite;
}

bool incluyeJugadaActual(tablero &t, jugadas &j, pos p){
    bool incluye = false;
    for(int i = 0; i<j.size(); i++){
        jugada c = jugada(p,minasAdyacentes(t,p));
        if(c == j[i]){
            incluye = true;
        }
    }
    return incluye;
}

/*
bool descubreSoloPosicionJugada(pos p, jugadas &j, jugadas &j0, tablero &t){
    bool res = (j.size() == j0.size() + 1) && ((t[p.first][p.second]==true) || (minasAdyacentes(t,p) > 0));
    return res;
}

bool hayCaminoLibre(pos posInicial, pos posFinal, jugadas &j0, banderitas &b, tablero &t){
    shdfatdahdhajtjdh
}

bool esDescubiertaAuto(pos q, pos p, jugadas &j, jugadas &j0, banderitas &b, tablero &t){
    bool res = posicionValida(q,t.size()) && hayCaminoLibre(p,q,j0,b,t);
    return res;
}

bool incluyeDescubiertasAutomaticamente(pos p, jugadas &j, jugadas &j0, banderitas &b, tablero &t){
    hskhfdskhafdsahk
}

bool sonPosicionesAdyacentes(pos p, pos q){
    bool res = (p!=q) && (abs(p.first - q.first) <= 1) && (abs(p.second - q.second) <= 1);
    return res;
}

int descubiertasAutoDesde(pos p, jugadas &j0, jugadas &j, banderitas &b, tablero &t){
    int suma = 0;
    for(int i = 0; i<t.size(); i++){
        int subsuma = 0;
        for(int k = 0; k<t.size(); k++){
            pos temp = pos(i,k);
            if(esDescubiertaAuto(temp,p,j,j0,b,t)){
                subsuma++;
            }
        }
        suma = suma + subsuma;
    }
    return suma;
}

bool descubreMultiplesPosiciones(pos p, jugadas &j, jugadas &j0, banderitas &b, tablero &t){
    bool res =
            !(t[p.first][p.second] == true) && (minasAdyacentes(t,p) == 0) &&
            incluyeDescubiertasAutomaticamente(p,j,j0,b,t) &&
            (j.size() == j0.size() + 1 + descubiertasAutoDesde(p,j0,j,b,t));
    return res;
}

bool soloAgregaPosicionesDescubiertas(pos p, jugadas &j, jugadas &j0, banderitas &b, tablero &t){
    bool res = descubreSoloPosicionJugada(p,j,j0,t) || descubreMultiplesPosiciones(p,j,j0,b,t);
    return res;
}
*/
// ##############################################################################################################################################################


bool esBanderita(pos p, banderitas &b){
    // Complejidad de peor caso de orden O(g)
    bool bandera = false;
    for(int i = 0; i<b.size(); i++){ // Recorre toda la secuencia de g elementos, con g = b.size().
        if(b[i] == p){
            bandera = true;
        }
    }
    return bandera;
}

bool esPosicionSinJugarYSinBanderita(pos p, jugadas &j, banderitas &b, tablero &t){
    //  Complejidad de peor caso del orden O(g+m) pues efectúa una comparación de orden O(g) y una de orden O(m)
    bool esPosicion = false;
    // Complejidad de peor caso de posicionValida es del orden O(1).
    // Complejidad de peor caso de esBanderita es del orden O(g) con g = b.size()
    // Complejidad de peor caso de fueJugada es del orden O(m) con m = j.size()
    if(posicionValida(p,t.size()) &&
    !fueJugada(p,j) && !esBanderita(p,b)){ // O(m) (fueJugada) + O(g) (esBanderita)
        esPosicion = true;
    }
    return esPosicion;
}

bool es121Horizontal(pos p, jugadas &j){
    // Complejidad temporal de peor caso es O(3*m) = O(m) con m = j.size()
    bool posicionDeArribaCumple = false;
    pos posDeArriba = make_pair(p.first,p.second-1);
    jugada jugadaAEvaluarArriba = make_pair((posDeArriba),1);
    for(int i = 0; i<j.size(); i++){
        if(j[i] == jugadaAEvaluarArriba){ // En el peor caso itera toda la secuencia j, es decir itera m veces.
            posicionDeArribaCumple = true;
        }
    }
    ////////////////////////////////////////////////
    bool posicionDelMedioCumple = false;
    pos posDelMedio = p;
    jugada jugadaAEvaluarMedio = make_pair((posDelMedio),2);
    for(int i = 0; i<j.size(); i++){
        if(j[i] == jugadaAEvaluarMedio){ // En el peor caso itera toda la secuencia j, es decir itera m veces.
            posicionDelMedioCumple = true;
        }
    }
    ///////////////////////////////////////////////
    bool posicionDeAbajoCumple = false;
    pos posDeAbajo = make_pair(p.first,p.second+1);
    jugada jugadaAEvaluarAbajo = make_pair((posDeAbajo),1);
    for(int i = 0; i<j.size(); i++){
        if(j[i] == jugadaAEvaluarAbajo){ // En el peor caso itera toda la secuencia j, es decir itera m veces.
            posicionDeAbajoCumple = true;
        }
    }
    //////////////////////////////////////////////
    bool hay121Horizontal = posicionDeArribaCumple && posicionDelMedioCumple && posicionDeAbajoCumple;
    return hay121Horizontal;
}

bool es121Vertical(pos p, jugadas &j){
    // Complejidad temporal de peor caso es O(3*m) = O(m) con m = j.size()
    bool posicionIzquierdaCumple = false;
    pos posIzquierda = make_pair(p.first-1,p.second);
    jugada jugadaAEvaluarIzquierda = make_pair((posIzquierda),1);
    for(int i = 0; i<j.size(); i++){ // En el peor caso itera toda la secuencia j, es decir itera m veces.
        if(j[i] == jugadaAEvaluarIzquierda){
            posicionIzquierdaCumple = true;
        }
    }
    ////////////////////////////////////////////////
    bool posicionDelMedioCumple = false;
    pos posDelMedio = p;
    jugada jugadaAEvaluarMedio = make_pair((posDelMedio),2);
    for(int i = 0; i<j.size(); i++){ // En el peor caso itera toda la secuencia j, es decir itera m veces.
        if(j[i] == jugadaAEvaluarMedio){
            posicionDelMedioCumple = true;
        }
    }
    ///////////////////////////////////////////////
    bool posicionDerechaCumple = false;
    pos posDerecha = make_pair(p.first+1,p.second);
    jugada jugadaAEvaluarDerecha = make_pair((posDerecha),1);
    for(int i = 0; i<j.size(); i++){ // En el peor caso itera toda la secuencia j, es decir itera m veces.
        if(j[i] == jugadaAEvaluarDerecha){
            posicionDerechaCumple = true;
        }
    }
    //////////////////////////////////////////////
    bool hay121Horizontal = posicionIzquierdaCumple && posicionDelMedioCumple && posicionDerechaCumple;
    return hay121Horizontal;
}

bool esAdyacenteA121(pos p, jugadas &j){
    /* Complejidad temporal de peor caso del orden O(m) (en el peor caso, es121horizontal
     * así como es121vertical tienen complejidad O(3*m), o lo que es lo mismo O(m) con m = j.size() */
    pos posHorizontal1 = make_pair(p.first-1,p.second);
    pos posHorizontal2 = make_pair(p.first+1,p.second);
    pos posVertical1 = make_pair(p.first,p.second-1);
    pos posVertical2 = make_pair(p.first,p.second+1);
    bool esAdyacente = // Cada comparación tiene complejidad de peor caso del orden O(m) con m = j.size()
            (es121Horizontal(posHorizontal1, j) ||
            es121Horizontal(posHorizontal2, j) ||
            es121Vertical(posVertical1, j) ||
            es121Vertical(posVertical2, j));
    return esAdyacente;
}

bool hayPosicionSugerible(jugadas &j, banderitas &b, tablero &t){
    // Complejidad temporal de peor caso es del orden O(m*n^2) con m = j.size() y n = t.size()
    bool posicionSugerible = false;
    for(int i = 0; i<t.size(); i++){ // En el peor caso itera t.size() = n veces, y por cada iteración
        // vuelve a iterar n veces. Es decir, en el peor caso itera m*n^2 veces (O(m*n^2))
        for(int k = 0; k<t.size(); k++){ // En el peor caso itera t.size() = n veces. A su vez, cada
            // iteración de estas tiene complejidad de peor caso del orden O(m) con m = j.size().
            // En total, este ciclo tiene complejidad de peor caso del orden O(n*m).
            pos p  = make_pair(i,k);
            if(esPosicionSinJugarYSinBanderita(p,j,b,t) && esAdyacenteA121(p,j)){
                /*
 * Si bien la función esPosicionSinJugarYSinBanderita(p,j,b,t) tiene complejidad O(g+m), la complejidad
 * de peor caso de esAdyacenteA121(p,j) es del orden de O(m), con m = j.size() ya que por cada comparación que
 * hace para comparar si es121horizontal(p,j) o es121Vertical(p,j) tiene complejidad temporal de peor caso
 * del orden O(m) y esta es la complejidad temporal de cada comparación.
 */
                posicionSugerible = true;
            }
        }
    }
    return posicionSugerible;
}


// ##############################################################################################################################################################


