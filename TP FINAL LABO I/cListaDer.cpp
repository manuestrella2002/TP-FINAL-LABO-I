#include"cListaDer.h"
 cListaDer::cListaDer(unsigned int TAM) :cListaT(TAM)
{
}

 cListaDer::~cListaDer()
{
}


 void cListaDer::RastrearEquipo()
{

	for (int i = 0; i < CA; i++)
	{
		if (vector[i]->VerificarLugares() == false)
		{
			vector[i]->ImprimirAlerta();
		}
	}

}

 int cListaDer::ContarEquipF_Serv()
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

 cEquipoMedico* cListaDer::operator[](unsigned int pos)
 {
	 cEquipoMedico* i_T = getItem(pos);
	 
	 return i_T;
 }

