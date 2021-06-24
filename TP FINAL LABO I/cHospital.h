#pragma once
#include<iostream>
#include<string>
#include"cListaDer.h"

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
	void ListarEquiposFueraLugar();

	string To_String();
	void Imprimir();

	friend class cElectrocardiografo;
	friend class cRespirador;
	friend class cMesaAnestesia;

};

