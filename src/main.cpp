#ifndef UNIT_TEST

#include "procesadorInstrucciones.h"
#include "identificadorOperaciones.h"
#include "operacionHola.h"
#include "operacionSuma.h" 

#include <iostream>
#include <string>
#include <fstream>

#include "proveedorFormato.h"
#include "proveedorFormatoDesdeStream.h"

using namespace std;

int main() {

    try {
        // Inicialización
        // Configuración de la inyección de dependencias
        map<string, Operacion *> operaciones {};

        std::ifstream ifs("formato.ini", std::ifstream::in);

        if (!ifs.is_open())
        {
            std::cerr << "Error leyendo archivo formato.ini" << std::endl;
            return -1;
        } 

        string nombreArchivo_deUsuario = "formatoIngles.ini"; //esta variable se puede cambiar dependiendo del usuario

        ifstream archivoUsuario(nombreArchivo_deUsuario, ifstream::in); 
        if(!archivoUsuario.is_open()){
            std::cerr << "Error leyendo archivo formatoUsuario.ini" << std::endl;
            return -1;
        }

        ProveedorFormato *proveedorFormato = new ProveedorFormatoDesdeStream(&ifs);
        ProveedorFormato *proveedorFormatoUsuario = new ProveedorFormatoDesdeStream(&archivoUsuario); 

        OperacionHola *operacionHola = new OperacionHola(proveedorFormato);
        OperacionSuma *operacionSuma = new OperacionSuma(); 
        OperacionHola *operacionHello = new OperacionHola(proveedorFormatoUsuario); 
        
        operaciones.insert(std::pair<string, Operacion *>("hola", operacionHola));
        operaciones.insert(std::pair<string, Operacion *>("suma", operacionSuma)); 
        operaciones.insert(std::pair<string, Operacion *>("hello", operacionHello)); 


        IdentificadorOperacionesBase *identificadorOperaciones = new IdentificadorOperaciones(operaciones);

        
        ProcesadorInstrucciones *procesador = new ProcesadorInstrucciones(identificadorOperaciones);
        string resultado = procesador->Procese("hola", "todos");
        string salida = procesador->Procese("suma","2 + 3"); 
        string resultadoHello = procesador->Procese("hello", "it's me"); 
        cout << "Resultado operacionSuma: " << salida << endl; 
        cout << "Resultado operacionHola: " << resultado << endl; 
        cout << "Resultado hello: " << resultadoHello << endl; 

        // Cerrar archivo de entrada
        ifs.close();

    } catch (char const* exception)
    {
        cerr << "Error: " << exception << endl;
    }
    

    return 0;
}

#endif