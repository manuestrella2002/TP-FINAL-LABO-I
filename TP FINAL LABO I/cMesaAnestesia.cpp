#include "cMesaAnestesia.h"
#include"cHospital.h"
cMesaAnestesia::cMesaAnestesia(string Nom_, const string COD, string Dim, float Peso, cLugares* Lugar_Guardar_):cEquipoMedico(Nom_,COD,Dim,Peso,Lugar_Guardar_)
{
	//SI LAS ALARMAS SON TRUE ES QUE FUNCIONAN
	Alarma_Alta_FrecCard = false;
	Alarma_Baja_FrecCard = false;
	Nivel_Sue�o = 100;
	Volumen_Flujo = 100;
}

cMesaAnestesia::~cMesaAnestesia()
{
}

void cMesaAnestesia::MantenimientoPreventivo(cListaT<cReparacion>* ListaReparaciones)
{
	try
	{
		if (Alarma_Alta_FrecCard == false || Alarma_Baja_FrecCard == false)
		{
			//si las alarmas no funcionan corecctamente hay que cambiarlas, se hace reparacion
			throw new exception("\nLas alarmas no funicionan. Se las cambian");
			_Estado = cEstado::FUERA_SERVICIO;
			cReparacion* Reparacion = new cReparacion(getclave(), 5000, cProblema::ELECTRICO);
			ListaReparaciones->AgregarItem(Reparacion);
			delete Reparacion;
		}
	}
	catch (const std::exception& ex1)
	{
		cout << ex1.what() << endl;
		MantenimientoCorrectivo();
	}

	try
	{
		if (Nivel_Sue�o<=20)
		{
			//si el nivel de sue�o es muy bajo entonces se debe reparar
			throw new exception("\nEl nivel de sue�o es muy bajo.");
			_Estado = cEstado::FUERA_SERVICIO;
			cReparacion* Reparacion = new cReparacion(getclave(), 1000, cProblema::ESPECIALIZADO);
			ListaReparaciones->AgregarItem(Reparacion);
			delete Reparacion;
		}
	}
	catch (const std::exception& ex2)
	{
		cout << ex2.what() << endl;
		MantenimientoCorrectivo(Nivel_Sue�o);
	}

	try
	{
		if (Volumen_Flujo== 0)
		{
			//el volumen no funciona bien, por lo que hay que repararlo 
			throw new exception("\nExiste un taponamiento en la maquina. Flujo 0");
			_Estado = cEstado::FUERA_SERVICIO;
			cReparacion* Reparacion = new cReparacion(getclave(), 2000, cProblema::MECANICO);
			ListaReparaciones->AgregarItem(Reparacion);
			delete Reparacion;

		}

	}
	catch (const std::exception& ex3)
	{
		cout << ex3.what() << endl;
		MantenimientoCorrectivo(Volumen_Flujo);

	}
}

void cMesaAnestesia::MantenimientoCorrectivo(int nivel_)
{
	//arregla si lo que funciona mal es el nivel del sue�o
	Nivel_Sue�o = 100;
	_Estado = cEstado::EN_ESPERA;
}

void cMesaAnestesia::MantenimientoCorrectivo()
{
	//arregla si las alarmas no funcionan como corresponde
	Alarma_Alta_FrecCard = true;
	Alarma_Baja_FrecCard = true;
	_Estado = cEstado::EN_ESPERA;
}

void cMesaAnestesia::MantenimientoCorrectivo(float Volumen_)
{
	//pone el flujo de vuelta a la normalidad
	Volumen_Flujo = 100;
	_Estado = cEstado::EN_ESPERA;
}

void cMesaAnestesia::SetSue�o(int sue�o_)
{
	Nivel_Sue�o = sue�o_;
}

istream& operator>>(istream& in, cMesaAnestesia& Mesa)
{
	float aux;
	cout << "Ingrese el nivel del sue�o: " << endl;
	in >> aux;
	Mesa.SetSue�o(aux);
	return in;
}

ostream& operator<<(ostream& out, cMesaAnestesia& Mesa)
{
	
	cout << "\nMESA DE ANESTESIA\n Nombre" << Mesa.Nombre << endl;
	cout << Mesa.Descripcion << endl;
	cout << "Codigo: " << Mesa.codigo << endl;
	cout << "Dimensiones: " << Mesa.Dimension << endl;
	cout << "Peso: " << Mesa.Peso << endl;
	cout << "Lugar actual: " << endl;
	Mesa.Lugar_Actual->Imprimir();
	cout << "\t Lugar de guardado: " << endl;
	Mesa.Lugar_Guardar->Imprimir();
	cout << "Nivel del sue�o: " << Mesa.Nivel_Sue�o << endl;
	cout << "Volumen de flujo: " << Mesa.Volumen_Flujo << endl;
	if (Mesa.Alarma_Alta_FrecCard == true && Mesa.Alarma_Baja_FrecCard == true)
	{
		cout << "Las alarmas funcionan correctamente" << endl;
	}
	cout << "Fecha de ultimo mantenimiento: " <<Mesa.Fecha_ult_Mant->tm_mday << "/" << Mesa.Fecha_ult_Mant->tm_mon << "/" << Mesa.Fecha_ult_Mant->tm_year << endl;
	return out;
}
