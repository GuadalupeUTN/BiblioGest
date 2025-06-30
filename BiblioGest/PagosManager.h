#ifndef PAGOSMANAGER_H_INCLUDED
#define PAGOSMANAGER_H_INCLUDED


class PagosManager
{
private:
public:
    bool deuda(int nroSocio);
    bool deudaPorFecha(int nroSocio, int _mes, int anio);
    int cantidadDeMesesAdeudados(int nroSocio);
    bool editar(int nroSocio, int mes, int anio);
};
#endif // PAGOSMANAGER_H_INCLUDED
