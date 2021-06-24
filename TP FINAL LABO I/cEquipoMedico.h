#pragma once
#include "cCalendario.h"
#include"cLugares.h"
#include"cReparacion.h"
#include <iostream>



class cEquipoMedico
{
protected:
	//DOS OPCIONES:
	//1)CREAR LISTA DE FECHAS CON LISTA TEMPLATE PASANDO cCALENDARIO* 
	//CON 3 VARIABLES DENTRO DE DIA, MES, AÑO
	//2)AGREGARLE MAS COSAS A LA CLASE CALENDARIO PARA AGREGARLE COSAS DENTRO DE LA VARIABLE
	
	static int Cant_Total_Equipos;
	const string codigo;
	string Nombre, Descripcion;
	string Dimension;
	float Peso;
	cEstado _Estado;
	tm* Fecha_ult_Mant;
	cLugares *Lugar_Actual, *Lugar_Guardar;

public:
	cCalendario* Calendario;
	cEquipoMedico(string Nom_, const string COD, string Dim, float Peso_, cLugares* LugarGuardar_);
	~cEquipoMedico();

	cEstado ChequearEstado();
	virtual void Imprimir()=0; //en general pero va virtual o no?
	void ImprimirAlerta();
	
	virtual void MantenimientoCorrectivo()=0;
	virtual void MantenimientoPreventivo(cListaT<cReparacion>* ListaReparaciones)=0;
	
	virtual string To_String() = 0;

	//VERIFICA SI LUGAR ACTUAL==LUAGR GUARDAR
	bool VerificarLugares();

	cLugares* getLugarAC();
	cLugares* getLugarGU();
	string getclave();

	friend istream& operator>>(istream& in, cEquipoMedico& Equipo);
	friend ostream& operator<<(ostream& out, const cEquipoMedico& Equipo); 
	//no se puede hacer virtual asi que no se como se podria hacer 
};
