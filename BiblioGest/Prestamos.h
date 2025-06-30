#pragma once
#include "Fecha.h"

class Prestamos{
private:
    int _IDPrestamos;
    char _ISBN[14];
    int _IDSocio;
    Fecha _fechaPrestamo;
    Fecha _fechaDevolucion;
    bool _estado;
public:
    Prestamos();
    Prestamos(Fecha fechaPrestamo, Fecha fechaDevolucion);

    int getIDPrestamos();
    const char* getISBN();
    int getIDSocio();
    Fecha getFechaPrestamo();
    Fecha getFechaDevolucion();
    bool getEstado();

    void setIDPrestamos(int IDPrestamos);
    void setISBN(const char* ISBN);
    void setIDSocio(int IDSocio);
    void setFechaPrestamo(Fecha fechaPrestamo);
    void setFechaDevolucion(Fecha fechaDevolucion);
    void setEstado(bool estado);

    void registrarPrestamo();
    void registrarDevolucion();
    void editarPrestamo();
    void editarDevolucion();
    //void eliminarPrestamo();
    //void eliminarDevolucion();
};
