#include <iostream>
using namespace std;

#include "funcionesPantallasInteractivas.h"
#include "socio.h"
#include "socioArchivo.h"
#include "pagos.h"
#include "pagosArchivo.h"
#include <cstring>

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
        cout << "5. Eliminar Socio (numero de socio)" << endl;
        cout << "6. Eliminar Socio (numero de dni)" << endl;
        cout << "7. Registrar pago" << endl;
        cout << "8. Historico de pagos" <<endl;
        cout << "0. Salir" << endl;

        cin >> opcion;
        cin.ignore();

        SocioArchivo archivo;
        Socio socio;
        int totalReg;
        int nroSocio;
        char dni[12];

        switch (opcion)
        {
        case 0:
            cout << "Saliendo del sistema..." << endl;
            break;
        case 1:
            socio.cargar();
            archivo.guardar(socio);
            break;

        case 2:
            totalReg = archivo.contarRegistros();
            for (int i = 0; i < totalReg; i++)
            {
                Socio s = archivo.leer(i);
                if (s.getEstado()) s.mostrar();
            }
            break;

        case 3:
            cout << "Ingrese el numero de socio: ";
            cin >> nroSocio;
            {
                int pos = archivo.buscar(nroSocio);
                if (pos >= 0)
                {
                    Socio s = archivo.leer(pos);
                    s.mostrar();
                }
                else
                {
                    cout << "Socio no encontrado." << endl;
                }
            }
            break;

        case 4:
            cout << "Ingrese el DNI: ";
            cin >> dni;
            {
                int total = archivo.contarRegistros();
                bool encontrado = false;
                for (int i = 0; i < total; i++)
                {
                    Socio s = archivo.leer(i);
                    if (strcmp(s.getDni(), dni) == 0 && s.getEstado())
                    {
                        s.mostrar();
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) cout << "Socio no encontrado." << endl;
            }
            break;

        case 5:
            cout << "Ingrese el numero de socio: ";
            cin >> nroSocio;
            archivo.eliminarLogicamente(nroSocio);
            break;

        case 6:
            cout << "Ingrese el DNI: ";
            cin >> dni;
            {
                int total = archivo.contarRegistros();
                bool eliminado = false;
                for (int i = 0; i < total; i++)
                {
                    Socio s = archivo.leer(i);
                    if (strcmp(s.getDni(), dni) == 0 && s.getEstado())
                    {
                        s.setEstado(false);
                        archivo.guardar(s, i);
                        eliminado = true;
                        cout << "Socio eliminado logicamente." << endl;
                        break;
                    }
                }
                if (!eliminado) cout << "Socio no encontrado o ya eliminado." << endl;
            }
            break;

       /* case 7:
            cout << "Ingrese el numero de socio: ";
            cin >> nroSocio;
            {
                int pos = archivo.buscar(nroSocio);
                if (pos >= 0)
                {
                    Socio socio = archivo.leer(pos);
                    Pagos p;
                    p.cargarPago(socio);
                    p.mostrar();

                    PagosArchivo pagosArchivo;
                    bool guardado = pagosArchivo.guardar(p);
                    if(guardado) { cout<<"SE HA GUARDADO CORRECTAMENTE!";}
                    else {"HUBO UN ERROR EN EL GUARDADO";}
                }
                else
                {
                    cout << "Socio no encontrado." << endl;
                }
            }
            break;
        case 8:
                PagosArchivo pagosArchivo;
                int reg= pagosArchivo.contarRegistros();
                for(int i = 0; i < reg; i++ )
                {
                    Pagos p = pagosArchivo.leer(i);
                    p.mostrar();

                }

            break;*/

        default:
            cout << "Opcion invalida." << endl;
            break;
        }

        system("pause");
        system("cls");

    } while (opcion != 0);
}
