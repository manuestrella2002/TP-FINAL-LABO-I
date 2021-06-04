#pragma once
#include "cCalendario.h"
#include <iostream>

using namespace std;

enum Estado{ EN_USO, EN_ESPERA, FUERA_SERVICIO, MANTENIMIENTO };
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
	cServicio* Lugar_Actual, * Lugar_Guardar, * Servicio;

public:
	cEquipoMedico(string Nom_, const string COD, string descripcion_, string Dim, float Peso);
	~cEquipoMedico();
	
	int ChequearEstado();
	virtual void Imprimir(); //en general pero va virtual o no?
	virtual void ImprimirAlerta();
	virtual void MantenimientoCorrectivo();
	virtual void MantenimientoPreventivo();
	virtual string To_String() = 0;
};

