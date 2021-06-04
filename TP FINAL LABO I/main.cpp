#include<iostream>
#include<string>

#include "cHospital.h"
#include "cElectrocardiografo.h"
#include "cMesaAnestesia.h"
#include "cRespirador.h"

using namespace std;
int main()
{
	cHospital* Hospital = new cHospital("Favaloro", "Entre Rios 2550", 10000000);
	cElectrocardiografo* Electro1 = new cElectrocardiografo("DJ DONG JIANG", "cm300", "318x264x152mm", 4.5);
	cMesaAnestesia* Mesa1 = new cMesaAnestesia("Beta", "pr450", "700x480x930", 80);
	cRespirador* Respirador1 = new cRespirador("Alpha", "bx200", "400x300x450", 50);

	cLugares* Consultorio = new cLugares("Consultorio", "A", 2);
	cCalendario* calendario = new cCalendario();
	//la repacion se crea cuando hacemos el mantenimiento y cumple con los requisitos para arreglos

	//agregamos a la lista con la sobrecarga +
	(*Hospital->ListaEquipos) + Electro1;
	(*Hospital->ListaEquipos) + Mesa1;
	(*Hospital->ListaEquipos) + Respirador1;
	(*Hospital->ListaLugares) + Consultorio;

	Electro1->Imprimir();
	Mesa1->Imprimir();
	Respirador1->Imprimir();
	Consultorio->Imprimir();
	calendario->Imprimir();

	//sobrecarga del cout en cLugares
		cout << Consultorio;

		//Vamos a controlar entorno a cHospital 

	return 0;
}