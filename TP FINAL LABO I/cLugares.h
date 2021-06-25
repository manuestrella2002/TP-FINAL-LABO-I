#pragma once
#include<iostream>
#include<string>
using namespace std;

class cLugares
{
	bool Localizado; //se usa para decir que el equipo fue encontrado efectivamente
	string Nombre, Pabellon;
	int Piso;


public:
	cLugares(string nom_, string pabellon_, int piso_);
	~cLugares();
	bool VerificarLocalizado();
	string getclave();

	string To_String();
	void Imprimir();

};
