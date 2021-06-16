#pragma once
#include<iostream>
#include<string>
#include"cEquipoMedico.h"
#include"cLugares.h"
#include"cReparacion.h"
#include"cListaDer.h"
using namespace std;

class cHospital
{
	float CostosEquiposMant, CuentaCorriente;
	string Direccion, Nombre;
	unsigned int Cant_Equip_F_Serv;
	
public:
	cListaDer* ListaEquipos;
	cListaT <cLugares>* ListaLugares;
	cListaT <cReparacion>* ListaReparaciones;

	cHospital(string nom_, string direc_, float cuenta);
	~cHospital();

	void ContarFueraServicio();

	string To_String();
	void Imprimir();


};

