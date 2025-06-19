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
    Generos reg;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) return reg;

    fseek(p, sizeof(Generos) * pos, SEEK_SET);
    fread(&reg, sizeof(Generos), 1, p);
    fclose(p);
    return reg;
};

bool GeneroArchivo::guardar(Generos reg)
{
    FILE* p = fopen(nombreArchivo, "ab");
    if (p == NULL) return false;

    bool exito = fwrite(&reg, sizeof(Generos), 1, p);
    fclose(p);
    return exito;
};

bool GeneroArchivo::guardar(Generos reg, int pos)
{
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == NULL) return false;

    fseek(p, sizeof(Generos) * pos, SEEK_SET);
    bool exito = fwrite(&reg, sizeof(Generos), 1, p);
    fclose(p);
    return exito;
};

int GeneroArchivo::contarRegistros()
{
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) return 0;

    fseek(p, 0, SEEK_END);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Generos);
};

int GeneroArchivo::buscarGenero(int _IDGenero)
{
    Generos reg;
    int posicion = 0;
    FILE* p = fopen(nombreArchivo, "rb");

    if (p == nullptr)
    {
        return -2;
    }

    while(fread(&reg, sizeof(Generos), 1, p) == 1)
    {
        if (reg.getIDGenero() == _IDGenero)
        {
            fclose(p);
            return posicion;
        }
        posicion++;
    }

    fclose(p);
    return -1;
};
