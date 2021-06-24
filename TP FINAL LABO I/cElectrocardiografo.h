#pragma once
#include "cEquipoMedico.h"
class cHospital;
class cElectrocardiografo : public cEquipoMedico
{
	bool Der_aVF, Der_aVL, Der_aVR;

public:
	cElectrocardiografo(string Nom_, const string COD, string Dim, float Peso, cLugares* LugarGuardar_);
	~cElectrocardiografo();

	void Imprimir();
	string To_String();

	void MantenimientoPreventivo(cListaT <cReparacion>* ListaReparaciones);
	void MantenimientoCorrectivo();
	
};
/*
istream& operator>>(istream& in, cElectrocardiografo& Electro)
{
	return in;
}

ostream& operator<<(ostream& out, cElectrocardiografo& Electro)
{
	Electro.Imprimir();
	out << Electro.To_String();
	return out;
}
*/