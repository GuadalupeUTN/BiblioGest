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
    rlutil::cls();
    rlutil::showcursor();
    int op;
    Libro milibro;
    LibroArchivo arcLibro;
    do
    {
        rlutil::setColor(rlutil::MAGENTA);
        cout <<"NUESTROS LIBROS"<<endl;
        rlutil::setColor(rlutil::WHITE);
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
            rlutil::cls();
            rlutil::setColor(rlutil::MAGENTA);
            cout << "================ REGISTRO DE NUEVO LIBRO ================" << endl;
            rlutil::setColor(rlutil::WHITE);
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
            rlutil::cls();
            rlutil::setColor(rlutil::MAGENTA);
            cout<<"================ NUESTRA BIBLIOTECA ================" <<endl;
            rlutil::setColor(rlutil::WHITE);
            arcLibro.mostrarListadoLibros();
            rlutil::showcursor();
            rlutil::setColor(rlutil::MAGENTA);
            cout <<"PRESIONE 1 PARA VOLVER AL MENU PRINCIPAL:";
            rlutil::setColor(rlutil::WHITE);
            int volver;
            cin >>volver;
            if (volver==1)
            {
                mostrarMenuLibros();

            }
            else cout<<"VALOR NO VALIDO. PORFAVOR INGRESE EL VALOR INDICADO";

        }
        break;
        case 3:
        {
            rlutil::cls();
            cout << "================ EDITAR UN LIBRO ================" << endl;
            rlutil::setColor(rlutil::WHITE);
            milibro.editarLibro();
        }
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
            rlutil::showcursor();
            rlutil::setColor(rlutil::MAGENTA);
            cout <<"PRESIONE 1 PARA VOLVER AL MENU PRINCIPAL:";
            rlutil::setColor(rlutil::WHITE);
            int volver;
            cin >>volver;
            if (volver==1)
            {
                mostrarMenuLibros();

            }
            else cout<<"VALOR NO VALIDO. PORFAVOR INGRESE EL VALOR INDICADO";
        }
        break;
        case 6:
        {
            rlutil::cls();
            rlutil::setColor(rlutil::MAGENTA);
            cout << "================ FILTRAR POR GENERO ================" << endl;
            rlutil::setColor(rlutil::WHITE);
            GeneroArchivo arcGenero;
            arcGenero.mostrarListadoGeneros();
            rlutil::showcursor();

            rlutil::setColor(rlutil::MAGENTA);
            ///FALTA FILTRO PARA ENCONTRAR LIBROS CON ID DE ESE GENERO
            cout<< "INGRESE EL ID GENERO DE LOS LIBROS QUE DESEA ENCONTRAR. SI NO ENCUENTRA EL GENERO QUE DESEA EN ESTA LISTA, LAMENTAMOS INFORMARLE QUE NO CONTAMOS CON EJEMPLARES POR EL MOMENTO."<<endl;
            cout << "GENERO:";
            int idGen;
            cin >> idGen;
            //SE VUELVE AL MENU
            rlutil::setColor(rlutil::MAGENTA);
            cout <<"PRESIONE 1 PARA VOLVER AL MENU PRINCIPAL:";
            rlutil::setColor(rlutil::WHITE);
            int volver;
            cin >>volver;
            if (volver==1)
            {
                mostrarMenuLibros();

            }
            else cout<<"VALOR NO VALIDO. PORFAVOR INGRESE EL VALOR INDICADO";
        }
        break;
        case 7:
        {            rlutil::cls();
            rlutil::setColor(rlutil::MAGENTA);
            cout << "================ FILTRAR POR AUTOR/A ================" << endl;
                        rlutil::setColor(rlutil::WHITE);
            AutoresArchivo arcAutores;
            arcAutores.mostrarListadoAutores();

                        rlutil::setColor(rlutil::MAGENTA);
            cout <<"PRESIONE 1 PARA VOLVER AL MENU PRINCIPAL:";
            rlutil::setColor(rlutil::WHITE);
            int volver;
            cin >>volver;
            if (volver==1)
            {
                mostrarMenuLibros();

            }
            else cout<<"VALOR NO VALIDO. PORFAVOR INGRESE EL VALOR INDICADO";
        }

        break;
        case 0:
            op=0;
            mostrarMenuPrincipal();
            break;
        }
    }
    while(op>0);
}



