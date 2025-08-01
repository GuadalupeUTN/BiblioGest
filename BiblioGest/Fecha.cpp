#include "Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(){
    _dia = 0;
    _mes = 0;
    _anio = 0;
}

Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

void Fecha::cargar() {
    cout << "DIA: ";
    cin >> _dia;
    cout << "MES: ";
    cin >> _mes;
    cout << "ANIO: ";
    cin >> _anio;
}

void Fecha::mostrar() {
    cout << _dia << "/" << _mes << "/" << _anio;
}


int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

void Fecha::setDia(int dia){
    _dia = dia;
}

void Fecha::setMes(int mes){
    _mes = mes;
}

void Fecha::setAnio(int anio){
    _anio = anio;
}

std::ostream& operator<<(std::ostream& os, const Fecha& f) {
    os << f._dia << "/" << f._mes << "/" << f._anio;
    return os;
}

