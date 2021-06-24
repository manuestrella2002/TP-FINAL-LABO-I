#include "cElectrocardiografo.h"
#include"cHospital.h"

cElectrocardiografo::cElectrocardiografo(string Nom_, const string COD, string Dim, float Peso, cLugares* LugarGuardar_):cEquipoMedico(Nom_,COD,Dim,Peso,LugarGuardar_)
{
	Der_aVF = true;
	Der_aVL = true;
	Der_aVR = true;

}

cElectrocardiografo::~cElectrocardiografo()
{
}

void cElectrocardiografo::Imprimir()
{
}

string cElectrocardiografo::To_String()
{
	return string();
}

void cElectrocardiografo::MantenimientoPreventivo(cListaT <cReparacion>* ListaReparaciones)
{
	try
	{
		if (Der_aVF == false || Der_aVL == false || Der_aVR == false)
		{
			throw new exception("\nEl sensor no funciona. Se lo cambia.");
			_Estado = cEstado::FUERA_SERVICIO;
			cReparacion* Reparacion = new cReparacion(getclave(), 2000, cProblema::ELECTRICO);
			
			ListaReparaciones->AgregarItem(Reparacion);

			delete Reparacion;
		}
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
		//SE IMPRIMI FALLO EN EL SENSOR Y LLAMA A MANTENIMIENTO CORRECTIVO
		MantenimientoCorrectivo();
	}

}

void cElectrocardiografo::MantenimientoCorrectivo()
{
	//SE CAMBIAN LOS SENSORES
	Der_aVF = true;
	Der_aVL = true;
	Der_aVR = true;
	_Estado = cEstado::EN_ESPERA;

}
