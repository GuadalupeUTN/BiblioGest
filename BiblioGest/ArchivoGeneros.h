#pragma once
#include <string>
#include "Generos.h"

class GeneroArchivo{
private:
    const char* nombreArchivo;

public:
    GeneroArchivo();
    Generos leer(int pos);
    bool guardar(Generos& reg);
    bool guardarEnPosicion(Generos g, int pos);
    int contarRegistros();
    int buscarGenero(int _IDGenero);
    void leerTodos(int cantidadRegistros, Generos *vector);
    int contarCantLibros(int _IDGenero);
    void mostrarListadoGeneros();
};
