#pragma once
#include <string>


class Fecha{
    private:
    int _dia, _mes, _anio;

    public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    int getDia();
    int getMes();
    int getAnio();
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    void mostrar();
    void cargar();
    std::string toString();

        //Clase amiga para acceder a valores internos de la clase Fecha
    friend std::ostream& operator<<(std::ostream& os, const Fecha& f);
};

