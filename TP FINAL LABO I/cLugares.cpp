#include "cLugares.h"

cLugares::cLugares(string nom_, string pabellon_, int piso_)
{
    Nombre = nom_;
    Pabellon = pabellon_;
    Piso = piso_;
    Localizado = false;
}

cLugares::~cLugares()
{
}

bool cLugares::VerificarLocalizado()
{
    if (Localizado==true)
    {
        return true;
    }
  return  false;
}

string cLugares::getclave()
{
    return Nombre;
}



string cLugares::To_String()
{
    return string();
}

void cLugares::Imprimir()
{
}
