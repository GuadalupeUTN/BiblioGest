#include <iostream>
#include <cstring>
using namespace std;
#include "Prestamos.h"
#include "Fecha.h"
#include "socio.h"

Prestamos::Prestamos(){
_IDPrestamos=0;
strcpy(_ISBN,"-");
_IDSocio=0;
_fechaPrestamo=Fecha();
_fechaDevolucion=Fecha();
_estado=true;
};

Prestamos::Prestamos(Fecha fechaPrestamo, Fecha fechaDevolucion){
_IDPrestamos=0;
_fechaPrestamo=fechaPrestamo;
_fechaDevolucion=fechaDevolucion;
};

int Prestamos::getIDPrestamos(){
return _IDPrestamos;
};

int Prestamos::getIDSocio(){
return _IDSocio;
}

const char* Prestamos::getISBN(){
return _ISBN;
}

Fecha Prestamos::getFechaPrestamo(){
return _fechaPrestamo;
};

Fecha Prestamos::getFechaDevolucion(){
return _fechaDevolucion;
};

bool Prestamos::getEstado(){
return _estado;
}

void Prestamos::setIDPrestamos(int IDPrestamos){
_IDPrestamos=IDPrestamos;
};

void Prestamos::setIDSocio(int IDSocio){
_IDSocio=IDSocio;
}

void Prestamos::setISBN(const char* ISBN){
strcpy(_ISBN, ISBN);
}

void Prestamos::setFechaPrestamo(Fecha fechaPrestamo){
_fechaPrestamo=fechaPrestamo;
};
void Prestamos::setFechaDevolucion(Fecha fechaDevolucion){
_fechaDevolucion=fechaDevolucion;
};

void Prestamos::setEstado(bool estado){
_estado=estado;
}

void Prestamos::cargarPrestamo(){
cout << "INGRESE EL ID DEL SOCIO:"<<endl;
cin >> _IDSocio;
cout << "AHORA INGRESE LA FECHA DE PRESTAMO:"<<endl;
this -> _fechaPrestamo.cargar();
};

void Prestamos::mostrarPrestamo(){
cout<<"ID:"<<_IDPrestamos<<"-";
cout<<"N°SOCIO:"<<_IDSocio<<"-";
cout<<"FECHA PRESTAMO:"<<_fechaPrestamo<<"-";
};
