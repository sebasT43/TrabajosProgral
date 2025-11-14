#pragma once
#include "Productos.h"
class NodoProductos
{
public:
    Productos producto;
    NodoProductos* siguiente;
    NodoProductos* anterior;

    NodoProductos(Productos p);

};

