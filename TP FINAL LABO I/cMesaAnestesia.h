#pragma once
#include "cEquipoMedico.h"

class cHospital;
class cMesaAnestesia : public cEquipoMedico
{
	bool Alarma_Alta_FrecCard, Alarma_Baja_FrecCard; //se usa para verificar el funcionamiento
	int Nivel_Sueño;
	float Volumen_Flujo;

public:
	cMesaAnestesia(string Nom_, const string COD, string Dim, float Peso,cLugares* Lugar_Guardar_);
	~cMesaAnestesia();

	void MantenimientoPreventivo(cListaT <cReparacion>* ListaReparaciones);
	//EXISTEN TRES TIPOS DE PROBLEMA DEPENDE DE CUAL SEA
	void MantenimientoCorrectivo(int nivel_);
	void MantenimientoCorrectivo();
	void MantenimientoCorrectivo(float Volumen_);

	void SetSueño(int sueño_);
	
	friend istream& operator>>(istream& in, cMesaAnestesia& Mesa);
	friend ostream& operator<<(ostream& out, cMesaAnestesia& Mesa);
};
