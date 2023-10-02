// Tests para la función cambiarBanderita.
// Ver el archovo README.md para ayuda


#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

// ┌───┬───┬───┬───┬───┐
// │ 1 │ * │ 2 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 2 │ 2 │ 3 │ * │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 1 │ * │ 2 │ 1 │ 1 │
// ├───┼───┼───┼───┼───┤
// │ 2 │ 3 │ 2 │ 1 │ 0 │
// ├───┼───┼───┼───┼───┤
// │ * │ 2 │ * │ 1 │ 0 │
// └───┴───┴───┴───┴───┘

tablero t_cambiar_Banderita = {
        { cVACIA,  cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cMINA,  cVACIA },
        { cVACIA, cMINA,  cVACIA, cVACIA, cVACIA },
        { cVACIA, cVACIA, cVACIA, cVACIA, cVACIA },
        { cMINA,  cVACIA, cMINA,  cVACIA, cVACIA },
};
jugadas jugadasValidas_cambiarBanderita = {
        jugada(pos(0, 2), 2),jugada(pos(0, 4), 1),
        jugada(pos(1, 0), 2),jugada(pos(1, 1), 2),jugada(pos(1, 2), 3),jugada(pos(1, 4), 1),
        jugada(pos(2, 0), 1),jugada(pos(2, 2), 2),jugada(pos(2, 3), 1),
        jugada(pos(3, 0), 2),jugada(pos(3, 1), 3),jugada(pos(3, 2), 2),jugada(pos(3, 3), 1),jugada(pos(3, 4), 0),
        jugada(pos(4, 1), 2),jugada(pos(4, 3), 1),jugada(pos(4, 4), 0),
};
banderitas b_ponerBanderita_antes={
        pos(0,0),pos(3,3),pos(4,4),pos(1,2),pos(3,2)
};

banderitas b_ponerBanderita_despues={
        pos(0,0),pos(3,3),pos(4,4),pos(1,2),pos(3,2),pos(2,4)
};
banderitas b_sacarBanderita_antes={
        pos(0,0),pos(3,3),pos(4,4),pos(0,2),pos(1,2),pos(3,2)
};
banderitas b_sacarBanderita_despues={
        pos(0,0),pos(3,3),pos(4,4),pos(1,2),pos(3,2)
};


TEST(cambiarBanderitaTEST, sacarBanderita){
    jugadas j = jugadasValidas_cambiarBanderita;
    pos p8 = pos(0,2);
    banderitas b0 = b_sacarBanderita_antes;
    cambiarBanderita(t_cambiar_Banderita,j,p8,b_sacarBanderita_antes);
    ASSERT_TRUE(esPermutacion(b_sacarBanderita_antes,b_sacarBanderita_despues));
    ASSERT_TRUE(sacaBanderita(p8,b_sacarBanderita_despues,b0));
}

TEST(cambiarBanderitaTEST, ponerBanderita){
    jugadas j1=jugadasValidas_cambiarBanderita;
    pos p9= pos(2,4);
    banderitas b0 = b_ponerBanderita_antes;
    cambiarBanderita(t_cambiar_Banderita,j1,p9,b_ponerBanderita_antes);
    ASSERT_EQ(b_ponerBanderita_antes,b_ponerBanderita_despues);
    ASSERT_TRUE(plantaBanderita(p9,b_ponerBanderita_antes,b0));
}


banderitas b_ponerBanderita_antes2={
        pos(0,0),pos(3,3),pos(4,4),pos(1,2),pos(3,2)
};

banderitas b_ponerBanderita_despues2={
        pos(0,0),pos(3,3),pos(4,4),pos(1,2),pos(3,2),pos(2,4)
};

TEST(cambiarBanderitaTEST, ponerYSacarBanderita){
    jugadas j1=jugadasValidas_cambiarBanderita;
    pos p9= pos(2,4);
    banderitas b0 = b_ponerBanderita_antes2;
    cambiarBanderita(t_cambiar_Banderita,j1,p9,b_ponerBanderita_antes2); // Poner banderita
    ASSERT_EQ(b_ponerBanderita_antes2,b_ponerBanderita_despues2);
    ASSERT_TRUE(plantaBanderita(p9,b_ponerBanderita_antes2,b0));
    banderitas b1 = b_ponerBanderita_antes2;
    cambiarBanderita(t_cambiar_Banderita,j1,p9,b_ponerBanderita_antes2); // Sacar banderita
    ASSERT_TRUE(esPermutacion(b_ponerBanderita_antes2,b0));
    ASSERT_TRUE(sacaBanderita(p9,b_ponerBanderita_antes2,b1));
}


banderitas b_ponerBanderita_antes3={
        pos(0,0),pos(3,3),pos(4,4),pos(1,2),pos(3,2)
};

TEST(cambiarBanderitaTEST, ponerBanderitaEnPosicionJugada){
    jugadas j1=jugadasValidas_cambiarBanderita;
    pos p9= pos(2, 2);
    banderitas b0 = b_ponerBanderita_antes3;
    cambiarBanderita(t_cambiar_Banderita,j1,p9,b_ponerBanderita_antes3); // Poner banderita
    ASSERT_FALSE(plantaBanderita(p9,b_ponerBanderita_antes3,b0));
}