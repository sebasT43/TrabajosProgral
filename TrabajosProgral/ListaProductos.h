#pragma once
#include "NodoProductos.h"
#include <string>
using namespace std;

class ListaProductos
{
public:

    NodoProductos* head;
    NodoProductos* BuscarPorNombre(string nombre);

    ListaProductos();

    void Insertar(Productos p);
    void Mostrar();
    void Eliminar(string nombre);
    void menuProductos();
    void GuardarEnArchivo();
    void LeerArchivo();
};

