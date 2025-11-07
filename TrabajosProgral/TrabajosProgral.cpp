// HerenciaM.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream> 
#include <string>
#include "ListaDoble.h"
using namespace std;    
  
int main()
{

    ListaDoble lista;
    bool Continuar = true;
    string Respuesta = "Si";
    int dato = 0;

    // Carga inicial de datos
    while (Continuar)
    {
        cout << "Ingrese Dato" << endl;
        cin >> dato;
        lista.Insertar(dato);

        cout << "Desea continuar? Si/No" << endl;
        cin >> Respuesta;

        if (Respuesta == "No" || Respuesta == "no")
        {
            Continuar = false;
        }
        else
        {
            Continuar = true;
        }
    }

    cout << endl;
    cout << "Contenido de la lista:" << endl;
    lista.Mostrar();

    // Menu con switch
    int opcion = 0;
    bool seguirMenu = true;

    while (seguirMenu)
    {
        cout << endl;
        cout << "===== Menu Lista Doble =====" << endl;
        cout << "1) Insertar dato" << endl;
        cout << "2) Mostrar lista" << endl;
        cout << "3) Buscar valor" << endl;
        cout << "4) Buscar multiplos de un numero" << endl;
        cout << "5) Calcular promedio" << endl;
        cout << "6) Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese Dato" << endl;
            cin >> dato;
            lista.Insertar(dato);
            cout << "Dato insertado" << endl;
            break;

        case 2:
            cout << "Contenido de la lista:" << endl;
            lista.Mostrar();
            break;

        case 3:
        {
            int valor;
            cout << "Digite valor a buscar:" << endl;
            cin >> valor;
            lista.Buscar(valor);
            break;
        }

        case 4:
        {
            int numero;
            cout << "Digite el numero para buscar sus multiplos:" << endl;
            cin >> numero;
            if (numero == 0)
            {
                cout << "No se puede buscar multiplos de 0" << endl;
            }
            else
            {
                lista.BuscarMultiplos(numero);
            }
            break;
        }

        case 5:
        {
            double promedio = lista.Promedio();
            cout << "Promedio de los valores: " << promedio << endl;
            break;
        }

        case 6:
            seguirMenu = false;
            cout << "Saliendo del programa..." << endl;
            break;

        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    }

    return 0;
    /*
     int i;
     cout << "Digite valor a buscar:" << endl;
     cin >> i;
     //lista.Buscar(i);
     */

     /*int i = 10;
     int* x = &i;


     cout <<"valor:" << i << endl;
     cout << "Direccion:" << &i << endl;
     cout << "Valor de *x:" << x << endl;
     cout << "Valor en la direccion guardad *x:" << *x << endl;

     i = 20;

     cout << "valor:" << i << endl;
     cout << "Direccion:" << &i << endl;
     cout << "Valor de *x:" << x << endl;
     cout << "Valor en la direccion guardad *x:" << *x << endl;
     */


     //// Persona p("Pablo", "54545",45);
     //

     // string Respuesta = "Si";
     // 
     // bool Continuar = true;

     // 

     // while (Continuar)
     // {
     //     Estudiante estudiante;
     //     estudiante = estudiante.SolicitarDatos();

     //     Estudiante estudiantes[3];
     //     estudiantes[1] = estudiante;



     //     Profesor profe;
     //     Grupo grupo("TI",profe,estudiantes);
     //     grupo.Mostrar();

     //    // estudiante.Mostrar();
     //     cout << "Desea continuar? Si/No" << endl;
     //         cin >> Respuesta;

     //     if (Respuesta == "No" || Respuesta == "no" )
     //     {
     //         Continuar = false;
     //     }
     //     else
     //     {
     //         Continuar = true;
     //     }
     //     




     // }






}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
