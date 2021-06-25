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
void cElectrocardiografo::MantenimientoPreventivo(cListaT <cReparacion>* ListaReparaciones)
{
	try
	{
		if (Der_aVF == false || Der_aVL == false || Der_aVR == false)
		{ 
			//alguno de los sensores no funciona, se debe arreglar 
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

void cElectrocardiografo::SetPeso(float peso_)
{
	Peso = peso_;
}

istream& operator>>(istream& in, cElectrocardiografo& Equipo)
{
	float aux;
	cout << "Ingrese el peso: " << endl;
	in >> aux;
	Equipo.SetPeso(aux);
	return in;
}

ostream& operator<<(ostream& out, const cElectrocardiografo& Equipo)
{

	cout << "\nELECTROCARDIOGRAFO\n Nombre" << Equipo.Nombre << endl;
	cout << Equipo.Descripcion << endl;
	cout << "Codigo: " << Equipo.codigo << endl;
	cout << "Dimensiones: " << Equipo.Dimension << endl;
	cout << "Peso: " << Equipo.Peso << endl;
	cout << "Lugar actual: " << endl;
	Equipo.Lugar_Actual->Imprimir();
	cout << "\t Lugar de guardado: " << endl;
	Equipo.Lugar_Guardar->Imprimir();
	if (Equipo.Der_aVF == true && Equipo.Der_aVL == true && Equipo.Der_aVR == true)//pueden pasar todos a la vez
	{
		cout << "El electrocardiografo funciona correctamente" << endl;
	}
	cout << "Fecha de ultimo mantenimiento: " << Equipo.Fecha_ult_Mant->tm_mday << "/" << Equipo.Fecha_ult_Mant->tm_mon << "/" << Equipo.Fecha_ult_Mant->tm_year << endl;
	return out;
 }
