#include <iostream>
#include <string.h>
#include "rlutil.h"
using namespace std;
#include "Libro.h"
#include "Generos.h"
#include "Autores.h"
#include "archivoLibros.h"
#include "ArchivoAutores.h"
#include "ArchivoGeneros.h"
#include "funcionesPantallasInteractivas.h"


Libro::Libro()
{
    strcpy(_ISBN,"-");
    strcpy(_titulo,"-");
    _IDAutor=0;
    _IDGenero=0;
    _fechaPubli= Fecha();
    _cantDisponible=0;
}

Libro::Libro(const char* ISBN,const char* titulo,int IDautor, int IDgenero, Fecha fechaPubli, int cantDisponible)
{
    strcpy(_ISBN, ISBN);
    strcpy(_titulo, titulo);
    _IDAutor=IDautor;
    _IDGenero=IDgenero;
    _fechaPubli= fechaPubli;
    _cantDisponible= cantDisponible;
}

const char* Libro::getISBN()
{
    return _ISBN;
}
const char* Libro::getTitulo()
{
    return _titulo;
}
int Libro::getIDAutor()
{
    return _IDAutor;
}
int Libro::getIDGenero()
{
    return _IDGenero;
}
Fecha Libro::getFechaPubli()
{
    return _fechaPubli;
}
int Libro::getCantDisponible()
{
    return _cantDisponible;
}

void Libro::setISBN(const char* ISBN)
{
    strcpy(_ISBN, ISBN);
}
void Libro::setTitulo (const char *titulo)
{
    strcpy(_titulo, titulo);
}
void Libro::setIDAutor (int IDautor)
{
    _IDAutor=IDautor;
}
void Libro::setIDGenero (int IDgenero)
{
    _IDGenero=IDgenero;
}
void Libro::setFecha (Fecha fechaPubli)
{
    _fechaPubli= fechaPubli;
}
void Libro::setCantiDisponible (int cantDisponible)
{
    _cantDisponible= cantDisponible;
}
void Libro::cargarLibro()
{
    int opcion;
    Generos gen;
    GeneroArchivo arcGenero;
    Autores au;
    AutoresArchivo arcAutores;
    char autorLibro[50];
    char generoLibro[20];
    cout << "PORFAVOR ESCRIBA LOS SIGUIENTES DATOS DEL LIBRO QUE DESEA:"<< endl;
    //SE COMIENZA LA CARGA DE GENEROS
    cout << "GENERO:";
    cin.getline(generoLibro, 20);
    int cantGeneros=arcGenero.contarRegistros();
    //SE VALIDA SI EXISTE EL GENERO INGRESADO
    bool generoEncontrado=false;
    for(int i=0; i<cantGeneros; i++)
    {
        gen=arcGenero.leer(i);
        if (strcmp(gen.getGenero(), generoLibro) == 0)
        {
//SI EXISTE SE ATRIBUYE EL RESPECTIVO ID AL GENERO
            _IDGenero=gen.getIDGenero();
            generoEncontrado=true;
        }
    }
    //CASO CONTRARIO SE CARGARA UNO NUEVO
    if(generoEncontrado==false)
    {

        cout<< "PARECE QUE NO EXISTE ESTE GENERO EN NUESTRA BASE DE DATOS, PORFAVOR PRESIONA 1 Y LUEGO <<ENTER>> PARA AGREGAR UN NUEVO GENERO"<<endl;
        cin >> opcion;
        cin.ignore();

        if (opcion==1)
        {
            //rlutil::cls();
            gen.cargarGenero();
            if (arcGenero.guardar(gen))
            {
                int posUltimo = arcGenero.contarRegistros() - 1;
                gen = arcGenero.leer(posUltimo);
                _IDGenero = gen.getIDGenero();
                cout<<"GENERO GUARDADO EXITOSAMENTE";

            }
            else
            {
                cout <<"ERROR AL GUARDAR NUEVO GENERO";
            }
        }
        else
        {
            cout << "ERROR-PORFAVOR INGRESE EL VALOR INDICADO (1 Y <ENTER>)"<<endl;
            return;
        }
    }

    //SE COMIENZA LA CARGA DE AUTORES
    cout << "AUTORES:";
    cin.getline(autorLibro, 50);
    int cantAutores=arcAutores.contarRegistros();
    //SE VALIDA SI EXISTE EL AUTOR INGRESADO
    bool autorEncontrado=false;
    for(int i=0; i<cantAutores; i++)
    {
        au=arcAutores.leer(i);
        if (strcmp(au.getAutor(), autorLibro) == 0)
        {
            //SI EXISTE SE ATRIBUYE EL RESPECTIVO ID DEL AUTOR
            _IDAutor=au.getIDAutor();
            autorEncontrado=true;
        }
    }
    //CASO CONTRARIO SE CARGARA UNO NUEVO
    if(autorEncontrado==false)
    {

        cout<< "PARECE QUE NO EXISTE ESTE AUTOR EN NUESTRA BASE DE DATOS, PORFAVOR PRESIONA 2 Y LUEGO <<ENTER>> PARA AGREGAR UN NUEVO GENERO"<<endl;
        cin >> opcion;
        cin.ignore();

        if (opcion==2)
        {
            //rlutil::cls();
            au.cargarAutor();
            if (arcAutores.guardar(au))
            {
                int posUltimo = arcAutores.contarRegistros() - 1;
                au = arcAutores.leer(posUltimo);
                _IDAutor = au.getIDAutor();
                cout<<"AUTOR GUARDADO EXITOSAMENTE";
            }
            else
            {
                cout <<"ERROR AL GUARDAR NUEVO AUTOR";
            }
        }
        else
        {
            cout << "ERROR-PORFAVOR INGRESE EL VALOR INDICADO (2 Y <ENTER>)"<<endl;
            return;
        }
    }
    cin.ignore();

    cout << "ISBN:";
    cin.getline(_ISBN, 14);
    cout << endl;

    cout << "TITULO:";
    cin.getline(_titulo, 50);
    cout << endl;

    cout << "FECHA DE PUBLICACION:";
    this ->_fechaPubli.cargar();
    cout << endl;
    cout << "CANTIDAD DE UNIDADES:";
    cin >> _cantDisponible;
    cout << endl;
};

