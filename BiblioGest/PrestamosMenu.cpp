#include <iostream>
#include "Prestamos.h"
#include "ArchivoPrestamos.h"

using namespace std;

void mostrarMenuPrestamos() {
    PrestamosArchivo archivo;
    int opcion;

    do {
        cout << "=== MENU DE PRESTAMOS ===" << endl;
        cout << "1. Registrar nuevo prestamo" << endl;
        cout << "2. Listar todos los prestamos" << endl;
        cout << "3. Buscar prestamo por ID" << endl;
        cout << "4. Eliminar prestamo logicamente" << endl;
        cout << "5. Editar prestamo" << endl;
        cout << "0. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1: {
            Prestamos p;
            p.cargarPrestamo();
            if (archivo.guardar(p)) {
                cout << "Prestamo registrado correctamente.";
            } else {
                cout << "Error al guardar el prestamo.";
            }
            cout<<endl;
            break;
        }
        case 2: {
            archivo.mostrarListadoPrestamos();
            break;
        }
        case 3: {
            int id;
            cout << "Ingrese ID del pr3stamo a buscar: ";
            cin >> id;
            int pos = archivo.buscarPrestamos(id);
            if (pos >= 0) {
                Prestamos p = archivo.leer(pos);
                p.mostrarPrestamo();
            } else {
                cout << "Pr3stamo no encontrado.";
            }
            break;
        }
        case 4: {
            int id;
            cout << "Ingrese ID del prestamo a eliminar: ";
            cin >> id;
            int pos = archivo.buscarPrestamos(id);
            if (pos >= 0) {
                Prestamos p = archivo.leer(pos);
                p.setEstado(false);
                archivo.guardarEnPosicion(p, pos);
                cout << "Prestamo eliminado logicamente.";
            } else {
                cout << "Prestamo no encontrado.";
            }
            break;
        }
        case 5:
            {

                int id;
                cout << "Ingrese ID del prestamo a editar: ";
                cin >> id;
                int pos = archivo.buscarPrestamos(id);
                if (pos >= 0)
                    {
                    Prestamos p = archivo.leer(pos);
                    cout << "EDITANDO PRESTAMO:";
                    p.mostrarPrestamo();
                    cout << "Ingrese nueva fecha de devolucion:";
                    Fecha f;
                    f.cargar();
                    p.setFechaDevolucion(f);
                    archivo.guardarEnPosicion(p, pos);
                    cout << "Fecha de devolucion actualizada.";
                } else {
                    cout << "Prestamo no encontrado.";
                }
                break;
        }
        case 0:
            cout << "Volviendo al menu principal...";
            break;
        default:
            cout << "Opcion invalida.";
        }

        system("pause");
        system("cls");

    } while (opcion != 0);
}
