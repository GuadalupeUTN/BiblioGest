#pragma once

class Autores
{
private:
    int _IDAutor;
    char _autor[80];
    int _cantObras;
    bool _estado;
public:
    Autores();
    Autores(const char* autor, int cantObras);

    int getIDAutor();
    const char* getAutor();
    int getCantObras();
    bool getEstado();

    void setIDAutor(int IDAutor);
    void setAutor(const char* autor);
    void setCantObras(int cantObras);
    void setEstado(bool estado);

    void cargarAutor();
    void mostrarAutor();
};
