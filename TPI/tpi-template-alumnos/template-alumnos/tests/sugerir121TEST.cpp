// Tests para la función sugerir121.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;


// ┌───┬───┬───┬───┬───┐
// │ * │ * │ 2 │ * │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 2 │ 2 │ 3 │ 2 │ 2 │
// ├───┼───┼───┼───┼───┤
// │ 0 │ 0 │ 1 │ * │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 1 │ 2 │ 1 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ * │ 2 │ * │ 1 │ 0 │
// └───┴───┴───┴───┴───┘
tablero t_121 = {
        { cMINA,  cMINA,  cVACIA, cMINA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
        { cVACIA, cVACIA,  cVACIA, cMINA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};
jugadas jugadasValidas121 = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 2),jugada(pos(1, 1), 2),jugada(pos(1, 2), 3),jugada(pos(1, 4), 2),
        jugada(pos(2, 0), 0),jugada(pos(2, 1), 0),jugada(pos(2, 2), 1),jugada(pos(2, 4), 1),
        jugada(pos(3, 0), 1),jugada(pos(3, 1), 2),jugada(pos(3, 2), 1),jugada(pos(3, 3), 1),jugada(pos(3, 4), 1),
        jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
};
banderitas banderitasPuestas121 = {
        pos(0,0), pos(0,1), pos(0,3),
        pos(2,3),
        pos(4,0),pos(4,2)
};
TEST(sugerir121TEST, hay121HorizontalYVerticalYDevuelveCualquieraYNoMarquePosicionSegura){
    banderitas b = banderitasPuestas121;
    jugadas j = jugadasValidas121;
    pos p = make_pair(1,1);
    ASSERT_TRUE(sugerirAutomatico121(t_121, b, j, p));
    ASSERT_EQ(p,pos(4,1));
}
banderitas banderitasPuestas121ConUnaPosicionSeguraMarcada = {
        pos(0,0), pos(0,1), pos(0,3),
        pos(2,3),
        pos(4,0),pos(4,1),pos(4,2)
};
TEST(sugerir121TEST, hay121HorizontalYVerticalPeroMarqueUnaPosicionSegura){
    banderitas b = banderitasPuestas121ConUnaPosicionSeguraMarcada;
    jugadas j = jugadasValidas121;
    pos p = make_pair(1,1);
    ASSERT_TRUE(sugerirAutomatico121(t_121, b, j, p)); // True porque debería devolver el vertical ya que marco la posición segura horizontal.
    ASSERT_EQ(p,pos(1,3));
}
banderitas banderitasPuestas121ConTodasPosicionesSegurasMarcadas = {
        pos(0,0), pos(0,1), pos(0,3),
        pos(1,3),
        pos(2,3),
        pos(4,0),pos(4,1),pos(4,2)
};
TEST(sugerir121TEST, hay121HorizontalYVerticalPeroMarqueTodasPosicionesSeguras){
    banderitas b = banderitasPuestas121ConTodasPosicionesSegurasMarcadas;
    jugadas j = jugadasValidas121;
    pos p = make_pair(1,1);
    ASSERT_FALSE(sugerirAutomatico121(t_121, b, j, p));
    ASSERT_EQ(p,pos(1,1));
}
jugadas jugadasValidas121ConUnaPosicionSeguraJugada = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 2),jugada(pos(1, 1), 2),jugada(pos(1, 2), 3),jugada(pos(1, 3), 2),jugada(pos(1, 4), 2),
        jugada(pos(2, 0), 0),jugada(pos(2, 1), 0),jugada(pos(2, 2), 1),jugada(pos(2, 4), 1),
        jugada(pos(3, 0), 1),jugada(pos(3, 1), 2),jugada(pos(3, 2), 1),jugada(pos(3, 3), 1),jugada(pos(3, 4), 1),
        jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
};
TEST(sugerir121TEST, hay121HorizontalYVerticalPeroJugueUnaPosicionSegura){
    banderitas b = banderitasPuestas121;
    jugadas j = jugadasValidas121ConUnaPosicionSeguraJugada;
    pos p = make_pair(1,1);
    ASSERT_TRUE(sugerirAutomatico121(t_121, b, j, p));
    ASSERT_EQ(p,pos(4,1));
}
jugadas jugadasValidas121ConTodasLasPosicionesSegurasJugadas = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 2),jugada(pos(1, 1), 2),jugada(pos(1, 2), 3),jugada(pos(1, 3), 2),jugada(pos(1, 4), 2),
        jugada(pos(2, 0), 0),jugada(pos(2, 1), 0),jugada(pos(2, 2), 1),jugada(pos(2, 4), 1),
        jugada(pos(3, 0), 1),jugada(pos(3, 1), 2),jugada(pos(3, 2), 1),jugada(pos(3, 3), 1),jugada(pos(3, 4), 1),
        jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
};
TEST(sugerir121TEST, hay121HorizontalYVerticalPeroJugueTodasPosicionesSeguras){
    banderitas b = banderitasPuestas121;
    jugadas j = jugadasValidas121ConTodasLasPosicionesSegurasJugadas;
    pos p = make_pair(1,1);
    ASSERT_FALSE(sugerirAutomatico121(t_121, b, j, p));
    ASSERT_EQ(p,pos(1,1));
}



