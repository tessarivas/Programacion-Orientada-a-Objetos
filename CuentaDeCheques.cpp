#include "CuentaDeCheques.h"
// Librerias
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>

// Atajo para la impresion de mensajes
using std::cout;
using std::endl;

// Constructor para inicializar atributos cuando se cree una cuenta
CuentaDeCheques::CuentaDeCheques(int num, const Persona& prop, int saldo_inicial)
{
    numero_cuenta = num;
    propietario = prop;
    saldo = saldo_inicial;
}

// Incrementar la cantidad del saldo actual
void CuentaDeCheques::depositar_dinero(int cantidad) 
{
    saldo += cantidad;
    // Actualizar la fecha de ultima transacción
    time_t tm;
    time(&tm);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &tm);
    fecha = buffer;
}

// Decrementar el saldo
void CuentaDeCheques::retirar_dinero(int cantidad) 
{
    if (saldo >= cantidad) 
    {
        saldo -= cantidad;
        // Actualizar la fecha de ultima transacción
        time_t tm;
        time(&tm);
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &tm);
        fecha = buffer;
    }
    else 
    {
        cout << "Fondos insuficientes." << endl;
    }
}

// Condicion para verificar si contamos con saldo primero, y ya de ahi
// verificar si se puede hacer la transferencia.
void CuentaDeCheques::transferencia(CuentaDeCheques& destino, int cantidad) 
{
    if (saldo >= cantidad) 
    {
        saldo -= cantidad;
        destino.depositar_dinero(cantidad);
        // Actualizar la fecha de ultima transacción
        time_t tm;
        time(&tm);
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &tm);
        fecha = buffer;
        destino.fecha = buffer;
    }
    else 
    {
        cout << "Fondos insuficientes." << endl;
    }
}

void CuentaDeCheques::imprimir_estado_cuenta_inicial()
{
    cout << "Numero de cuenta: " << numero_cuenta << endl;
    cout << "Propietario: " << propietario.GetNombre() << endl;
    cout << "Saldo: " << saldo << endl;
}

void CuentaDeCheques::imprimir_estado_cuenta() 
{
    cout << "Numero de cuenta: " << numero_cuenta << endl;
    cout << "Propietario: " << propietario.GetNombre() << endl;
    cout << "Saldo: " << saldo << endl;
    cout << "Fecha de ultima transaccion: " << fecha << endl;
}