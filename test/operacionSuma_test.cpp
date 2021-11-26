#include <gtest/gtest.h> 
#include <string> 
#include "./../src/operacionSuma.h" 

using namespace std; 

namespace{
    TEST(OperacionSuma_Test, Test_Formato_Aplicado){

        OperacionSuma *operacionSuma = new OperacionSuma(); 

        string actual = operacionSuma->Ejecute("2 + 4"); 
        string esperado = "6"; 

        delete operacionSuma;  

        EXPECT_EQ(esperado,actual);
    }

}