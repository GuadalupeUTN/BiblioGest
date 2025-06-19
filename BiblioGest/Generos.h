#pragma once

class Generos
{
private:
    static int idAux;
    int _IDGenero;
    char _genero[20];
    int _cantLibros;
public:
    Generos();
    Generos( const char* genero, int cantLibros );

    int getIDGenero();
    const char* getGenero();
    int getCantLibros();

    void setGenero(const char* genero);
    void setCantLibros(int cantLibros);

    void cargarGenero();
    void mostrarGeneros();
};
