#include <iostream>
#include "rlutil.h"
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
        rlutil::cls();
        rlutil::hidecursor();

        // TÍTULO SUPERIOR
        rlutil::setColor(rlutil::CYAN);
        rlutil::locate(45, 3);
        cout << "B I B L I O G E S T" << endl;

        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(38, 4);
        cout << "S I S T E M A   D E   S O C I O S" << endl;

        // MARCO
        rlutil::setColor(rlutil::MAGENTA);
        for (int i = 0; i < 50; i++) {
            rlutil::locate(25 + i, 6); cout << char(205);
            rlutil::locate(25 + i, 18); cout << char(205);
        }

        // OPCIONES
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(35, 8);  cout << "1. Registrar nuevo socio";
        rlutil::locate(35, 9);  cout << "2. Listar todos los socios";
        rlutil::locate(35, 10); cout << "3. Buscar Socio (numero de socio)";
        rlutil::locate(35, 11); cout << "4. Buscar Socio (numero de DNI)";
        rlutil::locate(35, 12); cout << "5. Dar de baja Socio (numero de socio)";
        rlutil::locate(35, 13); cout << "6. Dar de baja Socio (numero de DNI)";
        rlutil::locate(35, 14); cout << "0. Volver al menu principal";

        rlutil::setColor(rlutil::LIGHTGREEN);
        rlutil::locate(35, 16); cout << "Seleccione una opcion: ";
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(60, 16); cin >> opcion;
        if (cin.fail())
        {
            break;
        }

        cin.ignore();

        SocioArchivo archivo;
        Socio socio;
        int totalReg;
        int nroSocio;
        char dni[12];

        switch (opcion)
        {
        case 0:
            return;

        case 1:
        rlutil::cls();
        rlutil::setColor(rlutil::CYAN);
        cout << "================ REGISTRO DE NUEVO SOCIO ================" << endl;
        rlutil::setColor(rlutil::WHITE);

        socio.cargar();

        if (archivo.existeDni(socio.getDni())) {
            rlutil::setColor(rlutil::RED);
            cout << "Ya existe un socio registrado con ese DNI." << endl;
            break;
        }

        archivo.guardar(socio);
        rlutil::setColor(rlutil::GREEN);
        cout << "Socio registrado exitosamente." << endl;
        break;


        case 2:
            {
                rlutil::cls();
                rlutil::setColor(rlutil::CYAN);
                cout << "================ LISTADO DE SOCIOS ================" << endl;
                rlutil::setColor(rlutil::WHITE);

                totalReg = archivo.contarRegistros();
                bool hayActivos = false;
                for (int i = 0; i < totalReg; i++) {
                    Socio s = archivo.leer(i);
                    if (s.getEstado()) {
                        s.mostrar();
                        hayActivos = true;
                        cout << "--------------------------------------------------------" << endl;
                    }
                }
                if (!hayActivos) {
                    rlutil::setColor(rlutil::RED);
                    cout << " No hay socios activos cargados en el sistema." << endl;
                }
            }

        break;


        case 3:
        rlutil::cls();
        rlutil::setColor(rlutil::CYAN);
        cout << "=============== BUSCAR SOCIO POR NRO ===============" << endl;
        rlutil::setColor(rlutil::WHITE);

        cout << "Ingrese el numero de socio: ";
        cin >> nroSocio;

        if (cin.fail()) {
            errorMessage(2);
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }

        {
            int pos = archivo.buscar(nroSocio);
            if (pos >= 0) {
                Socio s = archivo.leer(pos);
                s.mostrar();
            } else {
                rlutil::setColor(rlutil::RED);
                cout << "Socio no encontrado." << endl;
            }
        }
        break;

        case 4:
        rlutil::cls();
        rlutil::setColor(rlutil::CYAN);
        cout << "=============== BUSCAR SOCIO POR DNI ===============" << endl;
        rlutil::setColor(rlutil::WHITE);

        cout << "Ingrese el DNI: ";
        cin >> dni;

        if (validarDNI(dni)) {
            int total = archivo.contarRegistros();
            bool encontrado = false;

            for (int i = 0; i < total; i++) {
                Socio s = archivo.leer(i);
                if (strcmp(s.getDni(), dni) == 0 && s.getEstado()) {
                    s.mostrar();
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado) {
                rlutil::setColor(rlutil::RED);
                cout << "Socio no encontrado o no está activo." << endl;
            }

        } else {
            errorMessage(1);
        }
        break;


        case 5:
        rlutil::cls();
        rlutil::setColor(rlutil::CYAN);
        cout << "=============== ELIMINAR SOCIO POR NRO ===============" << endl;
        rlutil::setColor(rlutil::WHITE);

        cout << "Ingrese el numero de socio: ";
        cin >> nroSocio;

        if (cin.fail()) {
            errorMessage(2);
            cin.clear();
            cin.ignore(1000, '\n');
            break;
        }

        archivo.eliminarLogicamente(nroSocio);
        rlutil::setColor(rlutil::GREEN);
        cout << "Socio dado de baja del sistema." << endl;
        break;


        case 6:
        rlutil::cls();
        rlutil::setColor(rlutil::CYAN);
        cout << "=============== ELIMINAR SOCIO POR DNI ===============" << endl;
        rlutil::setColor(rlutil::WHITE);

        cout << "Ingrese el DNI: ";
        cin >> dni;

        if (validarDNI(dni)) {
            int total = archivo.contarRegistros();
            bool eliminado = false;

            for (int i = 0; i < total; i++) {
                Socio s = archivo.leer(i);
                if (strcmp(s.getDni(), dni) == 0 && s.getEstado()) {
                    s.setEstado(false);
                    archivo.guardar(s, i);
                    eliminado = true;
                    rlutil::setColor(rlutil::GREEN);
                    cout << "Socio dado de baja." << endl;

                    break;
                }
            }

            if (!eliminado) {
                rlutil::setColor(rlutil::RED);
                cout << "Socio no encontrado o ya estaba eliminado." << endl;
            }

        } else {
            errorMessage(1);
        }
        break;

        default:
            cout << "Opcion invalida." << endl;
            break;
        }

        rlutil::anykey();
        system("cls");

    } while (opcion != 0);
}
