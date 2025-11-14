#pragma once
#include "NodoPedido.h"
#include "ListaCliente.h"
#include "ListaProductos.h"

class ListaPedidos
{
public:
    NodoPedido* head;

    ListaPedidos();

    void Insertar(Pedido p);
    void Mostrar();
    void crearPedido(ListaClientes& listaC, ListaProductos& listaP);
    void menuPedidos(ListaClientes& listaC, ListaProductos& listaP);
    void GuardarEnArchivo();
    void LeerArchivo();
};
