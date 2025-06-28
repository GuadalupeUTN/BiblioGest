#ifndef SOCIOARCHIVO_H
#define SOCIOARCHIVO_H

#include "Socio.h"

class SocioArchivo {
private:
    const char* nombreArchivo;

public:
    SocioArchivo();
    Socio leer(int pos);
    bool guardar(Socio reg);
    bool guardar(Socio reg, int pos);
    int contarRegistros();
    int buscar(int nroSocio);
    int buscarDni(char dni[12]);
};

#endif // SOCIOARCHIVO_H
