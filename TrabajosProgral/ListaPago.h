#pragma once
#include "NodoPago.h"
#include "ListaCliente.h"

class ListaPagos
{
public:
    NodoPago* head;

    ListaPagos();

    void Insertar(Pago p);
    void Mostrar();
    void crearPago(ListaClientes& listaC);
    void menuPagos(ListaClientes& listaC);
    void GuardarEnArchivo();
    void LeerArchivo();
};
