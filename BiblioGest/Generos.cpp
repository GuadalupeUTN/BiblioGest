#include <iostream>
#include <string.h>
using namespace std;

#include "Generos.h"
#include "ArchivoGeneros.h"
#include "archivoLibros.h"


Generos::Generos()
{
    _IDGenero=0;
    strcpy(_genero,"-");
    _cantLibros=0;
    _estado=true;
};

Generos::Generos(const char* genero, int cantLibros )
{
    _IDGenero=0;
    strcpy(_genero, genero);
    _cantLibros= cantLibros;
};

int Generos::getIDGenero()
{
    return _IDGenero;
};
const char* Generos::getGenero()
{
    return _genero;
};
int Generos::getCantLibros()
{
    return _cantLibros;
};

bool Generos::getEstado(){
return _estado;
};

void Generos::setIDGenero(int IDGenero){
_IDGenero=IDGenero;
}
void Generos::setGenero(const char* genero)
{
    strcpy(_genero, genero);
};
void Generos::setCantLibros(int cantLibros)
{
    _cantLibros= cantLibros;
};

void Generos::setEstado(bool estado){
_estado=estado;
}

void Generos::cargarGenero()
{
    cout << "GENERO:";
    cin.getline(_genero, 20);
};


void Generos::mostrarGeneros()
{
    LibroArchivo arcLibros;
     _cantLibros = arcLibros.contarCantLibrosPorGenero(_IDGenero);
    cout<<"ID:"<< _IDGenero<<"-";
    cout <<_genero<<"-";
    cout <<"CANTIDAD DE LIBROS:"<<_cantLibros<<endl;
};


