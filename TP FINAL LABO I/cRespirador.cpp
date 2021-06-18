#include "cRespirador.h"

cRespirador::cRespirador(string Nom_, const string COD, string Dim, float Peso, cLugares* Lugar_Guardar_) :cEquipoMedico(Nom_, COD, Dim, Peso, Lugar_Guardar_)
{
	Alarma_Alta_Presion = true;
	Alarma_Baja_Presion = true;
	Flujo = 100;
	FlujoConfigurado = 100;
	FlujoSalida = 100;
}

cRespirador::~cRespirador()
{
}

void cRespirador::Imprimir()
{
}

string cRespirador::To_String()
{
	return string();
}

void cRespirador::MantenimientoPreventivo()
{
	try
	{
		if (Alarma_Alta_Presion == false || Alarma_Baja_Presion == false)
		{
			throw new exception("Las alarmas no funcionan");
			_Estado = cEstado::FUERA_SERVICIO;
		}
	}
	catch (const std::exception& ex1)
	{
		cout << ex1.what() << endl;
		MantenimientoCorrectivo();
	}
	try
	{
		if (Flujo != FlujoConfigurado || FlujoSalida == 0)
		{
			throw new exception("Existen problemas con el fujo de oxigeno.");
			_Estado = cEstado::FUERA_SERVICIO;
		}
	}
	catch (const std::exception& ex2)
	{
		cout << ex2.what() << endl;
		MantenimientoCorrectivo(Flujo);
	}
}

void cRespirador::MantenimientoCorrectivo()
{
	Alarma_Alta_Presion = true;
	Alarma_Baja_Presion = true;
	_Estado = cEstado::EN_ESPERA;
}

void cRespirador::MantenimientoCorrectivo(float flujo_)
{
	Flujo = FlujoConfigurado;
	FlujoSalida = 100;
	_Estado = cEstado::EN_ESPERA;

}

void cRespirador::ConfigurarFlujo(float aux_)
{
	FlujoConfigurado = aux_;
}
