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
