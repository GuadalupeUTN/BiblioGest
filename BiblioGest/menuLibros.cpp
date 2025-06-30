#include <iostream>
#include <cstring>
#include "rlutil.h"
using namespace std;
#include "funcionesPantallasInteractivas.h"
#include "Libro.h"
#include "archivoLibros.h"
#include "ArchivoGeneros.h"
#include "ArchivoAutores.h"
void mostrarMenuLibros()
{
    int op;
    Libro milibro;
    LibroArchivo arcLibro;
    do
    {

        cout <<"NUESTROS LIBROS"<<endl;
        cout<<"1-REGISTRAR NUEVO LIBRO"<<endl;
        cout<<"2-NUESTRA BIBLIOTECA"<<endl;
        cout<<"3-EDITAR LIBRO"<<endl;
        cout<<"4-BAJA DE LIBRO"<<endl;
        cout<<"5-ENCONTRAR POR ISBN"<<endl;
        cout<<"6-ENCONTRAR POR GENERO"<<endl;
        cout<<"7-ENCONTRAR POR AUTOR/A"<<endl;
        cout <<"0-VOLVER A MENU PRINCIPAL"<<endl;

        cin >> op;
        cin.ignore();

        switch(op)
        {
        case 1:
        {
            cout<<endl;
            cout << "================ REGISTRO DE NUEVO LIBRO ================" << endl;
            milibro.cargarLibro();
            if(arcLibro.guardar(milibro))
            {
                cout << "LIBRO GUARDADO" << endl;
            }
            else
            {
                cout << "ERROR-NO SE PUDO GUARDAR EL LIBRO" << endl;
            }
        }

        break;
        case 2:
        {
            cout<<"================ NUESTRA BIBLIOTECA ================" <<endl;

            arcLibro.mostrarListadoLibros();
        }
        break;
        case 3:
        {
            rlutil::cls();
            cout << "================ EDITAR UN LIBRO ================" << endl;
            milibro.editarLibro();}
        break;
        case 4:
            cout << "================ BAJA DE LIBRO ================" << endl;
            break;
        case 5:
        {
            rlutil::cls(),
                   cout << "================ ENCONTRAR POR ISBN ================" << endl;
            char isbnElegido[14];
            cout<< "INGRESE EL ISBN DEL LIBRO QUE DESEA ENCONTRAR"<<endl;
            cout << "ISBN:";
            cin.getline(isbnElegido, 14);
            cin.ignore();
            int pos = arcLibro.buscarISBN(isbnElegido);
            if (pos < 0)
            {
                cout << "NO SE ENCONTRO EL LIBRO CON ESE ISBN" << endl;
                return;
            }
            else cout <<"SE ENCONTRO EL SIGUIENTE RESULTADO:"<<endl;
            Libro lib = arcLibro.leer(pos);
            lib.mostrarLibro();
        }
        break;
        case 6:
        {
            rlutil::cls();
            cout << "================ FILTRAR POR GENERO ================" << endl;
            cout<< "INGRESE EL ID GENERO DE LOS LIBROS QUE DESEA ENCONTRAR. SI NO ENCUENTRA EL GENERO QUE DESEA EN ESTA LISTA, LAMENTAMOS INFORMARLE QUE NO CONTAMOS CON EJEMPLARES POR EL MOMENTO."<<endl;
            cout << "GENERO:";
            int idGen;
            GeneroArchivo arcGenero;
            cin >> idGen;
            arcGenero.mostrarListadoGeneros();
        }
        break;
        case 7:
        {
            cout << "================ ENCONTRAR POR AUTOR/A ================" << endl;
        }
        break;
        case 0:
            op=0;
            break;
        }
    }
    while(op>0);
}



