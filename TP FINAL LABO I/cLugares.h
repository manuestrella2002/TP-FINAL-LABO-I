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
	bool VerificarLocalizado();

	string To_String();
	void Imprimir();

};

//DEBE IR ESTO ACA??
ostream& operator << (ostream& out, cLugares& lugar)
{
	lugar.Imprimir();
}

