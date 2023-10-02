//
// Función de inicio que corre todos los tests. 
// NO MODIFICAR
//

#include <iostream>
#include "ejercicios.h"
#include "auxiliares.h"
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    std::cout << "Implementando TPI!!" << std::endl;
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();;
}
