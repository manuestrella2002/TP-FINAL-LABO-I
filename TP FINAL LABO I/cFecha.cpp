#include "cFecha.h"

cFecha::cFecha(int dia_, int mes_, int anio_)
{
	dia = dia_;
	mes = mes_;
	anio = anio_;
}

cFecha::~cFecha()
{
}

string cFecha::getclave()
{
	string cadena;
	cadena = to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
	return cadena;
}

int cFecha::getdia()
{
	return dia;
}

int cFecha::getmes()
{
	return mes;
}

int cFecha::getanio()
{
	return anio;
}
