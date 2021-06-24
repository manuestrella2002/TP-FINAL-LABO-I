#include "cRespirador.h"
#include"cHospital.h"
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

void cRespirador::MantenimientoPreventivo(cListaT <cReparacion>* ListaReparaciones)
{
	try
	{
		if (Alarma_Alta_Presion == false || Alarma_Baja_Presion == false)
		{
			throw new exception("Las alarmas no funcionan");
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

istream& operator>>(istream& in, cRespirador& Respirador)
{
	// TODO: insert return statement here
}

ostream& operator<<(ostream& out, cRespirador& Respirador)
{
	string aux1, aux2;
	if (Respirador.Alarma_Alta_Presion == true)
	{
		aux1 = "Alarma de presion alta ";
	}
	if (Respirador.Alarma_Baja_Presion)
	{
		aux2 = "Alarma de presion baja";
	}
	cout << "\nRESPIRADOR\n Nombre" << Respirador.Nombre << endl;
	cout << Respirador.Descripcion << endl;
	cout << "Codigo: " << Respirador.codigo << endl;
	cout << "Dimensiones: " << Respirador.Dimension << endl;
	cout << "Peso: " << Respirador.Peso << endl;
	cout << "Lugar actual: " << Respirador.Lugar_Actual << "\t Lugar de guardado: " << Respirador.Lugar_Guardar << endl;
	if (Respirador.Alarma_Alta_Presion == true)
	{
		cout << "Alarma de presion alta " << endl;
	}
	else if (Respirador.Alarma_Baja_Presion)
	{
		cout << "Alarma de presion baja" << endl;
	}
	cout << "Flujo: " << Respirador.Flujo << endl;
	cout << "Flujo configurado: " << Respirador.FlujoConfigurado << endl;
	cout << "Flujo de salida: " << Respirador.FlujoSalida << endl;
	cout << "Fecha de ultimo mantenimiento: " << Respirador.Fecha_ult_Mant << endl;
}
