#pragma once
#include "cEquipoMedico.h"
class cMesaAnestesia : public cEquipoMedico
{
	bool Alarma_Alta_FrecCard, Alarma_Baja_FrecCard;
	int Nivel_Sueño;
	float Volumen_Flujo;

public:
	cMesaAnestesia(string Nom_, const string COD, string Dim, float Peso,cLugares* Lugar_Guardar_);
	~cMesaAnestesia();

	void Imprimir();
	string To_String();

	void MantenimientoPreventivo();
	//EXISTEN TRES TIPOS DE PROBLEMA DEPENDE DE CUAL SEA
	void MantenimientoCorrectivo(int nivel_);
	void MantenimientoCorrectivo();
	void MantenimientoCorrectivo(float Volumen_);
	
};
/*
istream& operator>>(istream& in, cMesaAnestesia& Mesa)
{
	return in;
}

ostream& operator<<(ostream& out, cMesaAnestesia& Mesa)
{
	Mesa.Imprimir();
	out << Mesa.To_String();
	return out;
}
*/