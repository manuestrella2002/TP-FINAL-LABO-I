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
	cLugares(string nom_, string pabellon_, int piso_);
	~cLugares();
	void RastrearEquipo();

	string To_String();
	void Imprimir();

};
ostream& operator << (ostream out, cLugares& lugar);

