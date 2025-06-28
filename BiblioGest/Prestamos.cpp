#include <iostream>
using namespace std;
#include "Prestamos.h"
#include "Fecha.h"
#include "socio.h"

Prestamos::Prestamos(){
_IDPrestamos=0;
//IDSocio
//ISBN
_fechaPrestamo=Fecha();
_fechaDevolucion=Fecha();
}

Prestamos::Prestamos( int IDPrestamos, Fecha fechaPrestamo, Fecha fechaDevolucion){
_IDPrestamos=IDPrestamos;
_fechaPrestamo=fechaPrestamo;
_fechaDevolucion=fechaDevolucion;
//IDSocio
//ISBN
}

int Prestamos::getIDPrestamos(){
return _IDPrestamos;
}

Fecha Prestamos::getFechaPrestamo(){
return _fechaPrestamo;
}

Fecha Prestamos::getFechaDevolucion(){
return _fechaDevolucion;
}


void Prestamos::setIDPrestamos(int IDPrestamos){
_IDPrestamos=IDPrestamos;
}
void Prestamos::setFechaPrestamo(Fecha fechaPrestamo){
_fechaPrestamo=fechaPrestamo;
}
void Prestamos::setFechaDevolucion(Fecha fechaDevolucion){
_fechaDevolucion=fechaDevolucion;
}

void Prestamos::registrarPrestamo(){
cout << "INGRESE LOS DATOS REQUERIDOS PARA REGISTRAR PRESTAMO:"<<endl;
cout <<"IDPrestamo:";
cin>> _IDPrestamos;
cout <<endl;
cout << "Fecha Prestamo:";
this -> _fechaPrestamo.cargar();
}

void Prestamos::registrarDevolucion(){
cout<< "INGRESE LOS DATOS REQUERIDOS PARA REGISTRAR DEVOLUCION:"<<endl;
cout<< "Fecha Devolucion: ";
this ->_fechaDevolucion.cargar();
cout << endl;
}
