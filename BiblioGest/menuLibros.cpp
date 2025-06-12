#include <iostream>

using namespace std;
#include "funcionesPantallasInteractivas.h"
#include "Libro.h"
#include "archivoLibros.h"

void mostrarMenuLibros()
{
    int op;
    Libro milibro;
    do
    {

        cout <<"NUESTROS LIBROS"<<endl;
        cout<<"1-Cargar libro"<<endl;
        cout<<"2-Mostrar libro"<<endl;
        cout<<"3-Editar libro"<<endl;
        cout<<"4-Disponibilidad"<<endl;
        cout <<"0-Salir"<<endl;

        cin >> op;
        cin.ignore();

        switch(op)
        {
        case 1:
            cout<<endl;
            milibro.cargarLibro();
          /* ArchivoLibros archi("arhcivoLibros.dat");

            if (archi.agregarRegistroLibro(milibro))
            {
                cout << "Libro guardado correctamente." << endl;
            }
            else

                cout << "Error al guardar el libro." << endl;*/

            break;
        case 2:
            cout<<endl;
         //  milibro = archi.leerRegistroLibro(0);
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
        case 0:
            op=0;
            break;
        }
    }while(op>0);

};


