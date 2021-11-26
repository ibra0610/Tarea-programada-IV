#ifndef OPERACIONSUMA_H 
#define OPERACIONSUMA_H 

#include "operacion.h" 
#include <string> 

using namespace std; 

class OperacionSuma : public Operacion{


    public: 
    OperacionSuma(); 

    virtual string Ejecute(string valor);
}; 

#endif