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

istream& operator>>(istream& in, cMesaAnestesia& Mesa)
{
	// TODO: insert return statement here
}

ostream& operator<<(ostream& out, cMesaAnestesia& Mesa)
{
	
	cout << "\nMESA DE ANESTESIA\n Nombre" << Mesa.Nombre << endl;
	cout << Mesa.Descripcion << endl;
	cout << "Codigo: " << Mesa.codigo << endl;
	cout << "Dimensiones: " << Mesa.Dimension << endl;
	cout << "Peso: " << Mesa.Peso << endl;
	cout << "Lugar actual: " << Mesa.Lugar_Actual << "\t Lugar de guardado: " << Mesa.Lugar_Guardar << endl;
	cout << "Nivel del sueño: " << Mesa.Nivel_Sueño << endl;
	cout << "Volumen de flujo: " << Mesa.Volumen_Flujo << endl;
	if (Mesa.Alarma_Alta_FrecCard == true)
	{
		cout << "La frecuencia cardiaca es alta " << endl;
	}
	else if (Mesa.Alarma_Baja_FrecCard == true)
	{
		cout << "La frecuencia cardiaca es baja " << endl;
	}
	cout << "Fecha de ultimo mantenimiento: " << Mesa.Fecha_ult_Mant << endl;
}
