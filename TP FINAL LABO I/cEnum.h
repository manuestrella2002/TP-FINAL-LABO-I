#pragma once

enum class cEstado //enum de estados de los	equipos
{
	EN_USO,
	EN_ESPERA,
	FUERA_SERVICIO,
	MANTENIMIENTO
};
enum class cProblema // enum de los problemas a reparar
{
	ELECTRICO,
	FALTA_COMPONENTE,
	MECANICO,
	ESPECIALIZADO,
	EN_ESPERA,
};