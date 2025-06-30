#include <iostream>
using namespace std;

#include "Pagos.h"
#include "Socio.h"

void Pagos::setNumeroSocio(int numeroSocio) {
    this->numeroSocio = numeroSocio;
}

void Pagos::setFechaPago(Fecha fechaPago) {
    fechaPago = fechaPago;
}

void Pagos::setImporte(float importe) {
    this->importe = importe;
}

void Pagos::setMesPago(int mesPago) {
    this->mesPago = mesPago;
}

void Pagos::setAnioPago(int anioPago) {
    this->anioPago = anioPago;
}

void Pagos::setEstado(bool estado) {
    this->estado = estado;
}

int Pagos::getNumeroSocio() {
    return numeroSocio;
}

Fecha Pagos::getFechaPago() {
    return fechaPago;
}

float Pagos::getImporte() {
    return importe;
}

int Pagos::getMesPago() {
    return mesPago;
}

int Pagos::getAnioPago() {
    return anioPago;
}

bool Pagos::getEstado() {
    return estado;
}

void Pagos::cargarPago(Socio socio) {
    system("cls");
    cout << "REGISTRAR NUEVO PAGO" << endl;
    cout << "---------------------" << endl;

    numeroSocio = socio.getNumeroSocio();

    cout << "FECHA DE PAGO:" << endl;
    fechaPago.cargar();

    // automáticamente extraemos mes y año
    mesPago = fechaPago.getMes();
    anioPago = fechaPago.getAnio();

    cout << "IMPORTE PAGADO: ";
    cin >> importe;

    estado = true;
}

void Pagos::mostrar() {
    cout << "--------------------------" << endl;
    cout << "NUMERO DE SOCIO: " << numeroSocio << endl;
    cout << "FECHA DE PAGO: ";
    fechaPago.mostrar();
    cout << endl;
    cout << "IMPORTE: $" << importe << endl;
    cout << "MES CORRESPONDIENTE: " << mesPago << endl;
    cout << "ANIO CORRESPONDIENTE: " << anioPago << endl;
}
