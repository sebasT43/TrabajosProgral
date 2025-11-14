#pragma once
#include "Pedido.h"

class NodoPedido
{
public:
    Pedido pedido;
    NodoPedido* siguiente;
    NodoPedido* anterior;

    NodoPedido(Pedido p);
};
