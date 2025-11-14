#include "NodoPedido.h"

NodoPedido::NodoPedido(Pedido p)
    : pedido(p), siguiente(nullptr), anterior(nullptr)
{
}
