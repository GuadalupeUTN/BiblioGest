#pragma once
#include <string>
#include "Generos.h"

class GeneroArchivo{
private:
    const char* nombreArchivo;

public:
    GeneroArchivo();
    Generos leer(int pos);
    bool guardar(Generos reg);
    bool guardar(Generos reg, int pos);
    int contarRegistros();
    int buscarGenero(int _IDGenero);
};
