#pragma once

class Autores
{
private:
    static int idAux;
    int _IDAutor;
    char _autor[80];
    int _cantObras;
public:
    Autores();
    Autores(const char* autor, int cantObras);

    int getIDAutor();
    const char* getAutor();
    int getCantObras();

    void setAutor(const char* autor);
    void setCantObras(int cantObras);

    static void inicializarID();

    void cargarAutor();
    void mostrarAutor();
};
