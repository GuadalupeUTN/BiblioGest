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
    int buscarISBN(char _ISBN[14]);
    int contarCantLibrosPorGenero(int _IDGenero);
    int contarCantLibrosPorAutor (int _IDAutor);
    void leerTodos(int cantidadRegistros, Libro *vector);
    void mostrarListadoLibros();
    void disponibilidadLibro(char isbn[14]);
    void eliminarRegistroLibro();
    //buscarPorTitulo

};
