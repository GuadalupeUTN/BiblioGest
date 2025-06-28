#include <iostream>
#include <string.h>
using namespace std;

#include "Generos.h"
#include "ArchivoGeneros.h"

int Generos::idAux = 1;

void Generos::inicializarID(){
GeneroArchivo arc;
idAux=arc.contarRegistros()+1;
};
Generos::Generos()
{
    _IDGenero=idAux++;
    strcpy(_genero,"-");
    _cantLibros=0;
};

Generos::Generos(const char* genero, int cantLibros )
{
    _IDGenero=idAux++;
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

void Generos::setGenero(const char* genero)
{
    strcpy(_genero, genero);
};
void Generos::setCantLibros(int cantLibros)
{
    _cantLibros= cantLibros;
};


void Generos::cargarGenero()
{
    cout << "GENERO:";
    cin.getline(_genero, 20);
    cout << "CANTIDAD LIBROS:";
    cin>> _cantLibros;
    cin.ignore();

};
void Generos::mostrarGeneros()
{
    cout<< _IDGenero<<endl;
    cout <<_genero<<endl;
    cout <<_cantLibros<<endl;
};
