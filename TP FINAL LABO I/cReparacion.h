#pragma once
#include<iostream>
#include<string>
using namespace std;
enum Problema
{
	ELECTRICO,
	FALTA_COMPONENTE,
	MECANICO,
	ESPECIALIZADO,
	EN_ESPERA,
};
class cReparacion
{
	string Codigo;
	float  Precio;
	Problema Problema;
public:
	cReparacion();
	~cReparacion();

	string To_String();
	void Imprimir();

};

