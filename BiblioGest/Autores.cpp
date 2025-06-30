
#include <iostream>
#include <cstring>
using namespace std;

#include "Autores.h"
#include "ArchivoAutores.h"
#include "archivoLibros.h"

Autores::Autores(){
_IDAutor=0;
    strcpy(_autor,"-");
_cantObras=0;
_estado=true;
};

Autores::Autores(const char* autor, int cantObras){
_IDAutor=0;
    strcpy(_autor, autor);
_cantObras=cantObras;
};

int Autores::getIDAutor(){
return _IDAutor;
};
const char* Autores::getAutor(){
return _autor;
};
int Autores::getCantObras(){
return _cantObras;
};
bool Autores::getEstado(){
return _estado;
};

void Autores::setIDAutor(int IDAutor){
    _IDAutor=IDAutor;
}

void Autores::setAutor(const char* autor){
    strcpy(_autor, autor);
};

void Autores::setCantObras(int cantObras){
_cantObras=cantObras;
};

void Autores::setEstado(bool estado){
_estado=estado;
}

void Autores::cargarAutor(){

    cout << "NOMBRE Y APELLIDO DEL AUTOR/A:";
    cin.getline(_autor, 80);

};

void Autores::mostrarAutor(){
    LibroArchivo arcLibros;
     _cantObras = arcLibros.contarCantLibrosPorAutor(_IDAutor);
    cout<<"ID:"<< _IDAutor<<"-";
    cout <<_autor<<"-";
    cout <<"CANTIDAD DE OBRAS:"<<_cantObras<<endl;
};
