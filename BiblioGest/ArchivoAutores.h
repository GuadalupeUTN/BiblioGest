#pragma once
#include <string>
#include "Autores.h"

class AutoresArchivo{
private:
    const char* nombreArchivo;

public:
    AutoresArchivo();
    Autores leer(int pos);
    bool guardar(Autores& reg);
    bool guardarEnPosicion(Autores reg, int pos);
    int contarRegistros();
    int buscarAutor(int _IDAutor);
    void leerTodos(int cantidadRegistros, Autores *vector);
    void mostrarListadoAutores();
};
