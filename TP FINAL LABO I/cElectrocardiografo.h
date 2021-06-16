#pragma once
#include "cEquipoMedico.h"
class cElectrocardiografo : public cEquipoMedico
{
	bool Der_aVF, Der_aVL, Der_aVR;

public:
	cElectrocardiografo(string Nom_, const string COD, string Dim, float Peso);
	~cElectrocardiografo();

	void Imrpimir();
	string To_String();

	void MantenimientoPreventivo();
	void MatenimientoCorrectivo();
	string GetClave();
};

istream& operator>>(istream& in, cElectrocardiografo& Electro)
{

}

ostream& operator<<(ostream& out, cElectrocardiografo& Electro)
{
	Electro.Imprimir();
}
