#include <iostream>

using namespace std;

#include "archivoLibros.h"

LibroArchivo::LibroArchivo()
{
    nombreArchivo="libros.dat";
};

Libro LibroArchivo::leer(int pos)
{
    Libro reg;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) return reg;

    fseek(p, sizeof(Libro) * pos, SEEK_SET);
    fread(&reg, sizeof(Libro), 1, p);
    fclose(p);
    return reg;
};
bool LibroArchivo::guardar(Libro reg)
{
    FILE* p = fopen(nombreArchivo, "ab");
    if (p == NULL) return false;

    bool exito = fwrite(&reg, sizeof(Libro), 1, p);
    fclose(p);
    return exito;
};

bool LibroArchivo::guardar(Libro reg, int pos)
{
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == NULL) return false;

    fseek(p, sizeof(Libro) * pos, SEEK_SET);
    bool exito = fwrite(&reg, sizeof(Libro), 1, p);
    fclose(p);
    return exito;
};

int LibroArchivo::contarRegistros()
{
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) return 0;

    fseek(p, 0, SEEK_END);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Libro);
};

int LibroArchivo::buscarISBN(char _ISBN[13])
{
    Libro reg;
    int posicion = 0;
    FILE* p = fopen(nombreArchivo, "rb");

    if (p == nullptr)
    {
        return -2;
    }

    while(fread(&reg, sizeof(Libro), 1, p) == 1)
    {
        if (reg.getISBN() == _ISBN)
        {
            fclose(p);
            return posicion;
        }
        posicion++;
    }

    fclose(p);
    return -1;
};
