#pragma once
#include "cEquipoMedico.h"
class cRespirador :  public cEquipoMedico
{
	bool Alarma_Alta_Presion, Alarma_Baja_Presion;
	float Flujo, FlujoConfigurado, FlujoSalida;

public:
	cRespirador(string Nom_, const string COD, string Dim, float Peso, cLugares* Lugar_Guardar_);
	~cRespirador();

	void Imprimir();
	string To_String();

	void MantenimientoPreventivo();
	void MantenimientoCorrectivo();
	void MantenimientoCorrectivo(float flujo_);


	void ConfigurarFlujo(float aux_);
};
/*
istream& operator>>(istream& in, cRespirador& Respirador)
{
	float aux;
	cin >> aux;
	Respirador.ConfigurarFlujo(aux);
	return in;
}

ostream& operator<<(ostream& out, cRespirador& Respirador)
{
	Respirador.Imprimir();

	out << Respirador.To_String();
	return out;
}
*/