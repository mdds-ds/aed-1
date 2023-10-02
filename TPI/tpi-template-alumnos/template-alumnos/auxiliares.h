
//
// Este archivo contiene las declaraciones de las funciones auxiliares
// que ustedes necesiten implementar. Tienen que coincidir con el código
// de esas mismas funciones, que estará en auxiliares.cpp
//

#pragma once   // esta línea es para que el archivo se incluya una sola vez

#include "definiciones.h"

bool coordenadaValida(int c, int n);
bool esAdyacenteValida(pos p, int i, int j, tablero &t);
////////////////////////////////////////////////////////////////////////////////
bool estaEnBanderitas(pos p, banderitas &b);
bool sacaBanderita(pos p_sacar, banderitas &b, banderitas &b0);
bool plantaBanderita(pos p_plantar, banderitas &b, banderitas &b0);
bool esPermutacion(banderitas &b1, banderitas &b2);
////////////////////////////////////////////////////////////////////////////////
bool hayMinaEnPosicion(pos p, tablero &t);
bool juegoPerdido(tablero &t, jugadas &j);
////////////////////////////////////////////////////////////////////////////////
bool posicionValida(pos p, int n);
bool fueJugada(pos p, jugadas &j);
bool incluyeJugadaActual(tablero &t, jugadas &j, pos p);
bool juegoGanado(tablero &t, jugadas &j);
///////////////////////////////////////////////////////////////////////////////
bool mantieneJugadas(jugadas &j0, jugadas &js);
bool jugadasNoRepetidas(jugadas &j);
bool esPermutacionDeJugadas(jugadas &j1, jugadas &j2);
///////////////////////////////////////////////////////////////////////////////
bool esBanderita(pos p, banderitas &b);
bool esPosicionSinJugarYSinBanderita(pos p, jugadas &j, banderitas &b, tablero &t);
bool es121Horizontal(pos p, jugadas &j);
bool es121Vertical(pos p, jugadas &j);
bool esAdyacenteA121(pos p, jugadas &j);
bool hayPosicionSugerible(jugadas &j, banderitas &b, tablero &t);
