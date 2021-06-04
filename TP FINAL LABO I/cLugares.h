#pragma once
#include<iostream>
#include<string>
using namespace std;

class cLugares
{
	bool Localizado;
	string Nombre, Pabellon;
	int Piso;


public:
	cLugares();
	~cLugares();
	void RastrearEquipo();

	string To_String();
	void Imprimir();

};

