#pragma once
#include "cListaT.h"
#include "cEquipoMedico.h"

class cListaDer : public cListaT<cEquipoMedico>
{
public:
	cListaDer(unsigned int TAM=NMAX);
	~cListaDer();

	void RastrearEquipo();
	int ContarEquipF_Serv();

	cEquipoMedico* operator[](unsigned int pos);


};
