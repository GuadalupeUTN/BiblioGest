#ifndef PAGOSARCHIVO_H
#define PAGOSARCHIVO_H

#include "pagos.h"

class PagosArchivo {
private:
    const char* nombreArchivo = "pagos.dat";

public:
    bool guardar(Pagos reg);
    bool guardar(Pagos reg, int pos);
    Pagos leer(int pos);
    int contarRegistros();
    bool eliminarLogicamente(int numeroSocio);
    bool eliminarFisicamente(int numeroSocio);
    bool tieneDeuda(int numeroSocio);
    bool tieneDeudaPorFecha(int numeroSocio, int _mes, int _anio);
};

#endif // PAGOSARCHIVO_H
