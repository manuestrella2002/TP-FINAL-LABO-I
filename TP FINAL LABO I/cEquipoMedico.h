#pragma once
#include "cCalendario.h"
#include"cLugares.h"
#include"cReparacion.h"
#include <iostream>
#include "cListaT.h"
#include <ctime>


class cEquipoMedico
{
protected:
	
	static int Cant_Total_Equipos;
	const string codigo;
	string Nombre, Descripcion;
	string Dimension;
	float Peso;
	cEstado _Estado;
	tm* Fecha_ult_Mant;
	cLugares *Lugar_Actual, *Lugar_Guardar;

public:
	cCalendario* Calendario; // tiene la lista de fechas 
	cEquipoMedico(string Nom_, const string COD, string Dim, float Peso_, cLugares* LugarGuardar_);
	~cEquipoMedico();

	cEstado ChequearEstado();

	void ImprimirAlerta(); //imprime una alerta si el equipo no se encuentra en el lugar de guardado
	
	virtual void MantenimientoCorrectivo()=0;
	virtual void MantenimientoPreventivo(cListaT<cReparacion>* ListaReparaciones)=0;


	//VERIFICA SI LUGAR ACTUAL==LUGAR GUARDAR
	bool VerificarLugares();

	cLugares* getLugarAC();
	cLugares* getLugarGU();
	string getclave();

	friend istream& operator>>(istream& in, cEquipoMedico& Equipo);
	friend ostream& operator<<(ostream& out, const cEquipoMedico& Equipo); 
	//no se puede hacer virtual asi que no se como se podria hacer 
};
