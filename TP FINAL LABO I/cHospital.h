#pragma once
#include<iostream>
#include<string>
#include<ctime>
#include"cListaDer.h"

using namespace std;

class cHospital
{
protected:
	float CostosEquiposMant, CuentaCorriente;
	string Direccion, Nombre;
	int Cant_Equip_F_Serv;


public:
	cListaDer* ListaEquipos;
	cListaT <cLugares>* ListaLugares;
	cListaT <cReparacion>* ListaReparaciones;


	cHospital(string nom_, string direc_, float cuenta);
	~cHospital();

	void ContarFueraServicio();
	void HacerMantenimiento();
	void ListarEquiposFueraLugar();

	friend class cElectrocardiografo;
	friend class cRespirador;
	friend class cMesaAnestesia;

	void FinalizarDia(); //se fija que la cantidad de equipos sea mayor que 5 o que el costo sea mayor a 
	//2000 dolares para realizar el mantenimiento correctivo, y tambien lista los equipos fuera de lugar

};

