#pragma once
#include<iostream>
#include<string>
#include"cLugares.h"
#include"cReparacion.h"
#include"cListaDer.h"
#include"cElectrocardiografo.h"
#include"cMesaAnestesia.h"
#include"cRespirador.h"
using namespace std;

class cHospital
{
protected:
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
	void HacerMantenimiento();

	string To_String();
	void Imprimir();

	friend class cElectrocardiografo;
	friend class cRespirador;
	friend class cMesaAnestesia;

};

