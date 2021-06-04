#pragma once
#include<iostream>
#include<string>
using namespace std;


class cCalendario
{
	tm* ListaFechaMantenimiento;

public:
	cCalendario();
	~cCalendario();
	void Imprimir();
};

