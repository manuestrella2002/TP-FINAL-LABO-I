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
	
	cLugares* Consultorio = new cLugares("Consultorio", "A", 2);
	cLugares* Anestesia = new cLugares("Anestesia", "B", 3);
	cLugares* Hemodinamia = new cLugares("Hemodinamia", "A", 1);
	cLugares* Quirofano = new cLugares("Quirofano", "C", 1);


	
	cElectrocardiografo* Electro1 = new cElectrocardiografo("DJ DONG JIANG", "cm300", "318x264x152mm", 4.5,Hemodinamia);
	cMesaAnestesia* Mesa1 = new cMesaAnestesia("Beta", "pr450", "700x480x930", 80,Anestesia);
	cRespirador* Respirador1 = new cRespirador("Alpha", "bx200", "400x300x450", 50, Quirofano);

	//la repacion se crea cuando hacemos el mantenimiento y cumple con los requisitos para arreglos

	//agregamos a la lista con la sobrecarga +
	(*Hospital->ListaLugares) + Consultorio;
	(*Hospital->ListaLugares) + Anestesia;
	(*Hospital->ListaLugares) + Hemodinamia;
	(*Hospital->ListaLugares) + Quirofano;

	(*Hospital->ListaEquipos) + Electro1;
	(*Hospital->ListaEquipos) + Mesa1;
	(*Hospital->ListaEquipos) + Respirador1;

	/*
	Electro1->Imprimir();
	Mesa1->Imprimir();
	Respirador1->Imprimir();
	Consultorio->Imprimir();
	calendario->Imprimir();
	*/
	//sobrecarga del cout en cLugares
		cout << Consultorio;

		//Vamos a controlar entorno a cHospital 

	return 0;
}