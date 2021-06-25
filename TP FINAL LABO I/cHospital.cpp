#include "cHospital.h"
#include"cElectrocardiografo.h"
#include"cMesaAnestesia.h"
#include"cRespirador.h"

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

void cHospital::Inicializar()
{
    cFecha* Fecha1 = new cFecha(25, 6, 2021);
    cFecha* Fecha2 = new cFecha(10, 9, 2021);
    cFecha* Fecha3 = new cFecha(10, 12, 2021);


    cLugares* Consultorio = new cLugares("Consultorio", "A", 2);
    cLugares* Anestesia = new cLugares("Anestesia", "B", 3);
    cLugares* Hemodinamia = new cLugares("Hemodinamia", "A", 1);
    cLugares* Quirofano = new cLugares("Quirofano", "C", 1);

    cReparacion* Reparacion1 = new cReparacion("101", 2000, cProblema::ELECTRICO);
    cReparacion* Reparacion2 = new cReparacion("102", 5000, cProblema::MECANICO);
    cReparacion* Reparacion3 = new cReparacion("103", 6000, cProblema::EN_ESPERA);
    cReparacion* Reparacion4 = new cReparacion("104", 7000, cProblema::ESPECIALIZADO);

    cElectrocardiografo* Electro1 = new cElectrocardiografo("DJ DONG JIANG", "cm300", "318x264x152mm", 4.5, Hemodinamia);
    cMesaAnestesia* Mesa1 = new cMesaAnestesia("Beta", "pr450", "700x480x930", 80, Anestesia);
    cRespirador* Respirador1 = new cRespirador("Alpha", "bx200", "400x300x450", 50, Quirofano);

    (*Electro1->Calendario) + Fecha1;
    (*Electro1->Calendario) + Fecha2;
    (*Electro1->Calendario) + Fecha3;

    (*Mesa1->Calendario) + Fecha1;
    (*Mesa1->Calendario) + Fecha2;
    (*Mesa1->Calendario) + Fecha3;

    (*Respirador1->Calendario) + Fecha1;
    (*Respirador1->Calendario) + Fecha2;
    (*Respirador1->Calendario) + Fecha3;


    //agregamos a la lista con la sobrecarga + los lugares
    (*this->ListaLugares) + Consultorio;
    (*this->ListaLugares) + Anestesia;
    (*this->ListaLugares) + Hemodinamia;
    (*this->ListaLugares) + Quirofano;

    (*this->ListaEquipos) + Electro1;
    (*this->ListaEquipos) + Mesa1;
    (*this->ListaEquipos) + Respirador1;
    //MUESTRA DE QUE LOS CIN SOBRECARGADOS FUNCIONAN
    cin >> *(Electro1);
    cin >> *(Mesa1);
    cin >> *(Respirador1);

}

void cHospital::Funcionamiento()
{

   MoverEquipo(this->ListaEquipos->getItem(0), this->ListaLugares->getItem(1));
   MoverEquipo(this->ListaEquipos->getItem(1), this->ListaLugares->getItem(3));
   cout << "\nRASTREO DE EQUIPOS\n" << endl;
    this->ListaEquipos->RastrearEquipo();

    this->HacerMantenimiento();

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

