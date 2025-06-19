#include <iostream>

using namespace std;
#include "ArchivoAutores.h"

AutoresArchivo::AutoresArchivo()
{
    nombreArchivo="autores.dat";
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

bool AutoresArchivo::guardar(Autores reg){
    FILE* p = fopen(nombreArchivo, "ab");
    if (p == NULL) return false;

    bool exito = fwrite(&reg, sizeof(Autores), 1, p);
    fclose(p);
    return exito;
};
bool AutoresArchivo::guardar(Autores reg, int pos){
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == NULL) return false;

    fseek(p, sizeof(Autores) * pos, SEEK_SET);
    bool exito = fwrite(&reg, sizeof(Autores), 1, p);
    fclose(p);
    return exito;
};
int AutoresArchivo::contarRegistros(){
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) return 0;

    fseek(p, 0, SEEK_END);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Autores);
};
int AutoresArchivo::buscarAutor(int _IDAutor){
   Autores reg;
    int posicion = 0;
    FILE* p = fopen(nombreArchivo, "rb");

    if (p == nullptr)
    {
        return -2;
    }

    while(fread(&reg, sizeof(Autores), 1, p) == 1)
    {
        if (reg.getIDAutor() == _IDAutor)
        {
            fclose(p);
            return posicion;
        }
        posicion++;
    }

    fclose(p);
    return -1;
};

