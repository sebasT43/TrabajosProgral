#include "ListaProductos.h"
#include <iostream>
#include <fstream>
using namespace std;

ListaProductos::ListaProductos()
    : head(nullptr)
{
}

void ListaProductos::Insertar(Productos p)
{
    NodoProductos* nuevo = new NodoProductos(p);

    if (head != nullptr)
    {
        head->anterior = nuevo;
        nuevo->siguiente = head;
    }

    head = nuevo;
}

void ListaProductos::Mostrar()
{
    NodoProductos* actual = head;

    if (actual == nullptr) {
        cout << "No hay productos en la lista." << endl;
        return;
    }

    while (actual != nullptr)
    {
        actual->producto.mostrarProducto();
        cout << "------------------------" << endl;
        actual = actual->siguiente;
    }
}

void ListaProductos::Eliminar(string nombre)
{
    NodoProductos* actual = head;
    while (actual != nullptr)
    {
        if (actual->producto.nombre == nombre)
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
            cout << "Producto eliminado: " << nombre << endl;
            return;
        }
        actual = actual->siguiente;
    }
    cout << "Producto no encontrado: " << nombre << endl;
}

void ListaProductos::menuProductos()
{
    int opcion = 0;

    do
    {
        system("cls");

        cout << "\n===== MENU PRODUCTOS =====" << endl;
        cout << "1. Ingresar producto" << endl;
        cout << "2. Mostrar productos" << endl;
        cout << "3. Eliminar producto" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        system("cls");

        switch (opcion)
        {
        case 1:
        {
            Productos p;
            p.introducirProducto();
            Insertar(p);
            break;
        }

        case 2:
            Mostrar();
            system("pause");
            break;

        case 3:
        {
            string nombre;
            cout << "Ingrese el nombre del producto a eliminar: ";
            cin >> nombre;
            Eliminar(nombre);
            break;
        }

        case 4:
            cout << "Saliendo del menu de productos..." << endl;
            break;

        default:
            cout << "Opcion no valida." << endl;
        }

    } while (opcion != 4);

    system("pause");
}

NodoProductos* ListaProductos::BuscarPorNombre(string nombre)
{
    NodoProductos* actual = head;

    while (actual != nullptr)
    {
        if (actual->producto.nombre == nombre)
        {
            return actual;  
        }
        actual = actual->siguiente;
    }

    return nullptr; 
}

void ListaProductos::GuardarEnArchivo()
{
    ofstream archivo("productos.txt");
    if (!archivo)
    {
        cout << "No se pudo crear el archivo de productos" << endl;
        return;
    }

    archivo << "Lista de Productos" << endl;

    NodoProductos* actual = head;
    while (actual != nullptr)
    {
        archivo << "Nombre: " << actual->producto.nombre
            << " | Precio: " << actual->producto.precio
            << " | Stock: " << actual->producto.stock
            << endl;

        actual = actual->siguiente;
    }

    archivo.close();
}

void ListaProductos::LeerArchivo()
{
    ifstream archivo("productos.txt");
    if (!archivo)
    {
        cout << "No se pudo abrir el archivo de productos" << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea))
    {
        cout << linea << endl;
    }

    archivo.close();
}
