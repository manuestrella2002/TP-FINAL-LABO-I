#include "cHospital.h"

cHospital::cHospital(string nom_, string direc_, float cuenta)
{
    Nombre = nom_;
    Direccion = direc_;
    CuentaCorriente = cuenta;
    CostosEquiposMant = 0;
    Cant_Equip_F_Serv = 0;
    ListaEquipos = new cListaDer();
    ListaLugares = new cListaT<cLugares>();
    ListaReparaciones = new cListaT<cReparacion>();

}

cHospital::~cHospital()
{
    delete ListaEquipos;
    delete ListaLugares;
    delete ListaReparaciones;
}

void cHospital::ContarFueraServicio()
{
    Cant_Equip_F_Serv=ListaEquipos->ContarEquipF_Serv();
}

void cHospital::HacerMantenimiento()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    timePtr->tm_year += 1900;
    timePtr->tm_mon += 1;
   
     for (int i = 0; i < ListaEquipos->getCA(); i++)
     {
            for (int a = 0; a < (*ListaEquipos)[i]->Calendario->getCA(); a++)
            {
                if (timePtr->tm_mday == (*ListaEquipos)[i]->Calendario->getItem(a)->getdia() && timePtr->tm_mon == (*ListaEquipos)[i]->Calendario->getItem(a)->getmes())
                {
                    (*ListaEquipos)[i]->MantenimientoPreventivo(ListaReparaciones);
                }
            }
     }
   
}

void cHospital::ListarEquiposFueraLugar()
{
    cout << "ALERTA EQUIPO FUERA DE LUGAR" << endl;

    for (int i = 0; i < ListaEquipos->getCA(); i++)
    {
        if ((*ListaEquipos)[i]->VerificarLugares()==false)
        {
            cout << "\nCodigo:" + (*ListaEquipos)[i]->getclave() + "\nLugar Actual:"
                + (*ListaEquipos)[i]->getLugarAC()->getclave()
                + "\nLugar Guardar:" + (*ListaEquipos)[i]->getLugarGU()->getclave() << endl;
        }
    }

}

void cHospital::MoverEquipo(cEquipoMedico* Equipo, cLugares* aux)
{
    ListaEquipos->BuscarItem(Equipo->getclave())->setLugarActual(aux);
}

void cHospital::FinalizarDia()
{
    for (int i = 0; i < ListaReparaciones->getCA(); i++)
    {
        CostosEquiposMant += (*ListaReparaciones)[i]->GetPrecio();
    }
    if (Cant_Equip_F_Serv > 5 || CostosEquiposMant > 2000 )
    {
        for (int i = 0; i < ListaEquipos->getCA(); i++)
        {
            if ((*ListaEquipos)[i]->ChequearEstado() == cEstado::FUERA_SERVICIO)
            {
                (*ListaEquipos)[i]->MantenimientoCorrectivo();
            }
        }
    }
    ListarEquiposFueraLugar();
}

