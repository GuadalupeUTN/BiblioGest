#ifndef PAGOSARCHIVO_H
#define PAGOSARCHIVO_H

#include "pagos.h"

class PagosArchivo {
private:
    const char* nombreArchivo = "pagos.dat";

public:
    bool guardar(Pagos reg);                 // agrega al final
    bool guardar(Pagos reg, int pos);        // sobrescribe en una posición
    Pagos leer(int pos);                     // lee un registro por posición
    int contarRegistros();                  // cuenta todos los registros
    bool eliminarLogicamente(int numeroSocio);
    bool eliminarFisicamente(int numeroSocio);
};

#endif // PAGOSARCHIVO_H
