#pragma once
#include "Cliente.h"
#include <string>
using namespace std;

class Pago
{
public:
    Cliente cliente;
    float monto;
    string metodo;

    Pago();
    Pago(Cliente c, float m, string me);

    void mostrarPago();
};
