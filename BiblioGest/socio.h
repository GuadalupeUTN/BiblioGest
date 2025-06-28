#ifndef SOCIO_H
#define SOCIO_H

#include "Fecha.h"

class Socio {
private:
    int numeroSocio;
    char dni[12];
    char nombre[30];
    char apellido[30];
    char telefono[20];
    char direccion[50];
    char email[40];
    bool estado;
    Fecha fechaNacimiento;

public:
    void cargar();
    void mostrar();

    void setNumeroSocio(int);
    void setDni(const char*);
    void setNombre(const char*);
    void setApellido(const char*);
    void setTelefono(const char*);
    void setDireccion(const char*);
    void setEmail(const char*);
    void setEstado(bool);
    void setFechaNacimiento(Fecha);

    int getNumeroSocio();
    const char* getDni();
    const char* getNombre();
    const char* getApellido();
    const char* getTelefono();
    const char* getDireccion();
    const char* getEmail();
    bool getEstado();
    Fecha getFechaNacimiento();
};

#endif // SOCIO_H
