#pragma once
#include "Pago.h"

class NodoPago
{
public:
    Pago pago;
    NodoPago* siguiente;
    NodoPago* anterior;

    NodoPago(Pago p);
};
