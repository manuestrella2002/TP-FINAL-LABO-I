#pragma once
#include "cCalendario.h"
#include "cLugares.h"
#include <iostream>


using namespace std;

enum Estado { EN_USO, EN_ESPERA, FUERA_SERVICIO, MANTENIMIENTO };
class cEquipoMedico
{
protected:
	//DOS OPCIONES:
	//1)CREAR LISTA DE FECHAS CON LISTA TEMPLATE PASANDO cCALENDARIO* 
	//CON 3 VARIABLES DENTRO DE DIA, MES, AÑO
	//2)AGREGARLE MAS COSAS A LA CLASE CALENDARIO PARA AGREGARLE COSAS DENTRO DE LA VARIABLE
	
	cCalendario* calendario;
	
	static int Cant_Total_Equipos;
	const string codigo;
	string Nombre, Descripcion;
	string Dimension;
	float Peso;
	Estado _Estado; tm* Fecha_ult_Mant;
	cLugares *Lugar_Actual, *Lugar_Guardar;

public:
	cEquipoMedico(string Nom_, const string COD, string Dim, float Peso_, cLugares* LugarGuardar_);
	~cEquipoMedico();

	Estado ChequearEstado();
	virtual void Imprimir(); //en general pero va virtual o no?
	void ImprimirAlerta();
	virtual void MantenimientoCorrectivo()=0;
	virtual void MantenimientoPreventivo()=0;
	virtual string To_String() = 0;

	//VERIFICA SI LUGAR ACTUAL==LUAGR GUARDAR
	bool VerificarLugares();


	string GetClave();
};

istream& operator>>(istream& in, cEquipoMedico& Equipo)
{
	
}

ostream& operator<<(ostream& out, cEquipoMedico& Equipo)
{
	Equipo.Imprimir();
}