#include "Pedido.h"
#include <iostream>
using namespace std;

Pedido::Pedido()
{
    cantidad = 0;
    total = 0;
}

Pedido::Pedido(Cliente c, Productos p, int cant, float t)
{
    cliente = c;
    producto = p;
    cantidad = cant;
    total = t;
}

void Pedido::mostrarPedido()
{
    cout << "Cliente: " << cliente.nombre
        << " | Cedula: " << cliente.cedula << endl;

    cout << "Producto: " << producto.nombre
        << " | Precio unitario: " << producto.precio << endl;

    cout << "Cantidad: " << cantidad << endl;
    cout << "Total a pagar: " << total << endl;
    cout << "-----------------------------------" << endl;
}
