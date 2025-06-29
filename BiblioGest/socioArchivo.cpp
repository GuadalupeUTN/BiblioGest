#include <cstdio>
#include "SocioArchivo.h"
#include <cstring>


SocioArchivo::SocioArchivo(){
  nombreArchivo = "socios.dat";
}

Socio SocioArchivo::leer(int pos)
{
    Socio reg;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) return reg;

    fseek(p, sizeof(Socio) * pos, SEEK_SET);
    fread(&reg, sizeof(Socio), 1, p);
    fclose(p);
    return reg;
}

bool SocioArchivo::guardar(Socio& reg) {
    int total = contarRegistros();
    int ultimoNumero = 0;

    // Buscar el último número de socio activo
    for (int i = total - 1; i >= 0; i--) {
        Socio s = leer(i);
        if (s.getEstado()) {
            ultimoNumero = s.getNumeroSocio();
            break;
        }
    }

    // Asignar número de socio automáticamente
    reg.setNumeroSocio(ultimoNumero + 1);

    // Guardar el nuevo socio en el archivo
    FILE* p = fopen(nombreArchivo, "ab");
    if (p == nullptr) return false;

    bool exito = fwrite(&reg, sizeof(Socio), 1, p);
    fclose(p);
    return exito;
}


bool SocioArchivo::guardar(Socio reg, int pos) {
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == NULL) return false;

    fseek(p, sizeof(Socio) * pos, SEEK_SET);
    bool exito = fwrite(&reg, sizeof(Socio), 1, p);
    fclose(p);
    return exito;
}

int SocioArchivo::contarRegistros() {
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) return 0;

    fseek(p, 0, SEEK_END);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Socio);
}

int SocioArchivo::buscar(int nroSocio){
   Socio reg;
   int posicion = 0;
   FILE* p = fopen(nombreArchivo, "rb");

   if (p == nullptr){
      return -2;
   }

   while(fread(&reg, sizeof(Socio), 1, p) == 1){
      if (reg.getNumeroSocio() == nroSocio){
         fclose(p);
         return posicion;
      }
      posicion++;
   }

   fclose(p);
   return -1;
}

int SocioArchivo::buscarDni(char dni[12]){
   Socio reg;
   int posicion = 0;
   FILE* p = fopen(nombreArchivo, "rb");

   if (p == nullptr){
      return -2;
   }

   while(fread(&reg, sizeof(Socio), 1, p) == 1){
      if (reg.getDni() == dni){
         fclose(p);
         return posicion;
      }
      posicion++;
   }

   fclose(p);
   return -1;
}
bool SocioArchivo::eliminarFisicamente(int nroSocio) {
    FILE* original = fopen(nombreArchivo, "rb");
    if (original == NULL) return false;

    FILE* temporal = fopen(nombreArchivo, "wb");
    if (temporal == NULL) {
        fclose(original);
        return false;
    }

    Socio reg;
    bool eliminado = false;

    while (fread(&reg, sizeof(Socio), 1, original) == 1) {
        if (reg.getNumeroSocio() != nroSocio) {
            fwrite(&reg, sizeof(Socio), 1, temporal);
        } else {
            eliminado = true;
        }
    }

    fclose(original);
    fclose(temporal);

    return eliminado;
}

bool SocioArchivo::eliminarFisicamente(char dni[12]) {
    FILE* original = fopen(nombreArchivo, "rb");
    if (original == NULL) return false;

    FILE* temporal = fopen(nombreArchivo, "wb");
    if (temporal == NULL) {
        fclose(original);
        return false;
    }

    Socio reg;
    bool eliminado = false;

    while (fread(&reg, sizeof(Socio), 1, original) == 1) {
        if (reg.getDni() != dni) {
            fwrite(&reg, sizeof(Socio), 1, temporal);
        } else {
            eliminado = true;
        }
    }

    fclose(original);
    fclose(temporal);

    return eliminado;
}

bool SocioArchivo::eliminarLogicamente(int nroSocio) {
    int total = contarRegistros();

    for (int i = 0; i < total; i++) {
        Socio s = leer(i);
        if (s.getNumeroSocio() == nroSocio && s.getEstado() == true) {
            s.setEstado(false);
            return guardar(s, i);
        }
    }
    return false;
}


bool SocioArchivo::eliminarLogicamente(char dni[12]) {
    int total = contarRegistros();

    for (int i = 0; i < total; i++) {
        Socio s = leer(i);
        if (s.getDni() == dni && s.getEstado() == true) {
            s.setEstado(false);
            return guardar(s, i);
        }
    }
    return false;
}

bool SocioArchivo::existeDni(const char* dni)
{
    int total = contarRegistros();

    for (int i = 0; i < total; i++) {
        Socio s = leer(i);

        if (strcmp(s.getDni(), dni) == 0) {
            return true;  // Existe y cumple el criterio
        }
    }

    return false;  // No se encontró
}

