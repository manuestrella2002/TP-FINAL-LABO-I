#pragma once
#include "cListaT.h"
class cListaDer : public cListaT<cEquipoMedico>
{
public:
	cListaDer(unsigned int TAM=NMAX);
	~cListaDer();

	void RastrearEquipo();
	int ContarEquipF_Serv();



};
inline cListaDer::cListaDer(unsigned int TAM) :cListaT(TAM)
{
}

inline cListaDer::~cListaDer()
{
}


inline void cListaDer::RastrearEquipo()
{
	
	for (int i = 0; i < CA; i++)
	{
		if (vector[i]->VerificarLugares()==false)
		{
			vector[i]->ImprimirAlerta();
		}
	}
	
}

inline int cListaDer::ContarEquipF_Serv()
{
	int cont = 0;
	
	for (int i = 0; i < CA; i++)
	{
		if (vector[i]->ChequearEstado() == cEstado::FUERA_SERVICIO)
		{
			cont++;
		}

	}
	return cont;
}
