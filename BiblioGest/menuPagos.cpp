#include <iostream>
#include "rlutil.h"
using namespace std;

#include "pagos.h"
#include "pagosArchivo.h"
#include "socio.h"
#include "socioArchivo.h"
#include "PagosManager.h"
#include <cstring>


void mostrarMenuPagos() {
    int opcion;
    do {
        rlutil::cls();
        rlutil::hidecursor();

        rlutil::setColor(rlutil::CYAN);
        rlutil::locate(45, 3); cout << "B I B L I O G E S T";
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(40, 4); cout << "M O D U L O   D E   P A G O S";

        rlutil::setColor(rlutil::MAGENTA);
        for (int i = 0; i < 50; i++) {
            rlutil::locate(25 + i, 6); cout << char(205);
            rlutil::locate(25 + i, 20); cout << char(205);
        }

        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(35, 8);  cout << "1. Registrar un nuevo pago";
        rlutil::locate(35, 9);  cout << "2. Listar pagos por numero de socio";
        rlutil::locate(35, 10); cout << "3. Eliminar pago logicamente (por socio)";
        rlutil::locate(35, 11); cout << "4. Eliminar pago fisicamente (por socio)";
        rlutil::locate(35, 12); cout << "5. Historial de todos los pagos";
        rlutil::locate(35, 13); cout << "6. Buscar pagos por fecha";
        rlutil::locate(35, 14); cout << "7. Listar pagos por DNI";
        rlutil::locate(35, 15); cout << "8. Deuda de socio actual";
        rlutil::locate(35, 16); cout << "9. Deuda de socio por fecha";
        rlutil::locate(35, 16); cout << "10. Cantidad de meses adeudados";
        rlutil::locate(35, 16); cout << "11. Editar un pago";
        rlutil::locate(35, 17); cout << "0. Volver al menu principal";

        rlutil::setColor(rlutil::LIGHTGREEN);
        rlutil::locate(35, 19); cout << "Seleccione una opcion: ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(60, 19); cin >> opcion;
        if (cin.fail()) {
                cout << "ERROR: Ingreso invalido.";
                cin.clear(); cin.ignore(1000, '\n');
                break;
            }
        cin.ignore();

        SocioArchivo socioArchivo;
        PagosArchivo pagosArchivo;
        int nroSocio;

        rlutil::cls();

        switch (opcion) {
        case 1: {
            cout << "=== REGISTRAR NUEVO PAGO ===";
            cout << "Ingrese el numero de socio: ";
            cin >> nroSocio;
            if (cin.fail()) {
                cout << "ERROR: Ingreso invalido.";
                cin.clear(); cin.ignore(1000, '\n');
                break;
            }

            int pos = socioArchivo.buscar(nroSocio);
            if (pos >= 0) {
                Socio s = socioArchivo.leer(pos);
                if (!s.getEstado()) {
                    cout << "El socio esta dado de baja, desea darle el alta nuevamente? (ingrese 1 si desea dar el alta, otro numero en caso de que no lo desee):";
                    int eleccion;
                    cin>> eleccion;
                    if (cin.fail())
                    {
                        cout << "ERROR: Ingreso invalido.";
                        cin.clear(); cin.ignore(1000, '\n');
                        break;
                    }
                    if(eleccion == 1)
                    {
                        s.setEstado(true);
                        if(s.getEstado())
                        {
                            cout << "SE HA DADO EL ALTA CORRECTAMENTE " <<endl;
                        }
                        else
                        {
                            cout << "HUBO UN ERROR DANDO EL ALTA " <<endl;
                        }
                    }
                    else
                    {
                        break;
                    }
                }

                Pagos p;
                p.cargarPago(s);
                if (pagosArchivo.guardar(p)) {
                    cout << "Pago guardado correctamente.";
                } else {
                    cout << " Error al guardar el pago.";
                }
            } else {
                cout << "Socio no encontrado.";
            }
            break;
        }

        case 2: {
            cout << "=== LISTAR PAGOS POR SOCIO ===";
            cout << "Ingrese el numero de socio: ";
            cin >> nroSocio;
            if (cin.fail()) {
                cout << " ERROR: Ingreso invalido.";
                cin.clear(); cin.ignore(1000, '\n');
                break;
            }

            int total = pagosArchivo.contarRegistros();
            bool encontrado = false;
            for (int i = 0; i < total; i++) {
                Pagos p = pagosArchivo.leer(i);
                if (p.getNumeroSocio() == nroSocio && p.getEstado()) {
                    p.mostrar();
                    encontrado = true;
                    cout << "-------------------------------------";
                }
            }
            if (!encontrado)
                cout << "⚠️  No se encontraron pagos activos para este socio.";
            break;
        }

        case 3: {
            cout << "=== ELIMINAR PAGO LOGICAMENTE ===";
            cout << "Ingrese el numero de socio: ";
            cin >> nroSocio;
            if (cin.fail()) {
                cout << "❌ ERROR: Ingreso invalido.";
                cin.clear(); cin.ignore(1000, '\n');
                break;
            }
            if (pagosArchivo.eliminarLogicamente(nroSocio))
                cout << "✅ Pagos eliminados logicamente.\n";
            else
                cout << "⚠️  No se encontraron pagos activos para eliminar.";
            break;
        }

        case 4: {
            cout << "=== ELIMINAR PAGO FISICAMENTE ===";
            cout << "Ingrese el numero de socio: ";
            cin >> nroSocio;
            if (cin.fail()) {
                cout << "❌ ERROR: Ingreso invalido.\n";
                cin.clear(); cin.ignore(1000, '\n');
                break;
            }
            if (pagosArchivo.eliminarFisicamente(nroSocio))
                cout << "✅ Pagos eliminados fisicamente.";
            else
                cout << "⚠️  No se encontraron pagos para eliminar.";
            break;
        }

        case 5: {
            cout << "=== HISTORIAL COMPLETO DE PAGOS ===\n";
            int reg = pagosArchivo.contarRegistros();
            for (int i = 0; i < reg; i++) {
                Pagos p = pagosArchivo.leer(i);
                p.mostrar();
                cout << "-------------------------------------";
            }
            break;
        }

        case 6: {
            int mes, anio;
            cout << "=== BUSCAR PAGOS POR FECHA ===\n";
            cout << "Ingrese MES: ";
            cin >> mes;
            cout << "Ingrese ANIO: ";
            cin >> anio;

            int total = pagosArchivo.contarRegistros();
            bool encontrado = false;

            for (int i = 0; i < total; i++) {
                Pagos p = pagosArchivo.leer(i);
                if (p.getMesPago() == mes && p.getAnioPago() == anio) {
                    p.mostrar();
                    encontrado = true;
                    cout << "-------------------------------------";
                }
            }
            if (!encontrado)
                cout << "⚠️  No se encontraron pagos en esa fecha.";
            break;
        }

        case 7: {
            char dni[12];
            cout << "=== BUSCAR PAGOS POR DNI ===";
            cout << "Ingrese DNI del socio: ";
            cin >> dni;

            int totalSocios = socioArchivo.contarRegistros();
            int numeroSocio = -1;

            for (int i = 0; i < totalSocios; i++) {
                Socio s = socioArchivo.leer(i);
                if (strcmp(s.getDni(), dni) == 0 && s.getEstado()) {
                    numeroSocio = s.getNumeroSocio();
                    break;
                }
            }

            if (numeroSocio == -1) {
                cout << "No se encontro un socio activo con ese DNI.";
                break;
            }

            int totalPagos = pagosArchivo.contarRegistros();
            bool encontrado = false;

            for (int i = 0; i < totalPagos; i++) {
                Pagos p = pagosArchivo.leer(i);
                if (p.getNumeroSocio() == numeroSocio) {
                    p.mostrar();
                    encontrado = true;
                    cout << "-------------------------------------";
                }
            }

            if (!encontrado)
                cout << "El socio no tiene pagos registrados.";
            break;
        }

        case 8:
            {
                int nroSocio;
                cout << "Ingrese el numero de socio: " <<endl;
                cin>>nroSocio;
                if (cin.fail())
                {
                    cout << "ERROR: Ingreso invalido.";
                    cin.clear(); cin.ignore(1000, '\n');
                    break;
                }

                PagosArchivo a;
                SocioArchivo aSocio;
                int pos = socioArchivo.buscar(nroSocio);
                if (pos >= 0)
                {
                    Socio s = socioArchivo.leer(pos);
                    if(a.tieneDeuda(nroSocio))
                    {
                        cout << "EL SOCIO: " << s.getNombre() << " " << s.getApellido() << " PRESENTA DEUDA" << endl;
                    }
                    else
                    {
                        cout << "EL SOCIO: " << s.getNombre() << " " << s.getApellido() << " NO PRESENTA DEUDA" << endl;
                    }
                }
            }
            break;

        case 9:
            {
                int mes, anio, nro, socio;
                cout << "INGRESE EL NUMERO DE SOCIO: ";
                cin >> socio;
                cout << "INGRESE EL MES: ";
                cin >> mes;
                cout << "INGRESE EL ANIO: ";
                cin >> anio;
                PagosArchivo a;
                if(mes > 0 && mes < 13 && anio < 2025 && anio > 2000)
                {
                    if(a.tieneDeudaPorFecha(socio, mes, anio))
                    {
                        cout << "PRESENTA DEUDA EN EL MES INGRESADO: "<<mes<<"/"<<anio;
                    }
                    else
                    {
                        cout << "NO PRESENTA DEUDA EN EL MES INGRESADO: "<<mes<<"/"<<anio;
                    }
                }
            }
            break;
        case 10:
            {
                int nroSocio;
                PagosManager m;
                cout << "INGRESE EL NUMERO DE SOCIO: ";
                cin>>nroSocio;
                int cantMeses = m.cantidadDeMesesAdeudados(nroSocio);
                cout<<"ADEUDA "<<cantMeses<<" DE MESES"<<endl;

            }
            break;

        case 11:
            {

                PagosManager m;
                int nroSocio, mes, anio;
                bool editado = false;
                cout<<"INGRESE EL NUMERO DE SOCIO: ";
                cin>>nroSocio;
                cout<<"INGRESE EL MES DEL PAGO: ";
                cin>>mes;
                cout<<"INGRESE EL ANIO DEL PAGO: ";
                cin>>anio;

                if(nroSocio > 0 && mes > 0 && mes < 13 && anio > 2000 && anio < 2030)
                {
                    editado = m.editar(nroSocio, mes, anio);
                }

                if(editado)
                {
                    cout<<"SE HA EDITADO CORRECTAMENTE"<<endl;
                }
                else
                {
                    cout<<"HUBO PROBLEMAS EN LA EDICION"<<endl;
                }
            }
            break;
        case 0:
            cout << "Volviendo al menu principal...";
            break;

        default:
            cout << "Opcion invalida.";
            break;
        }

        rlutil::anykey();
        system("cls");

    } while (opcion != 0);
}
