#pragma once
#include "cCalendario.h"
#include "cLugares.h"
#include <iostream>

using namespace std;

enum Estado { EN_USO, EN_ESPERA, FUERA_SERVICIO, MANTENIMIENTO };
class cEquipoMedico
{
protected:
	cCalendario calendario;
	unsigned int Cant_Equip_F_Serv, Cant_Total_Equipos;
	const string codigo;
	string Nombre, Descripcion;
	string Dimension;
	float Peso;
	Estado _Estado; tm* Fecha_ult_Mant;
	cLugares* Lugar_Actual, * Lugar_Guardar;

public:
	cEquipoMedico(string Nom_, const string COD, string Dim, float Peso);
	~cEquipoMedico();

	int ChequearEstado();
	virtual void Imprimir(); //en general pero va virtual o no?
	virtual void ImprimirAlerta();
	virtual void MantenimientoCorrectivo();
	virtual void MantenimientoPreventivo();
	virtual string To_String() = 0;

	string GetClave();
};



