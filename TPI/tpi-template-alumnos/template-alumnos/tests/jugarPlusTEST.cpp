// Tests para la función jugarPlus.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

// ┌───┬───┬───┬───┬───┐
// │ * │ * │ 2 │ * │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 2 │ 2 │ 2 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 0 │ 0 │ 0 │ 0 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ 1 │ 2 │ 1 │ 1 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ * │ 2 │ * │ 1 │ 0 │
// └───┴───┴───┴───┴───┘
tablero t_jugarPlus = {
        { cMINA,  cMINA,  cVACIA, cMINA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
        { cVACIA, cVACIA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};
jugadas j0_1 = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
};
jugadas j_1 = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1,0),2),jugada(pos(1,1),2),jugada(pos(1,2),2),jugada(pos(1,3),1),jugada(pos(1,4),1),
        jugada(pos(2, 0), 0),jugada(pos(2, 1), 0),jugada(pos(2, 2), 0),jugada(pos(2, 3), 0),jugada(pos(2,4),0),
        jugada(pos(3,0),1),jugada(pos(3,1),2),jugada(pos(3,2),1),jugada(pos(3,3),1),jugada(pos(3, 4), 0),
        jugada(pos(4, 3), 1),jugada(pos(4, 4), 0)
};
banderitas b = {
        pos(0,0), pos(0,1), pos(0,3),
        pos(4,0),pos(4,2)
};

TEST(jugarPlusTEST, noHayPosicionesSinMinasAdyacentesMarcadasComoBanderita){
    pos p = pos(1,0);
    jugarPlus(t_jugarPlus,b,p,j0_1);
    ASSERT_TRUE(mantieneJugadas(j0_1,j_1) && jugadasNoRepetidas(j0_1) && incluyeJugadaActual(t_jugarPlus,j0_1,p));
    ASSERT_TRUE(esPermutacionDeJugadas(j0_1,j_1));
}

jugadas j0_2 = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
};
jugadas j1_2 = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1,0),2),jugada(pos(1,1),2),jugada(pos(1,2),2),jugada(pos(1,3),1),
        jugada(pos(2, 0), 0),jugada(pos(2, 1), 0),jugada(pos(2, 2), 0),
        jugada(pos(3,0),1),jugada(pos(3,1),2),jugada(pos(3,2),1),jugada(pos(3,3),1)
};
banderitas b_2 = {
        pos(0,0), pos(0,1), pos(0,3),
        pos(2,3),
        pos(4,0),pos(4,2)
};
TEST(jugarPlusTEST, hayPosicionesSinMinasAdyacentesMarcadasComoBanderita){
    pos p = pos(1,0);
    jugarPlus(t_jugarPlus,b_2,p,j0_2);
    ASSERT_TRUE(mantieneJugadas(j0_2,j1_2) && jugadasNoRepetidas(j0_2) && incluyeJugadaActual(t_jugarPlus,j0_2,p));
    ASSERT_TRUE(esPermutacionDeJugadas(j0_2,j1_2));
}

jugadas j0_3 = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
};
jugadas j1_3 = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1,0),2),jugada(pos(1,1),2),jugada(pos(1,2),2),jugada(pos(1,3),1),jugada(pos(1,4),1),
        jugada(pos(2, 0), 0),jugada(pos(2, 1), 0),jugada(pos(2, 2), 0),jugada(pos(2, 3), 0),jugada(pos(2,4),0),
        jugada(pos(3,0),1),jugada(pos(3,1),2),jugada(pos(3,2),1),jugada(pos(3,3),1),jugada(pos(3, 4), 0),
        jugada(pos(4, 3), 1),jugada(pos(4, 4), 0)
};
banderitas b_3 = {};

TEST(jugarPlusTEST, empiezoDesdePosicionSinMinasAdyacentesYSinBanderitasMarcadas){
    pos p = pos(2,2);
    jugarPlus(t_jugarPlus,b_3,p,j0_3);
    ASSERT_TRUE(mantieneJugadas(j0_3,j1_3) && jugadasNoRepetidas(j0_3) && incluyeJugadaActual(t_jugarPlus,j0_3,p));
    ASSERT_TRUE(esPermutacionDeJugadas(j0_3,j1_3));
}


jugadas j0_4 = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1)
};
jugadas j1_4 = {
        jugada(pos(0, 2), 2),jugada(pos(0, 3), 0),jugada(pos(0, 4), 1)
};
banderitas b_4 = {};

TEST(jugarPlusTEST, juegoPosicionConMina){
    pos p = pos(0,3);
    jugarPlus(t_jugarPlus,b_4,p,j0_4);
    ASSERT_TRUE(mantieneJugadas(j0_4,j1_4) && jugadasNoRepetidas(j0_4) && incluyeJugadaActual(t_jugarPlus,j0_4,p));
    ASSERT_TRUE(esPermutacionDeJugadas(j0_4,j1_4));
}

// ┌───┬───┬───┬───┬───┐
// │ 0 │ 0 │ 0 │ 0 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ 0 │ 1 │ 1 │ 1 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ 0 │ 1 │ * │ 1 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ 0 │ 1 │ 1 │ 1 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ 0 │ 0 │ 0 │ 0 │ 0 │
// └───┴───┴───┴───┴───┘
tablero t_jugarPlus_2 = {
        { cVACIA,  cVACIA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
        { cVACIA, cVACIA,  cMINA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cVACIA,  cVACIA, cVACIA,  cVACIA, cVACIA },
};
jugadas j0_5 = {};
jugadas j1_5 = {
        jugada(pos(0, 0), 0),jugada(pos(0, 1), 0),jugada(pos(0, 2), 0),jugada(pos(0, 3), 0),jugada(pos(0, 4), 0),
        jugada(pos(1, 0), 0),jugada(pos(1, 1), 1),jugada(pos(1, 2), 1),jugada(pos(1, 3), 1),jugada(pos(1, 4), 0),
        jugada(pos(2, 0), 0),jugada(pos(2, 1), 1),jugada(pos(2, 3), 1),jugada(pos(2, 4), 0),
        jugada(pos(3, 0), 0),jugada(pos(3, 1), 1),jugada(pos(3, 2), 1),jugada(pos(3, 3), 1),jugada(pos(3, 4), 0),
        jugada(pos(4, 0), 0),jugada(pos(4, 1), 0),jugada(pos(4, 2), 0),jugada(pos(4, 3), 0),jugada(pos(4, 4), 0),
};
banderitas b_5 = {pos(2,2)};

TEST(jugarPlusTEST, primeraJugada){
    pos p = pos(0,0);
    jugarPlus(t_jugarPlus_2,b_5,p,j0_5);
    ASSERT_TRUE(mantieneJugadas(j0_5,j1_5) && jugadasNoRepetidas(j0_5) && incluyeJugadaActual(t_jugarPlus_2,j0_5,p));
    ASSERT_TRUE(esPermutacionDeJugadas(j0_5,j1_5));
}