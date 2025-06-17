#ifndef PAGOS_H_INCLUDED
#define PAGOS_H_INCLUDED

public class Pagos
{
    #ifndef PAGO_H
#define PAGO_H

#include "Fecha.h"

class Pago {
private:
    int numeroSocio;
    Fecha fechaPago;
    float importe;
    int mesPago;
    int anioPago;
    bool estado;

public:

    void setNumeroSocio(int numeroSocio);
    void setFechaPago(Fecha fechaPago);
    void setImporte(float importe);
    void setMesPago(int mesPago);
    void setAnioPago(int anioPago);
    void setEstado(bool estado);

    int getNumeroSocio();
    Fecha getFechaPago();
    float getImporte();
    int getMesPago();
    int getAnioPago();
    bool getEstado();
};

#endif // PAGO_H



#endif // PAGOS_H_INCLUDED
