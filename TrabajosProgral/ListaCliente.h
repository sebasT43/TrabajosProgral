#pragma once
#include "NodoCliente.h"

class ListaClientes
{
public:
    NodoCliente* head;
    

    ListaClientes();

    void Insertar(Cliente c);
    void Mostrar();
	void Eliminar(string cedula);
    NodoCliente* BuscarPorCedula(string cedula);
	void menuClientes();
    void GuardarEnArchivo();
    void LeerArchivo();

};
