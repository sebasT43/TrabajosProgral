#include "ListaCliente.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ListaClientes::ListaClientes()
{
    head = nullptr;
}

void ListaClientes::Insertar(Cliente c)
{
    NodoCliente* nuevo = new NodoCliente(c);

    if (head != nullptr)
    {
        head->anterior = nuevo;
        nuevo->siguiente = head;
    }

    head = nuevo;
}

void ListaClientes::Mostrar()
{
    NodoCliente* actual = head;

    if (actual == nullptr)
    {
        cout << "No hay clientes en la lista." << endl;
        return;
    }

    while (actual != nullptr)
    {
        actual->cliente.mostrarCliente();
        cout << "------------------------" << endl;
        actual = actual->siguiente;
    }
}

void ListaClientes::Eliminar(string cedula)
{
    NodoCliente* actual = head;

    while (actual != nullptr)
    {
        if (actual->cliente.cedula == cedula)
        {
            if (actual->anterior != nullptr)
            {
                actual->anterior->siguiente = actual->siguiente;
            }
            else
            {
                head = actual->siguiente;
            }

            if (actual->siguiente != nullptr)
            {
                actual->siguiente->anterior = actual->anterior;
            }

            delete actual;
            cout << "Cliente eliminado: " << cedula << endl;
            return;
        }
        actual = actual->siguiente;
    }

    cout << "Cliente no encontrado: " << cedula << endl;
}

void ListaClientes::menuClientes()
{
    int opcion = 0;

    do
    {
        system("cls");

        cout << "\n===== MENU CLIENTES =====" << endl;
        cout << "1. Ingresar cliente" << endl;
        cout << "2. Mostrar clientes" << endl;
        cout << "3. Eliminar cliente" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        system("cls");

        switch (opcion)
        {
        case 1:
        {
            Cliente c;
            c.introducirCliente();
            Insertar(c);
            break;
        }

        case 2:
            Mostrar();
            system("pause");
            break;

        case 3:
        {
            string cedula;
            cout << "Ingrese la cedula del cliente a eliminar: ";
            cin >> cedula;
            Eliminar(cedula);
            system("pause");
            break;
        }

        case 4:
            cout << "Saliendo del menu de clientes..." << endl;
            break;

        default:
            cout << "Opcion no valida." << endl;
            system("pause");
        }

    } while (opcion != 4);

    system("pause");
}

NodoCliente* ListaClientes::BuscarPorCedula(string cedula)
{
    NodoCliente* actual = head;
    while (actual != nullptr)
    {
        if (actual->cliente.cedula == cedula)
        {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void ListaClientes::GuardarEnArchivo()
{
    ofstream archivo("clientes.txt");
    if (!archivo)
    {
        cout << "No se pudo crear el archivo de clientes" << endl;
        return;
    }

    archivo << "Lista de Clientes" << endl;

    NodoCliente* actual = head;
    while (actual != nullptr)
    {
        archivo << "Nombre: " << actual->cliente.nombre
            << " | Cedula: " << actual->cliente.cedula
            << endl;

        actual = actual->siguiente;
    }

    archivo.close();
}

void ListaClientes::LeerArchivo()
{
    ifstream archivo("clientes.txt");
    if (!archivo)
    {
        cout << "No se pudo abrir el archivo de clientes" << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea))
    {
        cout << linea << endl;
    }

    archivo.close();
}