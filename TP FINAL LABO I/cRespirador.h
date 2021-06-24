#pragma once
#include "cEquipoMedico.h"
class cHospital;
class cRespirador :  public cEquipoMedico
{
	bool Alarma_Alta_Presion, Alarma_Baja_Presion;
	float Flujo, FlujoConfigurado, FlujoSalida;

public:
	cRespirador(string Nom_, const string COD, string Dim, float Peso, cLugares* Lugar_Guardar_);
	~cRespirador();

	void Imprimir();
	string To_String();

	void MantenimientoPreventivo(cListaT <cReparacion>* ListaReparaciones);
	void MantenimientoCorrectivo();
	void MantenimientoCorrectivo(float flujo_);


	void ConfigurarFlujo(float aux_);

	friend istream& operator>>(istream& in, cRespirador& Respirador);
	friend ostream& operator<<(ostream& out, cRespirador& Respirador);
};
