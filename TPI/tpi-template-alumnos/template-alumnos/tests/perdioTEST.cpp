// Tests para la función perdio.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

// Tests para la función perdio.
// Ver el archovo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;
// ┌───┬───┬───┬───┬───┐
// │ * │ * │ 2 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 3 │ 3 │ 3 │ * │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 1 │ * │ 2 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 2 │ 3 │ 2 │ 1 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ * │ 2 │ * │ 1 │ 0 │
// └───┴───┴───┴───┴───┘
tablero t_perdio = {
        { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
        { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};
jugadas jugadasNoValidas = {
        jugada(pos(0, 0), 1),jugada(pos(0, 1), 1),
        jugada(pos(1, 3), 0),jugada(pos(2, 1), 0),jugada(pos(4, 0), 0),
        jugada(pos(4, 2), 0)
};

jugadas jugadasReValidas= {
        jugada(pos(2, 3), 1),jugada(pos(2, 4), 1),jugada(pos(3, 0), 2),jugada(pos(3, 1), 3),jugada(pos(3, 2), 2),jugada(pos(3, 3), 1),jugada(pos(3, 4), 0),
        jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),

};
TEST(perdioTEST, noGano){
    jugadas j = jugadasNoValidas;
    ASSERT_TRUE(perdio(t_perdio, j));
}

TEST(perdioTEST, noPerdio){
    jugadas j= jugadasReValidas;
    ASSERT_FALSE(perdio(t_perdio,j));
}

// ┌───┬───┬───┬───┬───┐
// │ 1 │ 2 │ 2 │ 1 │ * │
// ├───┼───┼───┼───┼───┤
// │ 2 │ * │ * │ 2 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ * │ 2 │ 3 │ 2 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 2 │ 3 │ 2 │ * │ 2 │
// ├───┼───┼───┼───┼───┤
// │ * │ 1 │ 1 │ 2 │ * │
// └───┴───┴───┴───┴───┘
tablero t_perdio2 = {
        { cVACIA,  cVACIA,  cVACIA, cVACIA, cMINA },
        { cVACIA, cMINA, cMINA, cVACIA,  cVACIA },
        { cMINA, cVACIA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cMINA, cVACIA },
        { cMINA,  cVACIA, cVACIA,  cVACIA, cMINA },
};
jugadas jugadasNoValidas2 = {
        jugada(pos(0, 4), 0),jugada(pos(1, 2), 1),
        jugada(pos(2, 0), 1),jugada(pos(3, 3), 1),jugada(pos(4, 0), 0),
        jugada(pos(4, 4), 1)
};
jugadas jugadasReValidas2 = {
        jugada(pos(0, 0), 1),jugada(pos(1, 0), 1),
        jugada(pos(2, 4), 1),jugada(pos(1, 4), 1),jugada(pos(4, 1), 1),
        jugada(pos(3, 0), 2)
};
TEST(perdioTEST, noGano2){
    jugadas j = jugadasNoValidas2;
    ASSERT_TRUE(perdio(t_perdio2,j));
}

TEST(perdioTEST, noPerdio2){
    jugadas j=jugadasReValidas2;
    ASSERT_FALSE(perdio(t_perdio2,j));
}