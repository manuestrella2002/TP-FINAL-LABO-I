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

void cRespirador::MantenimientoPreventivo(cListaT <cReparacion>* ListaReparaciones)
{
	try
	{
		if (Alarma_Alta_Presion == false || Alarma_Baja_Presion == false)
		{
			//las alarmas correspondientes no funcionan
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
			//si el flujo no es el deseado o si hay un taponamiento, hay un problema
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
	//arregla las alarmas de las presiones
	Alarma_Alta_Presion = true;
	Alarma_Baja_Presion = true;
	_Estado = cEstado::EN_ESPERA;
}

void cRespirador::MantenimientoCorrectivo(float flujo_)
{
	//resuelve los problemas del flujo
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
	float aux;
	cout << "Ingrese el fujo a configurar: " << endl;
	in >> aux;
	Respirador.ConfigurarFlujo(aux);
	return in;
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
	cout << "Lugar actual: " << endl;
	Respirador.Lugar_Actual->Imprimir();
	cout << "\t Lugar de guardado: " << endl;
	Respirador.Lugar_Guardar->Imprimir();
	if (Respirador.Alarma_Alta_Presion == true && Respirador.Alarma_Baja_Presion == true)
	{
		cout << "El respirador funciona correctamente" << endl;
	}
	cout << "Flujo: " << Respirador.Flujo << endl;
	cout << "Flujo configurado: " << Respirador.FlujoConfigurado << endl;
	cout << "Flujo de salida: " << Respirador.FlujoSalida << endl;
	cout << "Fecha de ultimo mantenimiento: " << Respirador.Fecha_ult_Mant->tm_mday << "/" << Respirador.Fecha_ult_Mant->tm_mon << "/" << Respirador.Fecha_ult_Mant->tm_year << endl;
	return out;
}
