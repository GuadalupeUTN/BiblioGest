#include "Libro.h"
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

