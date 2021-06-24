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

	cFecha* Fecha1 = new cFecha(10, 6, 2021);
	cFecha* Fecha2 = new cFecha(10, 9, 2021);
	cFecha* Fecha3 = new cFecha(10, 12, 2021);

	
	cLugares* Consultorio = new cLugares("Consultorio", "A", 2);
	cLugares* Anestesia = new cLugares("Anestesia", "B", 3);
	cLugares* Hemodinamia = new cLugares("Hemodinamia", "A", 1);
	cLugares* Quirofano = new cLugares("Quirofano", "C", 1);

	cReparacion* Reparacion1 = new cReparacion("101", 2000, cProblema::ELECTRICO);
	cReparacion* Reparacion2 = new cReparacion("102", 5000, cProblema::MECANICO);
	cReparacion* Reparacion3 = new cReparacion("103", 6000, cProblema::EN_ESPERA);
	cReparacion* Reparacion4 = new cReparacion("104", 7000, cProblema::ESPECIALIZADO);

	cElectrocardiografo* Electro1 = new cElectrocardiografo("DJ DONG JIANG", "cm300", "318x264x152mm", 4.5,Hemodinamia);
	cMesaAnestesia* Mesa1 = new cMesaAnestesia("Beta", "pr450", "700x480x930", 80,Anestesia);
	cRespirador* Respirador1 = new cRespirador("Alpha", "bx200", "400x300x450", 50, Quirofano);

	(*Electro1->Calendario) + Fecha1;
	(*Electro1->Calendario) + Fecha2;
	(*Electro1->Calendario) + Fecha3;

	(*Mesa1->Calendario) + Fecha1;
	(*Mesa1->Calendario) + Fecha2;
	(*Mesa1->Calendario) + Fecha3;
	
	(*Respirador1->Calendario) + Fecha1;
	(*Respirador1->Calendario) + Fecha2;
	(*Respirador1->Calendario) + Fecha3;

	


	//la repacion se crea cuando hacemos el mantenimiento y cumple con los requisitos para arreglos
	/*
	(*Hospital->ListaReparaciones) + Reparacion1;
	(*Hospital->ListaReparaciones) + Reparacion2;
	(*Hospital->ListaReparaciones) + Reparacion3;
	(*Hospital->ListaReparaciones) + Reparacion4;
	*/

	//agregamos a la lista con la sobrecarga +
	(*Hospital->ListaLugares) + Consultorio;
	(*Hospital->ListaLugares) + Anestesia;
	(*Hospital->ListaLugares) + Hemodinamia;
	(*Hospital->ListaLugares) + Quirofano;

	(*Hospital->ListaEquipos) + Electro1;
	(*Hospital->ListaEquipos) + Mesa1;
	(*Hospital->ListaEquipos) + Respirador1;
	/*------------------------------------------------------------------------------------------*/
	Hospital->HacerMantenimiento();

	












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

		Hospital->ListarEquiposFueraLugar();

	return 0;
}