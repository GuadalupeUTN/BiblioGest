#include <iostream>

using namespace std;

#include "archivoLibros.h"

//ArchivoLibros::ArchivoLibros(std::string _nombreArchivo)
//{
    //_nombreArchivo=nombreArchivo;
//};

/*/bool ArchivoLibros::agregarRegistroLibro(Libro objlibro)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        cout <<"ARCHIVO VACIO"<<endl;
        return false;
    }
    bool ok = fwrite(&objlibro, sizeof(Libro), 1, pArchivo);
    fclose(pArchivo);
    return ok;
};

Libro ArchivoLibros::leerRegistroLibro(int pos){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
            cout<<"FALLA AL LEER ARCHIVO"<<endl;
        return Libro();
    }
    Libro objlibro;
    fseek(pArchivo, sizeof(Libro) * pos, SEEK_SET);
    fread(&objlibro, sizeof(Libro), 1, pArchivo);
    fclose(pArchivo);
    return objlibro;
};

void ArchivoLibros::mostrarBiblioteca()
{
};
int ArchivoLibros::cuentaLibrosRegistrados()
{
};*/

//int buscarRegistroLibroPorISBN(const char* _ISBN);
