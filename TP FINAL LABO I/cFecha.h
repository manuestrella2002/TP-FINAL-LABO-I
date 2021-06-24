#pragma once
#include<string>
#include<iostream>
using namespace std;
class cFecha
{
	int dia, mes, anio;

public:
	cFecha(int dia_,int mes_, int anio_);
	~cFecha();
	string getclave();

	int getdia();
	int getmes();
	int getanio();
};

