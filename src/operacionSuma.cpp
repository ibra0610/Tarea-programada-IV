#include "operacionSuma.h" 
#include <string> 

OperacionSuma::OperacionSuma(){
     
}

string OperacionSuma::Ejecute(string valor){
    
    string separador = " "; 

    int primerDigito = stoi(valor.substr(0,valor.find(separador)));
    int segundoDigito = stoi(valor.substr(4,valor.find(separador)));

    int resultado = primerDigito + segundoDigito; 

    string resultado_a_String = to_string(resultado);
    
    return resultado_a_String; 
}