#pragma once
#include "Cliente.h"
#include "Productos.h"

class Pedido
{
public:
    Cliente cliente;
    Productos producto;
    int cantidad;
    float total;

    Pedido();
    Pedido(Cliente c, Productos p, int cant, float t);

    void mostrarPedido();
};
