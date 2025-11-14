// HerenciaM.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
 
#include <iostream>
#include <string>
#include "ListaProductos.h"
#include "ListaCliente.h"
#include "ListaPedido.h"
#include "ListaPago.h"
using namespace std;
  
int main()
{
	int opcion = 0;
    ListaProductos listaP;
	ListaClientes listaC;
    ListaPedidos listaPe;
	ListaPagos listaPa;
    do
    {
        system("cls");
        cout << "===== MENU PRINCIPAL =====" << endl;
        cout << "1. Productos" << endl;
        cout << "2. Clientes" << endl;
        cout << "3. Pedidos" << endl;
        cout << "4. Pagos" << endl;
        cout << "5. Guardar todo en archivos" << endl;
        cout << "6. Leer todo en archivos" << endl;
        cout << "7. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        system("cls");

        switch (opcion)
        {
        case 1:
            listaP.menuProductos();
            break;

        case 2:
            listaC.menuClientes();
            break;

        case 3:
            listaPe.menuPedidos(listaC, listaP);
            break;

        case 4:
            listaPa.menuPagos(listaC);
            break;

        case 5:
            listaP.GuardarEnArchivo();
            listaC.GuardarEnArchivo();
            listaPe.GuardarEnArchivo();
            listaPa.GuardarEnArchivo();
            cout << "Datos guardados en archivos." << endl;
            system("pause");
            break;
        
        case 6:
            cout << "------ Productos ------" << endl;
            listaP.LeerArchivo();
            cout << "\n------ Clientes ------" << endl;
            listaC.LeerArchivo();
            cout << "\n------ Pedidos ------" << endl;
            listaPe.LeerArchivo();
            cout << "\n------ Pagos ------" << endl;
            listaPa.LeerArchivo();
            system("pause");
            break;

        case 7:
            cout << "Saliendo del sistema..." << endl;
            system("pause");
            break;

        default:
            cout << "Opcion no valida." << endl;
            system("pause");
        }

    } while (opcion != 7);

    return 0;


}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
