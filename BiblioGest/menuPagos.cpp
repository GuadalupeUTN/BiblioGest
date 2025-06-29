#include <iostream>
using namespace std;

#include "pagos.h"
#include "pagosArchivo.h"
#include "socio.h"
#include "socioArchivo.h"
#include <cstring>

void mostrarMenuPagos() {
    int opcion;
    do {
        cout << "PAGOS" << endl;
        cout << "1. Registrar un nuevo pago" << endl;
        cout << "2. Listar pagos por numero de socio" << endl;
        cout << "3. Eliminar pago logicamente (por numero de socio)" << endl;
        cout << "4. Eliminar pago fisicamente (por numero de socio)" << endl;
        cout << "5. Historial de pagos" << endl;
        cout << "0. Volver al menu principal" << endl;

        cin >> opcion;
        cin.ignore();

        SocioArchivo socioArchivo;
        PagosArchivo pagosArchivo;
        int nroSocio;

        switch (opcion) {
        case 1:
            cout << "Ingrese el numero de socio: ";
            cin >> nroSocio;
            {
                int pos = socioArchivo.buscar(nroSocio);
                if (pos >= 0) {
                    Socio s = socioArchivo.leer(pos);
                    if (!s.getEstado()) {
                        cout << "El socio está dado de baja." << endl;
                        break;
                    }

                    Pagos p;
                    p.cargarPago(s);
                    if (pagosArchivo.guardar(p)) {
                        cout << "Pago guardado correctamente." << endl;
                    } else {
                        cout << "Error al guardar el pago." << endl;
                    }
                } else {
                    cout << "Socio no encontrado." << endl;
                }
            }
            break;

        case 2:
            cout << "Ingrese el numero de socio: ";
            cin >> nroSocio;
            {
                int total = pagosArchivo.contarRegistros();
                bool encontrado = false;
                for (int i = 0; i < total; i++) {
                    Pagos p = pagosArchivo.leer(i);
                    if (p.getNumeroSocio() == nroSocio && p.getEstado()) {
                        p.mostrar();
                        encontrado = true;
                    }
                }
                if (!encontrado) cout << "No se encontraron pagos activos para este socio." << endl;
            }
            break;

        case 3:
            cout << "Ingrese el numero de socio: ";
            cin >> nroSocio;
            if (pagosArchivo.eliminarLogicamente(nroSocio)) {
                cout << "Pagos eliminados logicamente para el socio." << endl;
            } else {
                cout << "No se encontraron pagos activos para eliminar." << endl;
            }
            break;

        case 4:
            cout << "Ingrese el numero de socio: ";
            cin >> nroSocio;
            if (pagosArchivo.eliminarFisicamente(nroSocio)) {
                cout << "Pagos eliminados fisicamente." << endl;
            } else {
                cout << "No se encontraron pagos para eliminar." << endl;
            }
            break;
        case 5:
            {
                PagosArchivo pagosArchivo;
                int reg= pagosArchivo.contarRegistros();
                for(int i = 0; i < reg; i++ )
                {
                    Pagos p = pagosArchivo.leer(i);
                    p.mostrar();

                }
            }

            break;

        case 0:
            cout << "Volviendo al menu principal..." << endl;
            break;

        default:
            cout << "Opcion invalida." << endl;
            break;
        }

        system("pause");
        system("cls");

    } while (opcion != 0);
}
