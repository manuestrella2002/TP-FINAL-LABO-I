#include "cMesaAnestesia.h"
#include"cHospital.h"
cMesaAnestesia::cMesaAnestesia(string Nom_, const string COD, string Dim, float Peso, cLugares* Lugar_Guardar_):cEquipoMedico(Nom_,COD,Dim,Peso,Lugar_Guardar_)
{
	//SI LAS ALARMAS SON TRUE ES QUE FUNCIONAN
	Alarma_Alta_FrecCard = false;
	Alarma_Baja_FrecCard = false;
	Nivel_Sueño = 100;
	Volumen_Flujo = 100;
}

cMesaAnestesia::~cMesaAnestesia()
{
}

void cMesaAnestesia::Imprimir()
{
}

string cMesaAnestesia::To_String()
{
	return string();
}

void cMesaAnestesia::MantenimientoPreventivo(cListaT<cReparacion>* ListaReparaciones)
{
	try
	{
		if (Alarma_Alta_FrecCard == false || Alarma_Baja_FrecCard == false)
		{
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
		if (Nivel_Sueño<=20)
		{
			throw new exception("\nEl nivel de sueño es muy bajo.");
			_Estado = cEstado::FUERA_SERVICIO;
			cReparacion* Reparacion = new cReparacion(getclave(), 1000, cProblema::ESPECIALIZADO);
			ListaReparaciones->AgregarItem(Reparacion);
			delete Reparacion;
		}
	}
	catch (const std::exception& ex2)
	{
		cout << ex2.what() << endl;
		MantenimientoCorrectivo(Nivel_Sueño);
	}

	try
	{
		if (Volumen_Flujo== 0)
		{
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
	Nivel_Sueño = 100;
	_Estado = cEstado::EN_ESPERA;
}

void cMesaAnestesia::MantenimientoCorrectivo()
{
	Alarma_Alta_FrecCard = true;
	Alarma_Baja_FrecCard = true;
	_Estado = cEstado::EN_ESPERA;
}

void cMesaAnestesia::MantenimientoCorrectivo(float Volumen_)
{
	Volumen_Flujo = 100;
	_Estado = cEstado::EN_ESPERA;
}

