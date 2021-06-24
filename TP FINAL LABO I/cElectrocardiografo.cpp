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

istream& operator>>(istream& in, cElectrocardiografo& Equipo)
{
	// TODO: insert return statement here
}

ostream& operator<<(ostream& out, const cElectrocardiografo& Equipo)
{
	string auxVF, auxVL, auxVR;
	if (Equipo.Der_aVF == true)
	{
		auxVF = "Derivada aVF: potencial absoluto";
	}
	else if (Equipo.Der_aVL == true)
	{
		auxVL = "Derivada aVL: potencial absoluto";
	}
	else if (Equipo.Der_aVR == true)
	{
		auxVR = "Derivada aVR: potencial absoluto";
	}

	cout << "\nELECTROCARDIOGRAFO\n Nombre" << Equipo.Nombre << endl;
	cout << Equipo.Descripcion << endl;
	cout << "Codigo: " << Equipo.codigo << endl;
	cout << "Dimensiones: " << Equipo.Dimension << endl;
	cout << "Peso: " << Equipo.Peso << endl;
	cout << "Lugar actual: " << Equipo.Lugar_Actual << "\t Lugar de guardado: " << Equipo.Lugar_Guardar << endl;
	if (Equipo.Der_aVF == true)//pueden pasar todos a la vez
	{
		cout << "Derivada aVF: potencial absoluto" << endl;
	}
	if (Equipo.Der_aVL == true)
	{
		cout << "Derivada aVL: potencial absoluto" << endl;
	}
	if (Equipo.Der_aVR == true)
	{
		cout << "Derivada aVR: potencial absoluto" << endl;
	}
	cout << "Fecha de ultimo mantenimiento: " << Equipo.Fecha_ult_Mant << endl;

 }
