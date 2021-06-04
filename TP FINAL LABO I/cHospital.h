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

	
public:
	cListaT <cEquipoMedico>* ListaEquipos;
	cListaT <cLugares>* ListaLugares;
	cListaT <cReparacion>* ListaReparaciones;

	cHospital(string nom_, string direc_, float cuenta);
	~cHospital();

	string To_String();
	void Imprimir();


};

