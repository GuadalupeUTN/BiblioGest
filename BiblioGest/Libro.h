#pragma once
#include "Fecha.h"


class Libro
{
private:
    char _ISBN[14];
    char _titulo[50];
    int _IDAutor;
    int _IDGenero;
    Fecha _fechaPubli;
    int _cantDisponible;

public:
    Libro();
    Libro (const char* ISBN,const char* titulo,int IDautor, int IDgenero, Fecha fechaPubli, int cantDisponible);

    const char* getISBN();
    const char* getTitulo();
    int getIDAutor();
    int getIDGenero();
    Fecha getFechaPubli();
    int getCantDisponible();

    void setISBN( const char* ISBN);
    void setTitulo (const char* titulo);
    void setIDAutor (int IDautor);
    void setIDGenero (int IDgenero);
    void setFecha (Fecha fechaPubli);
    void setCantiDisponible (int cantDisponible);

    void cargarLibro();
    void mostrarLibro();
    void editarLibro();
    void disponibilidadLibro();

};

