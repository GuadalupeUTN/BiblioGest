#pragma once

class Generos
{
private:
    int _IDGenero;
    char _genero[20];
    int _cantLibros;
    bool _estado;
public:
    Generos();
    Generos( const char* genero, int cantLibros );

    int getIDGenero();
    const char* getGenero();
    int getCantLibros();
    bool getEstado();

    void setIDGenero(int IDGenero);
    void setGenero(const char* genero);
    void setCantLibros(int cantLibros);
    void setEstado(bool estado);


    void cargarGenero();
    void mostrarGeneros();
};
