#pragma once
#include<iostream>
#include<string>
#include"cEnum.h"

using namespace std;

class cReparacion
{
	string Codigo;
	float  Precio;
	cProblema Problema_;
public:
	cReparacion(string Cod_, float precio_, cProblema probl);
	~cReparacion();

	string To_String();
	void Imprimir();

};

