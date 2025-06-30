#include <iostream>
#include <cstring>
using namespace std;
#include "ArchivoPrestamos.h"
PrestamosArchivo::PrestamosArchivo(){
    nombreArchivo="prestamos.dat";
};
Prestamos PrestamosArchivo::leer(int pos){
     FILE *pArchivo = fopen(nombreArchivo, "rb");
    if (pArchivo == NULL){
        return Prestamos();
    }
    Prestamos p;
    fseek(pArchivo, sizeof(Prestamos) * pos, SEEK_SET);
fread(&p, sizeof(Prestamos), 1, pArchivo);
    fclose(pArchivo);
    return p;

};
bool PrestamosArchivo::guardar(Prestamos& reg){
     int total = contarRegistros();
    int ultimoNumero = 0;

    for (int i = total - 1; i >= 0; i--) {
        Prestamos p = leer(i);
        if (p.getEstado()) {
            ultimoNumero = p.getIDPrestamos();
            break;
        }
    }

    reg.setIDPrestamos(ultimoNumero + 1);

    FILE* p = fopen(nombreArchivo, "ab");
    if (p == nullptr) return false;

    bool exito = fwrite(&reg, sizeof(Prestamos), 1, p);
    fclose(p);
    return exito;
};
bool PrestamosArchivo::guardarEnPosicion(Prestamos p, int pos){
     FILE *pArchivo = fopen(nombreArchivo, "rb+");
    if (pArchivo == NULL){
            return false;}

    fseek(pArchivo, sizeof(Prestamos) * pos, SEEK_SET);
    bool ok = fwrite(&p, sizeof(Prestamos), 1, pArchivo);
    fclose(pArchivo);
    return ok;
};
int PrestamosArchivo::contarRegistros(){
    FILE *pArchivo = fopen(nombreArchivo, "rb");
    if (pArchivo == NULL) {
            return 0;}

    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Prestamos);
    fclose(pArchivo);
    return cantidadRegistros;
};
void PrestamosArchivo::leerTodos(int cantidadRegistros, Prestamos *vector){
        FILE *pArchivo = fopen(nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Prestamos), 1, pArchivo);
    }
    fclose(pArchivo);
};

int PrestamosArchivo::buscarPrestamos(int _IDPrestamo){
  FILE* pArchivo = fopen(nombreArchivo, "rb");

    if (pArchivo == NULL)
    {
        return -1;
    }

    Prestamos p;
    int posicion = 0;
    while(fread(&p, sizeof(Prestamos), 1, pArchivo))
    {
        if (p.getIDPrestamos() == _IDPrestamo)
        {
            fclose(pArchivo);
            return posicion;
        }
        posicion++;
    }

    fclose(pArchivo);
    return -1;
};
void PrestamosArchivo::mostrarListadoPrestamos(){
PrestamosArchivo arc;
int cantidad = arc.contarRegistros();
Prestamos* vector = new Prestamos[cantidad];

arc.leerTodos(cantidad, vector);

for (int i = 0; i < cantidad; i++) {
    vector[i].mostrarPrestamo();
}

delete[] vector;
};
