#include "cHospital.h"

cHospital::cHospital(string nom_, string direc_, float cuenta)
{
    Nombre = nom_;
    Direccion = direc_;
    CuentaCorriente = cuenta;
    CostosEquiposMant = 0;
    Cant_Equip_F_Serv = 0;

    //DEBEMOS DESTRUIR EN EL DESTRUCTOR LAS LISTAS??
    ListaEquipos = new cListaDer();
    ListaLugares = new cListaT<cLugares>();
    ListaReparaciones = new cListaT<cReparacion>();

}

cHospital::~cHospital()
{
}

void cHospital::ContarFueraServicio()
{
    Cant_Equip_F_Serv=ListaEquipos->ContarEquipF_Serv();
}

string cHospital::To_String()
{
    return string();
}

void cHospital::Imprimir()
{
}
