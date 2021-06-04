#pragma once
#include "cEquipoMedico.h"
class cRespirador : public cEquipoMedico
{
	bool Alarma_Alta_Presion, Alarma_Baja_Presion;
	float Flujo, FlujoConfigurado, FlujoSalida;

public:
	cRespirador(string Nom_, const string COD, string descripcion_, string Dim, float Peso);
	~cRespirador();

	void Imrpimir();
	string To_String();

	void MantenimientoPreventivo();
	void MatenimientoCorrectivo();
};