// ┌───┬───┬───┬───┬───┐
// │ * │ * │ 2 │ * │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 2 │ 2 │ 3 │ 2 │ 2 │
// ├───┼───┼───┼───┼───┤
// │ 0 │ 0 │ 1 │ * │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 1 │ 1 │ 1 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ * │ 1 │ 0 │ 0 │ 0 │
// └───┴───┴───┴───┴───┘
tablero t_121_vertical = {
        { cMINA,  cMINA,  cVACIA, cMINA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
        { cVACIA, cVACIA,  cVACIA, cMINA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cVACIA,  cVACIA, cVACIA },
};
jugadas jugadasValidas121_vertical = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 2),jugada(pos(1, 1), 2),jugada(pos(1, 2), 3),jugada(pos(1, 4), 2),
        jugada(pos(2, 0), 0),jugada(pos(2, 1), 0),jugada(pos(2, 2), 1),jugada(pos(2, 4), 1),
        jugada(pos(3, 0), 1),jugada(pos(3, 1), 1),jugada(pos(3, 2), 1),jugada(pos(3, 3), 1),jugada(pos(3, 4), 1),
        jugada(pos(4, 1), 1),jugada(pos(4, 2), 0),jugada(pos(4, 3), 0),jugada(pos(4, 4), 0),
};
banderitas banderitasPuestas121_vertical = {
        pos(0,0), pos(0,1), pos(0,3),
        pos(2,3),
        pos(4,0),pos(4,2)
};
TEST(sugerir121TEST, hay121VerticalYNoMarquePosicionSegura){
    banderitas b = banderitasPuestas121_vertical;
    jugadas j = jugadasValidas121_vertical;
    pos p = make_pair(3,1);
    ASSERT_TRUE(sugerirAutomatico121(t_121_vertical, b, j, p));
    ASSERT_EQ(p,pos(1,3));
}
banderitas banderitasPuestas121_verticalMarcada = {
        pos(0,0), pos(0,1), pos(0,3),
        pos(1,3),
        pos(2,3),
        pos(4,0),pos(4,2)
};
TEST(sugerir121TEST, hay121VerticalYMarquePosicionSegura){
    banderitas b = banderitasPuestas121_verticalMarcada;
    jugadas j = jugadasValidas121_vertical;
    pos p = make_pair(3,1);
    ASSERT_FALSE(sugerirAutomatico121(t_121_vertical, b, j, p));
    ASSERT_EQ(p,pos(3,1));
}



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
tablero t_121_horizontal = {
        { cMINA,  cMINA,  cVACIA, cMINA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
        { cVACIA, cVACIA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};
jugadas jugadasValidas121_horizontal = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 2),jugada(pos(1, 1), 2),jugada(pos(1, 2), 2),jugada(pos(1, 3), 1),jugada(pos(1, 4), 1),
        jugada(pos(2, 0), 0),jugada(pos(2, 1), 0),jugada(pos(2, 2), 0),jugada(pos(2, 3), 0),jugada(pos(2, 4), 0),
        jugada(pos(3, 0), 1),jugada(pos(3, 1), 2),jugada(pos(3, 2), 1),jugada(pos(3, 3), 1),jugada(pos(3, 4), 0),
        jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
};
banderitas banderitasPuestas121_horizontal = {
        pos(0,0), pos(0,1), pos(0,3),
        pos(2,3),
        pos(4,0),pos(4,2)
};
TEST(sugerir121TEST, hay121HorizontalYNoMarquePosicionSegura){
    banderitas b = banderitasPuestas121_horizontal;
    jugadas j = jugadasValidas121_horizontal;
    pos p = make_pair(3,1);
    ASSERT_TRUE(sugerirAutomatico121(t_121_horizontal, b, j, p));
    ASSERT_EQ(p,pos(4,1));
}
banderitas banderitasPuestas121_horizontalMarcada = {
        pos(0,0), pos(0,1), pos(0,3),
        pos(2,3),
        pos(4,0),pos(4,1),pos(4,2)
};
TEST(sugerir121TEST, hay121HorizontalYMarquePosicionSegura){
    banderitas b = banderitasPuestas121_horizontalMarcada;
    jugadas j = jugadasValidas121_horizontal;
    pos p = make_pair(3,1);
    ASSERT_FALSE(sugerirAutomatico121(t_121_horizontal, b, j, p));
    ASSERT_EQ(p,pos(3,1));
}




// ┌───┬───┬───┬───┬───┐
// │ * │ * │ 2 │ * │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 2 │ 2 │ 2 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 0 │ 0 │ 0 │ 0 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ 0 │ 1 │ 1 │ 1 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ 0 │ 1 │ * │ 1 │ 0 │
// └───┴───┴───┴───┴───┘
tablero t_sin121 = {
        { cMINA,  cMINA,  cVACIA, cMINA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA,  cVACIA },
        { cVACIA, cVACIA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cVACIA,  cVACIA, cMINA,  cVACIA, cVACIA },
};
jugadas jugadasValidasSin121 = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 2),jugada(pos(1, 1), 2),jugada(pos(1, 2), 2),jugada(pos(1, 3), 1),jugada(pos(1, 4), 1),
        jugada(pos(2, 0), 0),jugada(pos(2, 1), 0),jugada(pos(2, 2), 0),jugada(pos(2, 3), 0),jugada(pos(2, 4), 0),
        jugada(pos(3, 0), 0),jugada(pos(3, 1), 1),jugada(pos(3, 2), 1),jugada(pos(3, 3), 1),jugada(pos(3, 4), 0),
        jugada(pos(4, 0), 0),jugada(pos(4, 1), 1),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
};
banderitas banderitasPuestasSin121 = {
        pos(0,0), pos(0,1), pos(0,3),
        pos(2,3),
        pos(4,0),pos(4,2)
};
TEST(sugerir121TEST, noHay121){
    banderitas b = banderitasPuestasSin121;
    jugadas j = jugadasValidasSin121;
    pos p = make_pair(1,1);
    ASSERT_FALSE(sugerirAutomatico121(t_sin121, b, j, p));
    ASSERT_EQ(p,pos(1,1));
}