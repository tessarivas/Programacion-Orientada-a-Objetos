#pragma once
#include "Persona.h"
#include <string>

class CuentaDeCheques
{
	// Datos protegidos
protected:
	// Lo que contiene la cuenta de cheques
	int numero_cuenta;
	Persona propietario;
	int saldo;
	std::string fecha;
	// Datos publicos
public:
	// Cuenta de cheques inicial.
    CuentaDeCheques(int num, const Persona& prop, int saldo_inicial);
	// Acciones que se pueden manejar con la cuenta de cheques
    void depositar_dinero(int cantidad);
    void retirar_dinero(int cantidad);
    void transferencia(CuentaDeCheques& destino, int cantidad);
	void imprimir_estado_cuenta_inicial();
	void imprimir_estado_cuenta();
};