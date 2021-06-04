#pragma once
#include "cEquipoMedico.h"
class cMesaAnestesia : public cEquipoMedico
{
	bool Alarma_Alta_FrecCard, Alarma_Baja_FrecCard;
	float Nivel_Sueño, Volumen_Flujo;

public:
	cMesaAnestesia(string Nom_, const string COD, string Dim, float Peso);
	~cMesaAnestesia();

	void Imrpimir();
	string To_String();

	void MantenimientoPreventivo();
	void MatenimientoCorrectivo();
	string GetClave();
};

