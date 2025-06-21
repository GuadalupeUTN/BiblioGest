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
