#include <iostream>

#include <cstring>
using namespace std;

bool validarDNI(const char* dni)
{
    int len = strlen(dni);

    // Largo entre 7 y 8 dígitos
    if (len < 7 || len > 8) return false;

    // Que todos los caracteres sean dígitos
    for (int i = 0; i < len; i++) {
        if (!isdigit(dni[i])) return false;
    }

    return true;
}

void errorMessage(int error)
{
    switch(error)
    {
    case 1:
        cout << "ERROR AL INGRESAR EL DNI" << endl;
        break;
    case 2:
        cout << "ERROR AL INGRESAR EL NUMERO DE USUARIO" << endl;
        break;
    default:
        cout << "ERROR INTENTE OTRA VEZ" << endl;
    }
}

