#pragma once
#include <string>
#include "Prestamos.h"

class PrestamosArchivo{
private:
    const char* nombreArchivo;
public:
    PrestamosArchivo();
    Prestamos leer(int pos);
    bool guardar(Prestamos& reg);
    bool guardarEnPosicion(Prestamos p, int pos);
    int contarRegistros();
    int buscarPrestamos(int _IDPrestamo);
    void leerTodos(int cantidadRegistros, Prestamos *vector);
    void mostrarListadoPrestamos();
};
