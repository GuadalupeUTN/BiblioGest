#include <iostream>
using namespace std;
#include "Prestamos.h"

Prestamos::Prestamos(){
_IDPrestamos=0;
//IDSocio
//ISBN
_fechaPrestamos=Fecha();
_fechaDevolucion=Fecha();
};

Prestamos::Prestamos( int IDPrestamos, Fecha fechaPrestamo, Fecha fechaDevolucion){
_IDPrestamos=IDPrestamos;
_fechaPrestamo=fechaPrestamo;
_fechaDevolucion=fechaDevolucion;
//IDSocio
//ISBN
};

int Prestamos::getIDPrestamos(){
return _IDPrestamos;
};

Fecha Prestamos::getFechaPrestamo(){
return _fechaPrestamo;
};

Fecha Prestamos::getFechaDevolucion(){
return _fechaDevolucion;
};
