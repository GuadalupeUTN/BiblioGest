#include <iostream>
#include <cstring>
using namespace std;
#include "Menu.h"
#include "Socio.h"
#include "SocioArchivo.h"

void Menu::ejecutar()
{
    int opcion;
    do
    {
        cout << "-------------------------" << endl;
        cout << "  SISTEMA DE BIBLIOTECA  " << endl;
        cout << "-------------------------" << endl;
        cout << "1. Registrar nuevo socio" << endl;
        cout << "2. Listar todos los socios" << endl;
        cout << "3. Buscar Socio (numero de socio)" << endl;
        cout << "4. Buscar Socio (numero de dni)" << endl;
        cout << "0. Salir" << endl;
        cout << "-------------------------" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            registrarSocio();
            break;
        case 2:
            listarSocios();
            break;
        case 3:
            buscarSocio();
            break;
        case 4:
            buscarSocioDni();
            break;
        case 0:
            cout << "Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
            break;
        }

        system("pause");
        system("cls");

    }
    while(opcion != 0);
}

void Menu::registrarSocio()
{
    Socio s;
    SocioArchivo archivo;

    s.cargar();
    if (archivo.guardar(s))
    {
        cout << "Socio guardado correctamente." << endl;
    }
    else
    {
        cout << "Error al guardar el socio." << endl;
    }
}

void Menu::listarSocios()
{
    SocioArchivo archivo;
    int total = archivo.contarRegistros();

    if (total == 0)
    {
        cout << "No hay socios registrados." << endl;
        return;
    }

    for (int i = 0; i < total; i++)
    {
        Socio s = archivo.leer(i);
        cout << "--------------------------" << endl;
        s.mostrar();
    }
}

void Menu::buscarSocio()
{
    int nroSocio;

    cout<<"INGRESE EL NUMERO DE SOCIO: ";
    cin>>nroSocio;

    SocioArchivo archivo;
    int posicion = archivo.buscar(nroSocio);

    int listarSocios = archivo.contarRegistros();

    if(posicion == 0)
    {
        cout<<"No existe ese numero de socio";
    }

    for(int i = 0; i < listarSocios; i++)
    {
        Socio socio = archivo.leer(i);
        if (socio.getNumeroSocio() == nroSocio)
        {
            socio.mostrar();
        }
    }
}
void Menu::buscarSocioDni()
{
    string d;
    cout << "INGRESE EL NUMERO DE DNI: ";
    cin >> d;

    // Validar tamaño
    if (d.length() > 11)
    {
        cout << "DNI demasiado largo. Máximo 11 caracteres." << endl;
        return;
    }

    SocioArchivo archivo;
    int total = archivo.contarRegistros();
    bool encontrado = false;

    for (int i = 0; i < total; i++)
    {
        Socio s = archivo.leer(i);
        if (strcmp(s.getDni(), d.c_str()) == 0)
        {
            cout << "Socio encontrado:" << endl;
            s.mostrar();
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
    {
        cout << "No se encontró un socio con ese DNI." << endl;
    }
}

