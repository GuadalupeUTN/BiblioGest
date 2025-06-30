#include <iostream>
#include <cstring>
using namespace std;
#include "Prestamos.h"
#include "ArchivoPrestamos.h"
#include "Fecha.h"
#include "socio.h"
#include "socioArchivo.h"
#include "Libro.h"
#include "archivoLibros.h"

Prestamos::Prestamos(){
_IDPrestamos=0;
strcpy(_ISBN,"-");
_IDSocio=0;
_fechaPrestamo=Fecha();
_fechaDevolucion=Fecha();
_estado=true;
}

Prestamos::Prestamos(Fecha fechaPrestamo, Fecha fechaDevolucion){
_IDPrestamos=0;
_fechaPrestamo=fechaPrestamo;
_fechaDevolucion=fechaDevolucion;
}

int Prestamos::getIDPrestamos(){
return _IDPrestamos;
}

int Prestamos::getIDSocio(){
return _IDSocio;
}

const char* Prestamos::getISBN(){
return _ISBN;
}

Fecha Prestamos::getFechaPrestamo(){
return _fechaPrestamo;
}

Fecha Prestamos::getFechaDevolucion(){
return _fechaDevolucion;
}

bool Prestamos::getEstado(){
return _estado;
}

void Prestamos::setIDPrestamos(int IDPrestamos){
_IDPrestamos=IDPrestamos;
}

void Prestamos::setIDSocio(int IDSocio){
_IDSocio=IDSocio;
}

void Prestamos::setISBN(const char* ISBN){
strcpy(_ISBN, ISBN);
}

void Prestamos::setFechaPrestamo(Fecha fechaPrestamo){
_fechaPrestamo=fechaPrestamo;
}
void Prestamos::setFechaDevolucion(Fecha fechaDevolucion){
_fechaDevolucion=fechaDevolucion;
}

void Prestamos::setEstado(bool estado){
_estado=estado;
}

void Prestamos::cargarPrestamo(){
SocioArchivo arcSocio;
LibroArchivo arcLibro;
cout << "INGRESE EL NUMERO DE SOCIO:"<<endl;
cin >> _IDSocio;
 int pos = arcSocio.buscar(_IDSocio);
            if (pos >= 0) {
                Socio s = arcSocio.leer(pos);
                s.mostrar();
            } else {

                cout << "SOCIO NO ENCONTRADO" << endl;
            }
cin.ignore();
cout <<"---------------------------------"<<endl;
cout <<"INGRESE EL ISBN DEL LIBRO A PRESTAR:"<<endl;
cin.getline(_ISBN, 14);
int posLibro=arcLibro.buscarISBN(_ISBN);
if (posLibro>=0){
    Libro l=arcLibro.leer(posLibro);
    l.mostrarLibro();
}else{

        cout << "LIBRO NO ENCONTRADO" << endl;
}

cout <<"---------------------------------"<<endl;
cout << "AHORA INGRESE LA FECHA DE PRESTAMO:"<<endl;
this -> _fechaPrestamo.cargar();
}

void Prestamos::mostrarPrestamo(){
    PrestamosArchivo arcPrestamo;
    Prestamos prestamo;
   prestamo = arcPrestamo.leer(_IDPrestamos - 1);

cout<<"ID:"<<_IDPrestamos<<"-";
cout<<"N°SOCIO:"<<_IDSocio<<"-";
cout<<"FECHA PRESTAMO:"<<_fechaPrestamo<<"-";
}

void Prestamos::editarPrestamo() {
    cout << "=== MODIFICAR PRESTAMO ===" << endl;

    int opcion;
    do {
        cout << "1. Cambiar fecha de devolución" << endl;
        cout << "2. Cambiar estado (activo/inactivo)" << endl;
        cout << "0. Salir de edición" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Ingrese nueva fecha de devolución: " << endl;
            _fechaDevolucion.cargar();
            cout << "Fecha de devolución actualizada correctamente." << endl;
            break;

        case 2:
            cout << "Ingrese nuevo estado (1 = activo, 0 = inactivo): ";
            cin >> _estado;
            if (_estado)
                cout << "Estado cambiado a activo." << endl;
            else
                cout << "Estado cambiado a inactivo." << endl;
            break;

        case 0:
            cout << "Saliendo de la edición del préstamo." << endl;
            break;

        default:
            cout << "Opción inválida." << endl;
        }

        cout << "-------------------------" << endl;
    } while (opcion != 0);
}

