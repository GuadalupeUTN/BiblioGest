#include <iostream>

using namespace std;
#include "ArchivoAutores.h"

AutoresArchivo::AutoresArchivo()
{
    nombreArchivo="autores.dat";
};

bool AutoresArchivo::guardar(Autores a){
    FILE *pArchivo = fopen(nombreArchivo, "ab");
    if (pArchivo == NULL) {
            return false;}

    bool ok = fwrite(&a, sizeof(Autores), 1, pArchivo);
    fclose(pArchivo);
    return ok;
};

bool AutoresArchivo::guardar(Autores a, int pos){
    FILE *pArchivo = fopen(nombreArchivo, "rb+");
    if (pArchivo == NULL){
            return false;}

    fseek(pArchivo, sizeof(Autores) * pos, SEEK_SET);
    bool ok = fwrite(&a, sizeof(Autores), 1, pArchivo);
    fclose(pArchivo);
    return ok;
};

Autores AutoresArchivo::leer(int pos)
{
    Autores reg;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) return reg;

    fseek(p, sizeof(Autores) * pos, SEEK_SET);
    fread(&reg, sizeof(Autores), 1, p);
    fclose(p);
    return reg;
};

int AutoresArchivo::contarRegistros(){
    FILE *pArchivo = fopen(nombreArchivo, "rb");
    if (pArchivo == NULL) {
            return 0;}

    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Autores);
    fclose(pArchivo);
    return cantidadRegistros;
};

void AutoresArchivo::leerTodos(int cantidadRegistros, Autores *vector){
    FILE *pArchivo = fopen(nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Autores), 1, pArchivo);
    }
    fclose(pArchivo);
}


int AutoresArchivo::buscarAutor(int _IDAutor){
    FILE* pArchivo = fopen(nombreArchivo, "rb");

    if (pArchivo == NULL)
    {
        return -1;
    }

    Autores a;
    int posicion = 0;
    while(fread(&a, sizeof(Autores), 1, pArchivo))
    {
        if (a.getIDAutor() == _IDAutor)
        {
            fclose(pArchivo);
            return posicion;
        }
        posicion++;
    }

    fclose(pArchivo);
    return -1;
};

