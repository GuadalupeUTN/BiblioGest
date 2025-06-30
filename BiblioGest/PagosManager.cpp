#include <iostream>
#include "PagosManager.h"
#include "pagosArchivo.h"
#include "pagos.h"
#include "socio.h"
#include "socioArchivo.h"
#include <ctime>
using namespace std;


bool PagosManager::deuda(int numeroSocio)
{
    PagosArchivo pArchivo;
    int totalPagos = pArchivo.contarRegistros();
    if (totalPagos == 0) return true;

    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int anioActual = now->tm_year + 1900;
    int mesActual = now->tm_mon + 1;


    for (int i = 0; i < totalPagos; i++) {
        Pagos p = pArchivo.leer(i);
        if (p.getNumeroSocio() != numeroSocio) continue;

        int anio = p.getAnioPago();
        int mes = p.getMesPago();

        if(anio == anioActual && mes == mesActual)
        {
            return false;
        }
    }

    return true;
}

bool PagosManager::deudaPorFecha(int numeroSocio, int _mes, int _anio)
{
    PagosArchivo pArchivo;
    int totalPagos = pArchivo.contarRegistros();
    if (totalPagos == 0) return true;


    for (int i = 0; i < totalPagos; i++) {
        Pagos p = pArchivo.leer(i);
        if (p.getNumeroSocio() != numeroSocio) continue;

        int anio = p.getAnioPago();
        int mes = p.getMesPago();
        if(anio == _anio && mes == _mes)
        {
            return false;
        }
    }

    return true;
}



int PagosManager::cantidadDeMesesAdeudados(int numeroSocio)
{
    PagosArchivo pArchivo;
    int totalPagos = pArchivo.contarRegistros();
    if (totalPagos == 0) return 0;

    int primerMes = 12, primerAnio = 9999;
    int ultimoMes, ultimoAnio;

    for (int i = 0; i < totalPagos; i++) {
        Pagos p = pArchivo.leer(i);
        if (!p.getEstado() || p.getNumeroSocio() != numeroSocio) continue;

        int mes = p.getMesPago();
        int anio = p.getAnioPago();

        if (anio < primerAnio || (anio == primerAnio && mes < primerMes)) {
            primerMes = mes;
            primerAnio = anio;
        }
    }

    if (primerAnio == 9999) return 0;

    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int mesActual = now->tm_mon + 1;
    int anioActual = now->tm_year + 1900;

    int mesesTotales = (anioActual - primerAnio) * 12 + (mesActual - primerMes + 1);
    if (mesesTotales <= 0) return 0;

    bool pagosHechos[300] = {false};

    for (int i = 0; i < totalPagos; i++) {
        Pagos p = pArchivo.leer(i);
        if (!p.getEstado() || p.getNumeroSocio() != numeroSocio) continue;

        int mes = p.getMesPago();
        int anio = p.getAnioPago();

        int index = (anio - primerAnio) * 12 + (mes - primerMes);
        if (index >= 0 && index < 300) {
            pagosHechos[index] = true;
        }
    }

    int deuda = 0;
    for (int i = 0; i < mesesTotales; i++) {
        if (!pagosHechos[i]) deuda++;
    }

    return deuda;
}

bool PagosManager::editar(int numeroSocio, int mes, int anio)
{
    PagosArchivo archivo;
    int total = archivo.contarRegistros();
    bool encontrado = false;
    bool editado = false;

    for (int i = 0; i < total; i++)
    {
        Pagos p = archivo.leer(i);

        if (p.getNumeroSocio() == numeroSocio &&
            p.getMesPago() == mes &&
            p.getAnioPago() == anio &&
            p.getEstado())
            {

                cout << "PAGO ENCONTRADO:";
                p.mostrar();
                cout << "Ingrese el nuevo importe: ";
                float nuevoImporte;
                cin >> nuevoImporte;
                p.setImporte(nuevoImporte);

                editado =  archivo.guardar(p, i);
            }

    }
    return editado;
}
