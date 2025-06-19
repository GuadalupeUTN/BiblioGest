#include <iostream>

using namespace std;
#include "funcionesPantallasInteractivas.h"
#include "Libro.h"
#include "archivoLibros.h"
#include <cstring>
void mostrarMenuLibros()
{
    int op;
    Libro milibro;
    LibroArchivo archivo;
    do
    {

        cout <<"NUESTROS LIBROS"<<endl;
        cout<<"1-Cargar libro"<<endl;
        cout<<"2-Mostrar libro"<<endl;
        cout<<"3-Editar libro"<<endl;
        cout<<"4-Disponibilidad"<<endl;
        cout<<"5-Buscar por ISBN"<<endl;
        cout <<"0-Salir"<<endl;

        cin >> op;
        cin.ignore();

        switch(op)
        {
        case 1:
        {
            cout<<endl;
            milibro.cargarLibro();
            if(archivo.guardar(milibro))
            {
                cout << "Libro guardado exitosamente." << endl;
            }
            else
            {
                cout << "Error al guardar el libro." << endl;
            }
        }

        break;
        case 2:
            cout<<endl;
            milibro.mostrarLibro();

            break;
        case 3:
            cout<<endl;

            milibro.editarLibro();
            break;
        case 4:
            cout<<endl;
            milibro.disponibilidadLibro();
            break;
        case 5:
           /* cout<<endl;
            char isbn[13];
            cout << "PORFAVOR INGRESE EL CODIGO ISBN: ";
            cin >> isbn;
            if (isbn>13)
            {
                cout << "CODIGO NO VALIDO-MAXIMO 13 CARACTERES" << endl;
            }

            int total = archivo.contarRegistros();
            bool encontrado = false;

            for (int i=0; i<total; i++)
            {
                milibro = archivo.leer(i);
                if (strcmp(milibro.getISBN(), isbn.c_str()) == 0)
                {
                    cout << "LIBRO ENCONTRADO:" << endl;
                    milibro.mostrarLibro();
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado)
            {
                cout << "Lo sentimos, no se encontró ningun libro con ese ISBN." << endl;
            }*/
            break;
        case 0:
            op=0;
            break;
        }
    }
    while(op>0);
}



