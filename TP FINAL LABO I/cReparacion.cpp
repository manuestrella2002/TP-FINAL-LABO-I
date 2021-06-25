#include "cReparacion.h"

cReparacion::cReparacion(string Cod_, float precio_, cProblema probl)
{
	Codigo = Cod_;
	Precio = precio_;
	Problema_ = probl;
}

cReparacion::~cReparacion()
{
}

string cReparacion::getclave()
{
	return Codigo;
}

float cReparacion::GetPrecio()
{
	return Precio;
}

string cReparacion::To_String()
{
	string aux;
	switch (Problema_)
	{
	case cProblema::ELECTRICO:
	{
		aux = "Electrico";
		break;
	}
	case cProblema::EN_ESPERA:
	{
		aux = "En espera";
		break;
	}
	case cProblema::ESPECIALIZADO:
	{
		aux = "Especializado";
		break;
	}
	case cProblema::FALTA_COMPONENTE:
	{
		aux = "Falta componente";
		break;
	}
	case cProblema::MECANICO:
	{
		aux = "Mecanico";
		break;
	}
	}
	string cadena = "\nREPARACIONES\nCodigo: " + Codigo + "\nPrecio: " + to_string(Precio) +
		"\nProblema: " + aux;
	return cadena;
}

void cReparacion::Imprimir()
{
	cout << To_String();
}
