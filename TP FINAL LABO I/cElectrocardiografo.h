#pragma once
#include "cEquipoMedico.h"

class cElectrocardiografo : public cEquipoMedico
{
	bool Der_aVF, Der_aVL, Der_aVR;

public:
	cElectrocardiografo(string Nom_, const string COD, string descripcion_, string Dim, float Peso);
	~cElectrocardiografo();

	void Imrpimir();
	string To_String();

	void MantenimientoPreventivo();
	void MatenimientoCorrectivo();
};

