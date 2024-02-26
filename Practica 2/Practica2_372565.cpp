// Practica2_372565.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

// Librerias
#include <iostream>
#include <ctime>
#include "Persona.h"
#include "CuentaDeCheques.h"

// Atajo para la impresion de mensajes
using std::cout;
using std::endl;

int main()
{
    // Crear instancias de la clase Persona para los propietarios de las cuentas
    Persona propietario1("Andrea", 12);
    Persona propietario2("Teresa", 19);
    Persona propietario3("Isaac", 23);

    // Crear cuentas de cheques para los propietarios
    CuentaDeCheques cuenta1(1001, propietario1, 5000);
    CuentaDeCheques cuenta2(1002, propietario2, 10000);
    CuentaDeCheques cuenta3(1003, propietario3, 100);

    // Imprimir estado de cuenta inicial
    cout << "----------------------------------------" << endl;
    cout << "        ESTADO DE CUENTA INCIAL:        " << endl;
    cout << "----------------------------------------" << endl;
    cout << endl;

    cout << "CUENTA 1:" << endl;
    cuenta1.imprimir_estado_cuenta_inicial();
    cout << endl;

    cout << "CUENTA 2:" << endl;
    cuenta2.imprimir_estado_cuenta_inicial();
    cout << endl;

    cout << "CUENTA 3:" << endl;
    cuenta3.imprimir_estado_cuenta_inicial();
    cout << endl;

    // Realizar operaciones
    cuenta1.depositar_dinero(1000);
    cuenta2.retirar_dinero(2000);
    cuenta1.transferencia(cuenta2, 3000);
    cuenta2.transferencia(cuenta3, 1000);

    cout << "----------------------------------------" << endl;
    cout << "DESPUES DE LAS TRANSACCIONES REALIZADAS:" << endl;
    cout << "----------------------------------------" << endl;
    cout << endl;

    // Imprimir estado de cuenta
    cout << "Estado de cuenta de la cuenta 1:" << endl;
    cuenta1.imprimir_estado_cuenta();
    cout << endl;

    cout << "Estado de cuenta de la cuenta 2:" << endl;
    cuenta2.imprimir_estado_cuenta();
    cout << endl;

    cout << "Estado de cuenta de la cuenta 3:" << endl;
    cuenta3.imprimir_estado_cuenta();
    cout << endl;

    return 0;
}