void Libro::mostrarLibro()
{
    GeneroArchivo arcGenero;
    AutoresArchivo arcAutor;

    Generos genero;
    Autores autor;

    genero = arcGenero.leer(_IDGenero - 1);

    autor = arcAutor.leer(_IDAutor - 1);

    cout<<"==================================="<<endl;
    cout << "ISBN:"<< _ISBN << endl;

    cout << "TITULO:" << _titulo << endl;

    cout<< "GENERO:"<<genero.getGenero()<< endl;

    cout << "AUTOR:"<<autor.getAutor()<< endl;

    cout << "FECHA DE PUBLICACION:"<< _fechaPubli<< endl;

    cout << "CANTIDAD DISPONIBLE:" << _cantDisponible << endl;
    cout<<"==================================="<<endl;

};
void Libro::editarLibro()
{
    //SOLO SE EDITA LO YA EXISTENTE. CANT DISPONIBLE SE ACTUALIZA AUTOMATICAMENTE.
    LibroArchivo arcLibro;
    char isbnElegido[14];
    cout<< "INGRESE EL ISBN DEL LIBRO QUE DESEA EDITAR"<<endl;
    cout << "ISBN:";
    cin.getline(isbnElegido, 14);
    cin.ignore();
    int pos = arcLibro.buscarISBN(isbnElegido);
    if (pos < 0)
    {
        cout << "NO SE ENCONTRO EL LIBRO CON ESE ISBN" << endl;
        return;
    }
    Libro lib = arcLibro.leer(pos);
    int opcion;
    do
    {
        cout << "AHORA SELECCIONE QUE DATO DEL LIBRO DESEA EDITAR:"<<endl;
        cout << "1-ISBN"<<endl;
        cout << "2-TITULO"<<endl;
        cout << "3-GENERO" <<endl;
        cout << "4-AUTOR"<<endl;
        cout << "5-FECHA DE PUBLICACION"<<endl;
        cout << "0-VOLVER A MENU LIBROS"<<endl;
        cin >> opcion;
        cin.ignore();
        switch(opcion)
        {
        case 1:
            cout << "NUEVO ISBN: ";
            cin.getline(lib._ISBN, 14);
            break;
        case 2:
            cout << "NUEVO TITULO: ";
            cin.getline(lib._titulo, 50);
            break;
        case 3:
        {

            GeneroArchivo arcGenero;
            int op;
            Generos gen;
            arcGenero.mostrarListadoGeneros();
            cout << "SI NO ENCUENTRA EL GENERO QUE BUSCA EN ESTA LISTA, PRESIONE:" << endl;
            cout << "1 - PARA CARGAR UNO NUEVO" << endl;
            cout << "2 - PARA INGRESAR EL ID DE UN GENERO DE LA LISTA" << endl;
            cout << "OPCION: ";
            cin>>op;
            cin.ignore();
            if (op==1)
            {
                cout<<endl;
                cout << "NUEVO GENERO: ";
                gen.cargarGenero();
                if (arcGenero.guardar(gen))
                {
                int posUltimo = arcGenero.contarRegistros() - 1;
                gen = arcGenero.leer(posUltimo);
                lib._IDGenero = gen.getIDGenero();
                    cout<<"GENERO GUARDADO EXITOSAMENTE";

                }
                else

                    cout <<"ERROR AL GUARDAR NUEVO GENERO";
            }
            else if (op == 2)
            {
                cout << "INGRESE EL ID DE GENERO: ";
                cin >> lib._IDGenero;
                cin.ignore();
            }
            else
            {
                cout << "VALOR INVALIDO - SOLO INGRESE 1 O 2" << endl;
            }
        }
        break;
        case 4:
        {
            int op;
            Autores au;
            AutoresArchivo arcAutor;
            arcAutor.mostrarListadoAutores();
            cout << "SI NO ENCUENTRA EL AUTOR QUE BUSCA EN ESTA LISTA, PRESIONE:" << endl;
            cout << "1 - PARA CARGAR UNO NUEVO" << endl;
            cout << "2 - PARA INGRESAR EL ID DE UN AUTOR DE LA LISTA" << endl;
            cout << "OPCION: ";
            cin>>op;
            cin.ignore();
            if (op==1)
            {
                cout<<endl;
                cout << "NUEVO AUTOR: ";
                au.cargarAutor();
                if (arcAutor.guardar(au))
                {
                int posUltimo = arcAutor.contarRegistros() - 1;
                au = arcAutor.leer(posUltimo);
                  lib._IDAutor = au.getIDAutor();
                    cout<<"AUTOR GUARDADO EXITOSAMENTE";

                }
                else

                    cout <<"ERROR AL GUARDAR NUEVO AUTOR";
            }
            else if (op == 2)
            {

                cout << "NUEVO ID DE AUTOR: ";
                cin >> lib._IDAutor;
                cin.ignore();
            }
        }

        break;
        case 5:
            cout << "NUEVA FECHA DE PUBLICACION:" << endl;
            lib._fechaPubli.cargar();
            break;
        case 0:
            rlutil::cls();
            mostrarMenuLibros();
            break;
        }
    }
    while(opcion!=0);
};
void Libro::disponibilidadLibro()
{
//getISBN
//if IDLibroPrestamo==ISBN //lo mismo para devoluciones pero ++ cantDisponible
//cantDisponible--;
//bool disponibilidad;

    if (_cantDisponible==0)
    {

        rlutil::setColor(rlutil::RED);
        cout <<"NO DISPONIBLE";
    }
    else
    {
        rlutil::setColor(rlutil::GREEN);
        cout << "DISPONIBLE";
    }
};
