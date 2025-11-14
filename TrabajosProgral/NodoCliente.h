#pragma once
#include "Cliente.h"

class NodoCliente
{
public:
    Cliente cliente;
    NodoCliente* siguiente;
    NodoCliente* anterior;

    NodoCliente(Cliente c);
};
