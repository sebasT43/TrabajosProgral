#include "NodoCliente.h"

NodoCliente::NodoCliente(Cliente c)
    : cliente(c), siguiente(nullptr), anterior(nullptr)
{
}
