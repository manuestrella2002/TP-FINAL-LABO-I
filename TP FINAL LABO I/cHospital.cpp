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

void cHospital::HacerMantenimiento()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
   /*
        for (int i = 0; i < ListaEquipos->getCA(); i++)
        {
            for (int a = 0; a < (ListaEquipos[i])->Calendario->getCA(); a++)
            {

            }
            if (timePtr->tm_mday==(ListaEquipos[i])->Calendario[i]->getdia())
            {

            }
            //PREGUNAT COMO SE USA OPERADOR CORCHETES
            (ListaEquipos->getItem(i))->MantenimientoPreventivo();
        }
   */
}

