#include "Cliente.h"
#include <iostream>
using namespace std;

Cliente::Cliente()
{
    nombre = "";
    cedula = "";
    edad = 0;
}

Cliente::Cliente(string n, string c, int e)
{
    nombre = n;
    cedula = c;
    edad = e;
}

void Cliente::mostrarCliente()
{
    cout << "Nombre del cliente: " << nombre << endl;
    cout << "Cedula del cliente: " << cedula << endl;
    cout << "Edad del cliente: " << edad << endl;
}

void Cliente::introducirCliente()
{
    cout << "Ingrese el nombre del cliente: ";
    cin >> nombre;

    cout << "Ingrese la cedula del cliente: ";
    cin >> cedula;

    cout << "Ingrese la edad del cliente: ";
    cin >> edad;
}
