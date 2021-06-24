#pragma once
#include<iostream>
#include<string>
#include"cFecha.h"
#define N 150
using namespace std;



class cCalendario
{
protected:
	cFecha** vector;
	int CA, TAM;
	

public:
	cCalendario(int TAM=N);
	~cCalendario();
	bool AgregarItem(cFecha* item);
	cFecha* BuscarItem(string clave);
	cFecha* getItem(int pos);

	 int getCA();
	 int getTAM();

	cFecha* operator[](int pos);
	void operator+(cFecha* item);
};

inline cCalendario::cCalendario(int TAM)
{
	vector = new cFecha * [TAM];
	for (int i = 0; i < TAM; i++)
	{
		vector[i] = NULL;
	}

	this->TAM = TAM;
	CA = 0;
}

inline cCalendario::~cCalendario()
{
	if (vector != NULL)
	{
		for ( int i = 0; i < CA; i++)
		{
			if (vector[i] != NULL)
				delete vector[i];
		}
		delete[] vector;
	}
}
inline bool cCalendario::AgregarItem(cFecha* item)
{

	cFecha* i_f = BuscarItem(item->getclave());
	if (i_f != NULL)throw new exception("Ya se encuentra en la lista");

	if (CA < TAM)
		vector[CA++] = item;
	else throw new exception("No hay tamaño suficiente para agregar el item");;
	return true;
}
inline cFecha* cCalendario::BuscarItem(string clave)
{
	for (int i = 0; i < CA; i++)
	{
		if (vector[i]->getclave() == clave)
			return vector[i];
	}
	return NULL;
}

inline cFecha* cCalendario::getItem(int pos)
{
	if (pos < CA)
		return vector[pos];
	else return NULL;
}

inline int cCalendario::getCA()
{
	return CA;
}

inline int cCalendario::getTAM()
{
	return TAM;
}

inline cFecha* cCalendario::operator[](int pos)
{
	return getItem(pos);
}

inline void cCalendario::operator+(cFecha* item)
{
	AgregarItem(item);
}