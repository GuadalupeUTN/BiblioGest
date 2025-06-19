#pragma once
#include "Fecha.h"
#include "Generos.h"

class Libro
{
private:
    char _ISBN[13];
    char _titulo[50];
    char _autor[50];
    Fecha _fechaPubli;
    int _cantDisponible;

public:
    Libro();
    Libro (const char* ISBN,const char* titulo,const char* autor, Fecha fechaPubli, int cantDisponible);

    const char* getISBN();
    const char* getTitulo();
    const char* getAutor();
    Fecha getFechaPubli();
    int getCantDisponible();

    void setISBN( const char* ISBN);
    void setTitulo (const char* titulo);
    void setAutor (const char* autor);
    void setFecha (Fecha fechaPubli);
    void setCantiDisponible (int cantDisponible);

    void cargarLibro();
    void mostrarLibro();
    void editarLibro();
    void disponibilidadLibro();

};

