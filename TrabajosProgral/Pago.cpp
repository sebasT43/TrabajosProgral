#include "Pago.h"
#include <iostream>
using namespace std;

Pago::Pago()
{
    monto = 0;
    metodo = "";
}

Pago::Pago(Cliente c, float m, string me)
{
    cliente = c;
    monto = m;
    metodo = me;
}

void Pago::mostrarPago()
{
    cout << "Cliente: " << cliente.nombre
        << " | Cedula: " << cliente.cedula << endl;
    cout << "Monto pagado: " << monto << endl;
    cout << "Metodo de pago: " << metodo << endl;
    cout << "-----------------------------------" << endl;
}
