#include <iostream>

using namespace std;
#include "Generos.h"
#include "ArchivoGeneros.h"

GeneroArchivo::GeneroArchivo()
{
    nombreArchivo="generos.dat";
};


bool GeneroArchivo::guardar(Generos g)
{
    FILE *pArchivo = fopen(nombreArchivo, "ab");
    if (pArchivo == NULL) {
            return false;}

    bool ok = fwrite(&g, sizeof(Generos), 1, pArchivo);
    fclose(pArchivo);
    return ok;
};

bool GeneroArchivo::guardar(Generos g, int pos)
{
    FILE *pArchivo = fopen(nombreArchivo, "rb+");
    if (pArchivo == NULL){
            return false;}

    fseek(pArchivo, sizeof(Generos) * pos, SEEK_SET);
    bool ok = fwrite(&g, sizeof(Generos), 1, pArchivo);
    fclose(pArchivo);
    return ok;
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

