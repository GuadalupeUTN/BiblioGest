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
    bool guardarEnPosicion(Libro reg, int pos);
    int contarRegistros();
    int buscarISBN(char _ISBN[13]);
    int contarCantLibrosPorGenero(int _IDGenero);
    int contarCantLibrosPorAutor (int _IDAutor);
    void leerTodos(int cantidadRegistros, Libro *vector);
    void eliminarRegistroLibro();
    void mostrarListadoLibros();
    //buscarPorTitulo

};
