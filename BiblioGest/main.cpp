#include <iostream>

using namespace std;
#include "Libro.h"
#include "Fecha.h"
#include "Generos.h"
#include "Autores.h"
#include "ArchivoGeneros.h"
#include "ArchivoAutores.h"
#include "funcionesPantallasInteractivas.h"
int main()
{
    //Menu _menu;

    //_menu.ejecutar();

 mostrarMenuPrincipal();
  // Generos::inicializarID();
  // Autores::inicializarID();
   //PRUEBAS LIBROS
   //PRUEBAS AUTORES
/*
Autores autor1;
autor1.cargarAutor();
if (arc.guardar(autor1)){
    cout<<"GUARDADO";
}
else cout <<"ERROR";

   //PRUEBAS GENEROS
Generos genero1;
genero1.cargarGenero();
if (arc.guardar(genero1)){
    cout<<"GUARDADO";
}
else cout <<"ERROR";
GeneroArchivo arc;

//LEER TODOS LOS ARC CON MEM DINAMIC
AutoresArchivo arc;
int cantidad = arc.contarRegistros();
Autores* vector = new Autores[cantidad];

arc.leerTodos(cantidad, vector);

for (int i = 0; i < cantidad; i++) {
    vector[i].mostrarAutor();
}

delete[] vector;
*/
    return 0;
}
