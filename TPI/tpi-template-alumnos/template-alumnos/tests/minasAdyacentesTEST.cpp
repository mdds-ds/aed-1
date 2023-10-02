// Tests para la función minasAdyacentes.
// Ver el archivo README.md para ayuda

#include "../ejercicios.h"
#include "../auxiliares.h"
#include "../definiciones.h"
#include "gtest/gtest.h"

using namespace std;

tablero t_minas = {
        { cMINA,  cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
        { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};

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

pos p = make_pair(1,0);
TEST(minasAdyacentesTEST, posicionUnoCero) {
    ASSERT_EQ(minasAdyacentes(t_minas,p),3);
}

pos p1 = make_pair(5,5);
TEST(minasAdyacentesTEST, noHayMinas) {
    ASSERT_EQ(minasAdyacentes(t_minas,p1),0);
}

pos p2 = make_pair(0,1);
TEST(minasAdyacentesTEST, posicionCeroUnoConMina) {
    ASSERT_EQ(minasAdyacentes(t_minas,p2),1);
}

pos p3 = make_pair(2,4);
TEST(minasAdyacentesTEST, posicionLimiteHorizontal) {
    ASSERT_EQ(minasAdyacentes(t_minas,p3),1);
}

pos p4 = make_pair(0,2);
TEST(minasAdyacentesTEST, posicionLimiteVertical) {
    ASSERT_EQ(minasAdyacentes(t_minas,p4),2);
}