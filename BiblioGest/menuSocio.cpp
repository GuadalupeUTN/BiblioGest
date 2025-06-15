 #include <iostream>
using namespace std;

#include "funcionesPantallasInteractivas.h"
#include "socio.h"
#include "socioArchivo.h"

void mostrarMenuSocio()
{
    int opcion;
    do
    {
        cout << "SOCIOS" << endl;
        cout << "1. Registrar nuevo socio" << endl;
        cout << "2. Listar todos los socios" << endl;
        cout << "3. Buscar Socio (numero de socio)" << endl;
        cout << "4. Buscar Socio (numero de dni)" << endl;
        cout << "5. Eliminar Socio (numero de socio)" <<endl;
        cout << "6. Eliminar Socio (numero de dni)" <<endl;
        cout << "0. Salir" << endl;

        cin>>opcion;
        cin.ignore();

        SocioArchivo archivo;
        Socio socio;
        int totalReg;
        int nroSocio;
        char dni[12];

        switch(opcion)
            {
            case 1:
                socio.cargar();
                archivo.guardar(socio);
                break;
            case 2:
                totalReg = archivo.contarRegistros();

                for(int i = 0; i < totalReg; i++)
                {
                    Socio s = archivo.leer(i);
                    if(s.getEstado()) { s.mostrar(); }
                }
                break;
            case 3:
                cout << "Ingrese el numero de socio: "<<endl;
                nroSocio;
                cin>>nroSocio;

                archivo.buscar(nroSocio);
                break;
            case 4:
                cout << "Ingrese el dni: " <<endl;
                int dni;
                archivo.buscar(dni);

                break;
            case 5:
                cout << "Ingrese el numero de socio: " <<endl;
                nroSocio;
                cin>>nroSocio;

                archivo.eliminarLogicamente(nroSocio);
                break;
            case 6:
                cout << "Ingrese el dni: " <<endl;
                cin>>dni;
                archivo.eliminarLogicamente(dni);
                break;
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
            }

    }while(opcion != 0);
}
