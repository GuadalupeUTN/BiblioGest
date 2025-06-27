#include <cstdio>
#include "pagosArchivo.h"

bool PagosArchivo::guardar(Pagos reg) {
    FILE* p = fopen(nombreArchivo, "ab");
    if (p == nullptr) return false;

    bool ok = fwrite(&reg, sizeof(Pagos), 1, p);
    fclose(p);
    return ok;
}

bool PagosArchivo::guardar(Pagos reg, int pos) {
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == nullptr) return false;

    fseek(p, pos * sizeof(Pagos), SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Pagos), 1, p);
    fclose(p);
    return ok;
}

Pagos PagosArchivo::leer(int pos) {
    Pagos reg;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return reg;

    fseek(p, pos * sizeof(Pagos), SEEK_SET);
    fread(&reg, sizeof(Pagos), 1, p);
    fclose(p);
    return reg;
}

int PagosArchivo::contarRegistros() {
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == nullptr) return 0;

    fseek(p, 0, SEEK_END);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Pagos);
}
bool PagosArchivo::eliminarFisicamente(int numeroSocio) {
    FILE* original = fopen(nombreArchivo, "rb");
    if (original == nullptr) return false;

    FILE* temp = fopen("pagos_temp.dat", "wb");
    if (temp == nullptr) {
        fclose(original);
        return false;
    }

    Pagos p;
    bool eliminado = false;

    while (fread(&p, sizeof(Pagos), 1, original) == 1) {
        if (p.getNumeroSocio() != numeroSocio) {
            fwrite(&p, sizeof(Pagos), 1, temp);
        } else {
            eliminado = true;
        }
    }

    fclose(original);
    fclose(temp);

    if (eliminado) {
        remove(nombreArchivo);
        rename("pagos_temp.dat", nombreArchivo);
    } else {
        remove("pagos_temp.dat");
    }

    return eliminado;
}
bool PagosArchivo::eliminarLogicamente(int numeroSocio) {
    int total = contarRegistros();
    bool eliminado = false;

    for (int i = 0; i < total; i++) {
        Pagos p = leer(i);
        if (p.getNumeroSocio() == numeroSocio && p.getEstado()) {
            p.setEstado(false);              // marcamos como inactivo
            guardar(p, i);                   // sobrescribimos el registro
            eliminado = true;
        }
    }

    return eliminado;
}

