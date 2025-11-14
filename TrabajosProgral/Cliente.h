#pragma once
#include <string>
using namespace std;

class Cliente
{
private:
    int edad;

public:
    Cliente();
    Cliente(string, string, int);

    void mostrarCliente();
    void introducirCliente();

    string nombre;
    string cedula;
};