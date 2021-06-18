#include "cEquipoMedico.h"

int cEquipoMedico::Cant_Total_Equipos = 0;

bool cEquipoMedico::VerificarLugares()
{
    return false;
}

string cEquipoMedico::getclave()
{
    return codigo;
}

cEquipoMedico::cEquipoMedico(string Nom_, const string COD, string Dim, float Peso_, cLugares* LugarGuardar_):codigo(COD)
{
    Nombre = Nom_;
    Dimension = Dim;
    Peso = Peso_;
    //USAR RANDOM ALGO ASI PARA INICIALIZAR LA FECHA EN ALGO
    Fecha_ult_Mant = NULL;

    Cant_Total_Equipos++;
    Lugar_Guardar = LugarGuardar_;

    //COMO COMIENZA EL DIA SE LOS LUGARES DEBEN SER LOS MISMOS
    Lugar_Actual = LugarGuardar_;
   
}

cEquipoMedico::~cEquipoMedico()
{
}

cEstado cEquipoMedico::ChequearEstado()
{
    return _Estado;
}

void cEquipoMedico::ImprimirAlerta()
{
    cout << "\nEl equipo"<< Nombre <<"no se encuentra en el lugar a guardar." << endl;
}
