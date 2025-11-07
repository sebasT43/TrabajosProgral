#include "ListaDoble.h"
#include <iostream>
using namespace std;


ListaDoble::ListaDoble() : head(nullptr)
{
}


void ListaDoble::Insertar(int valor) {
	NodoDoble* nuevo = new NodoDoble(valor);
	if (head != nullptr)//LISTA CONTIENE ELEMENTOS
	{
		head->anterior = nuevo;
		nuevo->siguiente = head;
	}

	head = nuevo;

}

#pragma region Metodo Mostrar
void ListaDoble::Mostrar() {
	NodoDoble* actual = head;
	while (actual != nullptr)
	{
		cout << actual->dato << " ";
		cout << "Direc actual" << actual << " ";
		cout << "Direc anterior" << actual->anterior << " ";
		cout << "Direc siguiente" << actual->siguiente << " ";
		cout << endl;
		actual = actual->siguiente;
	}


}
#pragma endregion

void ListaDoble::Buscar(int valor)
{
	int posicion = 1;
	NodoDoble* actual = head;
	while (actual != nullptr)
	{
		if (actual->dato == valor)
		{
			cout << "EL dato se encuentra en el nodo:" << posicion << endl;
		}
		//cout << actual->dato << endl;
		actual = actual->siguiente;
		posicion++;
	}
	cout << "FINAL DE LA LISTA" << endl;
}

void ListaDoble::BuscarMultiplos(int numero)
{
	NodoDoble* actual = head;
	int posicion = 0;
	bool encontrado = false;
	while (actual != nullptr)
	{
		if (actual->dato % numero == 0)
		{
			cout << "El valor " << actual->dato << " en la posicion " << posicion << " es multiplo de " << numero << endl;
			encontrado = true;
		}
		actual = actual->siguiente;
		posicion++;
	}
	if (!encontrado)
	{
		cout << "No se encontraron multiplos de " << numero << " en la lista." << endl;
	}
}

double ListaDoble::Promedio()  
{
	if (head == nullptr) {
		cout << "La lista est� vac�a." << endl;
		return 0.0; // Retorna 0 si no hay elementos
	}

	NodoDoble* actual = head;
	int suma = 0;
	int contador = 0;

	while (actual != nullptr) {
		suma += actual->dato;
		contador++;
		actual = actual->siguiente;
	}

	double promedio = static_cast<double>(suma) / contador;
	return promedio;
}

/*
void ListaDoble::ContarPares()
{
    if (head == nullptr) {
        cout << "La lista esta vacia." << endl;
        return;
    }

    NodoDoble* actual = head;
    int posicion = 1;
    int contadorPares = 0;

    while (actual != nullptr) {
        if (actual->dato % 2 == 0) {
            cout << "Posicion " << posicion << " -> Valor: " << actual->dato << endl;
            contadorPares++;
        }
        actual = actual->siguiente;
        posicion++;
    }

    if (contadorPares == 0) {
        cout << "No se encontraron numeros pares en la lista." << endl;
    } else {
        cout << "Total de numeros pares encontrados: " << contadorPares << endl;
    }
}
*/

/*void ListaDoble::MayorYMenor()
{
    if (head == nullptr) {
        cout << "La lista esta vacia. No se puede calcular mayor y menor." << endl;
        return;
    }

    NodoDoble* actual = head;
    int mayor = actual->dato;
    int menor = actual->dato;
    actual = actual->siguiente;

    while (actual != nullptr) {
        if (actual->dato > mayor) mayor = actual->dato;
        if (actual->dato < menor) menor = actual->dato;
        actual = actual->siguiente;
    }

    cout << "Valor mayor: " << mayor << endl;
    cout << "Valor menor: " << menor << endl;
}