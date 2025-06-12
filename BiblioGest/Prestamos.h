#pragma once
#include "Fecha.h"

class Prestamos{
private:
    int _IDPrestamos;
    //Libro ISBN
    //Socio _IDSocio
    Fecha _fechaPrestamo;
    Fecha _fechaDevolucion;
public:
    Prestamos();
    Prestamos( int IDPrestamos, Fecha fechaPrestamo, Fecha fechaDevolucion);

    int getIDPrestamos();
    Fecha getFechaPrestamo();
    Fecha getFechaDevolucion();

    void setIDPrestamos(int IDPrestamos);
    void setFechaPrestamo(Fecha fechaPrestamo);
    void setFechaDevolucion(Fecha fechaDevolucion);

    void registrarPrestamo();
    void registrarDevolucion();
    void editarPrestamo();
    void editarDevolucion();
};
