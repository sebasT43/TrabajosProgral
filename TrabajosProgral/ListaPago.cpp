#include "ListaPago.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ListaPagos::ListaPagos()
{
    head = nullptr;
}

void ListaPagos::Insertar(Pago p)
{
    NodoPago* nuevo = new NodoPago(p);

    if (head != nullptr)
    {
        head->anterior = nuevo;
        nuevo->siguiente = head;
    }

    head = nuevo;
}

void ListaPagos::Mostrar()
{
    NodoPago* actual = head;

    if (actual == nullptr)
    {
        cout << "No hay pagos registrados." << endl;
        return;
    }

    while (actual != nullptr)
    {
        actual->pago.mostrarPago();
        actual = actual->siguiente;
    }
}

void ListaPagos::crearPago(ListaClientes& listaC)
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
        float monto;
        string metodo;

        cout << "Ingrese el monto a pagar: ";
        cin >> monto;

        cout << "Ingrese el metodo de pago (ej: efectivo, tarjeta, SINPE): ";
        cin >> metodo;

        Pago nuevoPago(nCliente->cliente, monto, metodo);

        Insertar(nuevoPago);

        cout << "\nPago registrado exitosamente.\n";

        cout << "\nDesea registrar OTRO pago para este mismo cliente?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout << "Opcion: ";
        cin >> continuar;
    }

    system("pause");
}

void ListaPagos::menuPagos(ListaClientes& listaC)
{
    int opcion = 0;
    do
    {
        system("cls");
        std::cout << "=== MENU PAGOS ===" << std::endl;
        std::cout << "1. Crear pago" << std::endl;
        std::cout << "2. Mostrar pagos" << std::endl;
        std::cout << "3. Volver" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            crearPago(listaC);
            break;
        case 2:
            Mostrar();
            system("pause");
            break;
        case 3:
            break;
        default:
            std::cout << "Opcion no valida." << std::endl;
            system("pause");
            break;
        }

    } while (opcion != 3);
}

void ListaPagos::GuardarEnArchivo()
{
    ofstream archivo("pagos.txt");
    if (!archivo)
    {
        cout << "No se pudo crear el archivo de pagos" << endl;
        return;
    }

    archivo << "Lista de Pagos" << endl;

    NodoPago* actual = head;
    while (actual != nullptr)
    {
        archivo << "Cliente: " << actual->pago.cliente.nombre
            << " | Cedula: " << actual->pago.cliente.cedula
            << " | Monto: " << actual->pago.monto
            << " | Metodo: " << actual->pago.metodo
            << endl;

        actual = actual->siguiente;
    }

    archivo.close();
}


void ListaPagos::LeerArchivo()
{
    ifstream archivo("pagos.txt");
    if (!archivo)
    {
        cout << "No se pudo abrir el archivo de pagos" << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea))
    {
        cout << linea << endl;
    }

    archivo.close();
}
