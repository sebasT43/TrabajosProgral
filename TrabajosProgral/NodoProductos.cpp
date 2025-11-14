#include "NodoProductos.h"

NodoProductos::NodoProductos(Productos p)
    : producto(p), siguiente(nullptr), anterior(nullptr)
{
}