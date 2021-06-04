#pragma once
#include<iostream>
#include<string>
#include"cListaT.h"
#include"cEquipoMedico.h"
#include"cLugares.h"
#include"cReparacion.h"
using namespace std;

class cHospital
{
	float CostosEquiposMant, CuentaCorriente;
	string Direccion, Nombre;

	cListaT <cEquipoMedico>* ListaEquipos;
	cListaT <cLugares>* ListaLugares;
	cListaT <cReparacion>* ListaReparaciones;
public:
	cHospital();
	~cHospital();

	string To_String();
	void Imprimir();


};

