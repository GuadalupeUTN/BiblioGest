#include <iostream>
using namespace std;

#include "Libro.h"
#include "Fecha.h"
#include <string.h>

Libro::Libro()
{
    strcpy(_ISBN,"-");
    strcpy(_titulo,"-");
    strcpy(_autor,"-");
    _fechaPubli= Fecha();
    _cantDisponible=0;
};

Libro::Libro(const char* ISBN,const char* titulo,const char* autor, Fecha fechaPubli, int cantDisponible)
{
    strcpy(_ISBN, ISBN);
    strcpy(_titulo, titulo);
    strcpy(_autor, autor);
    _fechaPubli= fechaPubli;
    _cantDisponible= cantDisponible;
};

const char* Libro::getISBN()
{
    return _ISBN;
};
const char* Libro::getTitulo()
{
    return _titulo;
};
const char* Libro::getAutor()
{
    return _autor;
};
Fecha Libro::getFechaPubli()
{
    return _fechaPubli;
};
int Libro::getCantDisponible()
{
    return _cantDisponible;
};

void Libro::setISBN(const char* ISBN)
{
    strcpy(_ISBN, ISBN);
};
void Libro::setTitulo (const char *titulo)
{
    strcpy(_titulo, titulo);
};
void Libro::setAutor (const char *autor)
{
    strcpy(_autor, autor);
};
void Libro::setFecha (Fecha fechaPubli)
{
    _fechaPubli= fechaPubli;
};
void Libro::setCantiDisponible (int cantDisponible)
{
    _cantDisponible= cantDisponible;
};

void Libro::cargarLibro()
{
    cout << "PORFAVOR ESCRIBA LOS SIGUIENTES DATOS DEL LIBRO QUE DESEA:"<< endl;
    cout << "ISBN:";
    cin.getline(_ISBN, 13);
    cout << endl;
    cout << "TITULO:";
    cin.getline(_titulo, 50);
    cout << endl;
    cout << "AUTOR:";
    cin.getline(_autor, 50);
    cout << endl;
    cout << "FECHA DE PUBLICACION:";
    this ->_fechaPubli.cargarFecha();
    cout << endl;
    cout << "CANTIDAD DISPONIBLE:";
    cin >> _cantDisponible;
    cout << endl;
};
void Libro::mostrarLibro()
{

    cout << "ISBN:"<< _ISBN << endl;

    cout << "TITULO:" << _titulo << endl;

    cout << "AUTOR:"<< _autor << endl;

    cout << "FECHA DE PUBLICACION:"<< _fechaPubli<< endl;

    cout << "CANTIDAD DISPONIBLE:" << _cantDisponible << endl;

};
void Libro::editarLibro() {
cout << "Editar libro esta en proceso"<<endl;};
void Libro::eliminarLibro() {
cout << "Eliminar libro esta en proceso"<<endl;};
