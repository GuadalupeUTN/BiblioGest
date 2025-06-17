#include <iostream>
#include "rlutil.h"

using namespace std;
#include "funcionesPantallasInteractivas.h"
#include "menu.h"

void mostrarMenuPrincipal()
{
    int seleccion;
    do
    {
        rlutil::cls();
        rlutil::hidecursor();
        rlutil::locate(45,7);
        cout<<"B    I    B    L    I    O    G    E    S    T"<<endl;
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(40,9);
        cout<< "S i s t e m a    G e s t i o n    B i b l i o t e c a"<<endl;
        for (int i=0; i<=100; i++)
        {
            rlutil::setColor(rlutil::MAGENTA);
            rlutil::locate(20+i,5);
            cout<< char(205);
            rlutil::locate(20+i,10);
            cout<< char(205);
        };

        rlutil::setColor(rlutil::CYAN);
        cout<<endl;
        rlutil::locate(55,12);
        cout<<"1-B I B L I O T E C A"<<endl;
        rlutil::locate(55,13);
        cout<<"2-S O C I O S"<<endl;
        rlutil::locate(55,14);
        cout<<"3-P A G O S"<<endl;
        rlutil::locate(55,15);
        cout<<"4-P R E S T A M O S"<<endl;
        rlutil::locate(55,16);
        cout<<"5-C R E D I T O S"<<endl;
        rlutil::locate(55,17);
        cout<<"0-S A L I R"<<endl;
        cin >> seleccion;

        switch(seleccion)
        {
        case 1:
        {
            rlutil::cls();
            mostrarMenuLibros();
        }
        break;
        case 2:
        {
            rlutil::cls();
            mostrarMenuPrincipal();
        }
        break;
        case 3:
        {
            rlutil::cls();
            cout<< "ESTAMOS TRABAJANDO EN ESTA OPCION, REGRESE AL MENU PRINCIPAL CON CUALQUIER TECLA"<<endl;
            int volver=rlutil::getkey();
            if (volver==1)
            {
                mostrarMenuPrincipal();
            }
        }
        break;
        case 4:
        {
            rlutil::cls();
            cout<< "ESTAMOS TRABAJANDO EN ESTA OPCION, REGRESE AL MENU PRINCIPAL CON CUALQUIER TECLA"<<endl;
            int volver=rlutil::getkey();
            if (volver==1)
            {
                mostrarMenuPrincipal();
            }
        }
        break;
        case 5:
        {
            rlutil::cls();
            cout<<"ESTE PROYECTO FUE REALIZADO CON ESFUERZO, SUDOR Y (EN ESPECIAL) LAGRIMAS POR: "<<endl;
            cout<<"FLORENCIA Y GUADALUPE"<<endl;
            cout<<"PARA REGRESAR AL MENU PRINCIPAL PRESIONE CUALQUIER TECLA"<<endl;
            int volver=rlutil::getkey();
            if (volver==1)
            {
                mostrarMenuPrincipal();
            }
        }
        break;
        case 0:
            rlutil::cls();
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(50,20);
            cout<<"SALIENDO DEL PROGRAMA, PRESIONE CUALQUIER TECLA PARA CONTINUAR"<<endl;
            rlutil::anykey();
            exit(0);
            break;
        }

    }
    while(seleccion>0);

}
