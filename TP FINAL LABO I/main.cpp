#include<iostream>
#include<string>
#include<stdlib.h>

#include "cHospital.h"
#include "cElectrocardiografo.h"
#include "cMesaAnestesia.h"
#include "cRespirador.h"



using namespace std;
int main()
{

	cHospital* Hospital = new cHospital("Favaloro", "Entre Rios 2550", 10000000);

	
	Hospital->Inicializar();

	Hospital->Funcionamiento();
	


	Hospital->ListaLugares->getItem(0)->Imprimir();
	Hospital->ListaLugares->getItem(1)->Imprimir();
	Hospital->ListaLugares->getItem(2)->Imprimir();
	Hospital->ListaLugares->getItem(3)->Imprimir();
	system("\nPause");
	system("cls");

		//Vamos a controlar entorno a cHospital 
	Hospital->FinalizarDia();

	return 0;
}