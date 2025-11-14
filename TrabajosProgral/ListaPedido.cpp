#include "ListaPedido.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ListaPedidos::ListaPedidos()
{
    head = nullptr;
}

void ListaPedidos::Insertar(Pedido p)
{
    NodoPedido* nuevo = new NodoPedido(p);

    if (head != nullptr)
    {
        head->anterior = nuevo;
        nuevo->siguiente = head;
    }

    head = nuevo;
}

void ListaPedidos::Mostrar()
{
    NodoPedido* actual = head;

    if (actual == nullptr)
    {
        cout << "No hay pedidos registrados." << endl;
        return;
    }

    while (actual != nullptr)
    {
        actual->pedido.mostrarPedido();
        actual = actual->siguiente;
    }
}

void ListaPedidos::crearPedido(ListaClientes& listaC, ListaProductos& listaP)
{
    string cedula;
    cout << "Ingrese la cedula del cliente: ";
    cin >> cedula;

    NodoCliente* nCliente = listaC.BuscarPorCedula(cedula);

    if (nCliente == nullptr)
    {
        cout << "Cliente NO encontrado." << endl;
        system("pause");
        return;
    }

    int continuar = 1;

    while (continuar == 1)
    {
        string nombreProducto;
        int cantidad;

        cout << "Ingrese el nombre del producto: ";
        cin >> nombreProducto;

        NodoProductos* nProducto = listaP.BuscarPorNombre(nombreProducto);

        if (nProducto == nullptr)
        {
            cout << "Producto NO encontrado." << endl;
            system("pause");
            return;
        }

        cout << "Ingrese la cantidad: ";
        cin >> cantidad;

        float total = nProducto->producto.precio * cantidad;

        Pedido nuevoPedido(
            nCliente->cliente,
            nProducto->producto,
            cantidad,
            total
        );

        Insertar(nuevoPedido);

        cout << "\nPedido creado exitosamente.\n";

        cout << "\nDesea crear otro pedido PARA EL MISMO CLIENTE?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout << "Opcion: ";
        cin >> continuar;

		system("cls");
    }

    system("pause");
}


void ListaPedidos::menuPedidos(ListaClientes& listaC, ListaProductos& listaP)
{
    int opcion = 0;

    do
    {
        system("cls");
        cout << "===== MENU PEDIDOS =====" << endl;
        cout << "1. Crear pedido" << endl;
        cout << "2. Mostrar pedidos" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        system("cls");

        switch (opcion)
        {
        case 1:
            crearPedido(listaC, listaP);
            break;

        case 2:
            Mostrar();
            system("pause");
            break;

        case 3:
            cout << "Saliendo del menu de pedidos..." << endl;
            system("pause");
            break;

        default:
            cout << "Opcion no valida." << endl;
            system("pause");
        }

    } while (opcion != 3);
}

void ListaPedidos::GuardarEnArchivo()
{
    ofstream archivo("pedidos.txt");
    if (!archivo)
    {
        cout << "No se pudo crear el archivo de pedidos" << endl;
        return;
    }

    archivo << "Lista de Pedidos" << endl;

    NodoPedido* actual = head;
    while (actual != nullptr)
    {
        archivo << "Cliente: " << actual->pedido.cliente.nombre
            << " | Cedula: " << actual->pedido.cliente.cedula
            << " | Producto: " << actual->pedido.producto.nombre
            << " | Precio unitario: " << actual->pedido.producto.precio
            << " | Cantidad: " << actual->pedido.cantidad
            << " | Total: " << actual->pedido.total
            << endl;

        actual = actual->siguiente;
    }

    archivo.close();
}

void ListaPedidos::LeerArchivo()
{
    ifstream archivo("pedidos.txt");
    if (!archivo)
    {
        cout << "No se pudo abrir el archivo de pedidos" << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea))
    {
        cout << linea << endl;
    }

    archivo.close();
}
