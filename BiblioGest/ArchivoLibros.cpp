#include <iostream>
#include <cstring>

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

bool LibroArchivo::guardarEnPosicion(Libro reg, int pos)
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

int LibroArchivo::buscarISBN(char _ISBN[14])
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
        if (strcmp(reg.getISBN(), _ISBN) == 0)
        {
            fclose(p);
            return posicion;
        }
        posicion++;
    }

    fclose(p);
    return -1;
};

int LibroArchivo::contarCantLibrosPorGenero(int _IDGenero){
int cantidadLibros=0;
LibroArchivo arcLibros;
int totalLibros=arcLibros.contarRegistros();
for (int i = 0; i < totalLibros; i++){
Libro lib=arcLibros.leer(i);
if (lib.getIDGenero()==_IDGenero){
    cantidadLibros++;
}
}
return cantidadLibros;
};

int LibroArchivo::contarCantLibrosPorAutor (int _IDAutor){
int cantidadLibros=0;
LibroArchivo arcLibros;
int totalLibros=arcLibros.contarRegistros();
for (int i = 0; i < totalLibros; i++){
Libro lib=arcLibros.leer(i);
if (lib.getIDAutor()==_IDAutor){
    cantidadLibros++;
}
}
return cantidadLibros;
};

void LibroArchivo::leerTodos(int cantidadRegistros, Libro *vector){
    FILE *pArchivo = fopen(nombreArchivo, "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Libro), 1, pArchivo);
    }
    fclose(pArchivo);
}

void LibroArchivo::mostrarListadoLibros(){
LibroArchivo arc;
int cantidad = arc.contarRegistros();
Libro* vector = new Libro[cantidad];

arc.leerTodos(cantidad, vector);

for (int i = 0; i < cantidad; i++) {
    vector[i].mostrarLibro();
}

delete[] vector;
}

void LibroArchivo::disponibilidadLibro(char isbn[14]){
int pos=buscarISBN(isbn);
Libro libro = leer(pos);
if (libro.getCantDisponible() <= 0) {
    cout << "NO HAY EJEMPLARES DISPONIBLES DE ESTE LIBRO" << endl;
    libro.mostrarLibro();
    return;
}
libro.setCantiDisponible(libro.getCantDisponible() - 1);
guardarEnPosicion(libro, pos);
}

void LibroArchivo::eliminarRegistroLibro(){
    /*
LibroArchivo arc;
char isbnElegido[14];
cout << "INGRESE ISBN DEL LIBRO A ELIMINAR:";
cin.getline(isbnElegido,14);
cin.ignore();
int pos = arcLibro.buscarISBN(isbnElegido);
    if (pos < 0)
    {
        cout << "NO SE ENCONTRO EL LIBRO CON ESE ISBN" << endl;
        return;
    }
*/


}
