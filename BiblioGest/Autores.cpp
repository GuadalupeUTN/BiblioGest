
#include <iostream>
#include <cstring>
using namespace std;

#include "Autores.h"
int Autores::idAux=1;

Autores::Autores(){
_IDAutor=idAux++;
    strcpy(_autor,"-");
_cantObras=0;
};
Autores::Autores(const char* autor, int cantObras){
_IDAutor=idAux++;
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

void Autores::setAutor(const char* autor){
    strcpy(_autor, autor);
};

void Autores::setCantObras(int cantObras){
_cantObras=cantObras;
};

void Autores::cargarAutor(){
    cout << "NOMBRE Y APELLIDO DEL AUTOR/A:";
    cin.getline(_autor, 80);
    cout << "CANTIDAD OBRAS:";
    cin>> _cantObras;
    cin.ignore();
};

void Autores::mostrarAutor(){
    cout<< _IDAutor<<endl;
    cout <<_autor<<endl;
    cout <<_cantObras<<endl;
};
