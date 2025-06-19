#pragma once
#include <string>
#include "Libro.h"


class LibroArchivo {
private:
    const char* nombreArchivo;

public:
    LibroArchivo();
    Libro leer(int pos);
    bool guardar(Libro reg);
    bool guardar(Libro reg, int pos);
    int contarRegistros();
    int buscarISBN(char _ISBN[13]);
    //buscarTitulo
    //int buscarAutor
    //int buscarGenero

};

