#include <cstring>
#include <iostream>

using namespace std;
#include "Socio.h"

void Socio::cargar() {
    cout << "NUMERO DE SOCIO: ";
    cin >> numeroSocio;

    cout << "DNI: ";
    cin >> dni;

    cout << "NOMBRE: ";
    cin.ignore();
    cin.getline(nombre, 30);

    cout << "APELLIDO: ";
    cin.getline(apellido, 30);

    cout << "TELEFONO: ";
    cin.getline(telefono, 20);

    cout << "DIRECCION: ";
    cin.getline(direccion, 50);

    cout << "EMAIL: ";
    cin.getline(email, 40);

    estado = true;

    cout << "FECHA DE NACIMIENTO: " << endl;
    fechaNacimiento.cargar();
}

void Socio::mostrar() {
    cout << "SOCIO #" << numeroSocio << endl;
    cout << "DNI: " << dni << endl;
    cout << "NOMBRE: " << nombre << ", " << apellido << endl;
    cout << "TELEFONO: " << telefono << endl;
    cout << "DIRECCION: " << direccion << endl;
    cout << "EMAIL: " << email << endl;
    cout << "FECHA DE NACIMIENTO: ";
    fechaNacimiento.mostrar();
    cout << endl;
}

// Setters
void Socio::setNumeroSocio(int n) { numeroSocio = n; }
void Socio::setDni(const char* d) { strcpy(dni, d); }
void Socio::setNombre(const char* n) { strcpy(nombre, n); }
void Socio::setApellido(const char* a) { strcpy(apellido, a); }
void Socio::setTelefono(const char* t) { strcpy(telefono, t); }
void Socio::setDireccion(const char* d) { strcpy(direccion, d); }
void Socio::setEmail(const char* e) { strcpy(email, e); }
void Socio::setEstado(bool e) { estado = e; }
void Socio::setFechaNacimiento(Fecha f) { fechaNacimiento = f; }

// Getters
int Socio::getNumeroSocio() { return numeroSocio; }
const char* Socio::getDni() { return dni; }
const char* Socio::getNombre() { return nombre; }
const char* Socio::getApellido() { return apellido; }
const char* Socio::getTelefono() { return telefono; }
const char* Socio::getDireccion() { return direccion; }
const char* Socio::getEmail() { return email; }
bool Socio::getEstado() {return estado; }
Fecha Socio::getFechaNacimiento() { return fechaNacimiento; }
