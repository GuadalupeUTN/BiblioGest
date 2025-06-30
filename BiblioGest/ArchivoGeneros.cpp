#include <iostream>

using namespace std;
#include "Generos.h"
#include "ArchivoGeneros.h"

GeneroArchivo::GeneroArchivo()
{
    nombreArchivo="generos.dat";
};

Generos GeneroArchivo::leer(int pos)
{

    FILE *pArchivo = fopen(nombreArchivo, "rb");
    if (pArchivo == NULL){
        return Generos();
    }
    Generos g;
    fseek(pArchivo, sizeof(Generos) * pos, SEEK_SET);
fread(&g, sizeof(Generos), 1, pArchivo);
    fclose(pArchivo);
    return g;

};


bool GeneroArchivo::guardar(Generos& reg)
{
    int total = contarRegistros();
    int ultimoNumero = 0;

    for (int i = total - 1; i >= 0; i--) {
        Generos g = leer(i);
        if (g.getEstado()) {
            ultimoNumero = g.getIDGenero();
            break;
        }
    }

    reg.setIDGenero(ultimoNumero + 1);

    FILE* p = fopen(nombreArchivo, "ab");
    if (p == nullptr) return false;

    bool exito = fwrite(&reg, sizeof(Generos), 1, p);
    fclose(p);
    return exito;
};

bool GeneroArchivo::guardarEnPosicion(Generos g, int pos)
{
    FILE *pArchivo = fopen(nombreArchivo, "rb+");
    if (pArchivo == NULL){
            return false;}

    fseek(pArchivo, sizeof(Generos) * pos, SEEK_SET);
    bool ok = fwrite(&g, sizeof(Generos), 1, pArchivo);
    fclose(pArchivo);
    return ok;
};


int GeneroArchivo::contarRegistros()
{
    FILE *pArchivo = fopen(nombreArchivo, "rb");
    if (pArchivo == NULL) {
            return 0;}

    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Generos);
    fclose(pArchivo);
    return cantidadRegistros;
};

void GeneroArchivo::leerTodos(int cantidadRegistros, Generos *vector){
    FILE *pArchivo = fopen(nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Generos), 1, pArchivo);
    }
    fclose(pArchivo);
}

int GeneroArchivo::buscarGenero(int _IDGenero)
{
    FILE* pArchivo = fopen(nombreArchivo, "rb");

    if (pArchivo == NULL)
    {
        return -1;
    }

    Generos g;
    int posicion = 0;
    while(fread(&g, sizeof(Generos), 1, pArchivo))
    {
        if (g.getIDGenero() == _IDGenero)
        {
            fclose(pArchivo);
            return posicion;
        }
        posicion++;
    }

    fclose(pArchivo);
    return -1;
};

void GeneroArchivo::mostrarListadoGeneros(){
GeneroArchivo arc;
int cantidad = arc.contarRegistros();
Generos* vector = new Generos[cantidad];

arc.leerTodos(cantidad, vector);

for (int i = 0; i < cantidad; i++) {
    vector[i].mostrarGeneros();
}

delete[] vector;
};

