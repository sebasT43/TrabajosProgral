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
		//cout << "Direc actual" << actual << " ";
		//cout << "Direc anterior" << actual->anterior << " ";
		//cout << "Direc siguiente" << actual->siguiente << " ";
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

void ListaDoble::numeroMayor()
{
	if (head == nullptr)
	{
		cout << "La lista esta vacia" << endl;
		return;
	}
	NodoDoble* actual = head;
	int mayor = actual->dato;
	int posicion = 1;
	int posicion01 = 1;

	while (actual != nullptr)
	{
		if (actual->dato > mayor)
		{
			mayor = actual->dato;
			posicion = posicion01;
		}
		actual = actual->siguiente;
		posicion01++;
	}
	cout << "El numero mayor es: " << mayor << " y esta en la posicion " << posicion << endl;
}


void ListaDoble::numeroMenor()
{
	if (head == nullptr)
	{
		cout << "La lista esta vacia" << endl;
		return;
	}
	NodoDoble* actual = head;
	int menor = actual->dato;
	int posicion = 1;
	int posicion01 = 1;

	while (actual != nullptr)
	{
		if (actual->dato < menor)
		{
			menor = actual->dato;
			posicion = posicion01;
		}
		actual = actual->siguiente;
		posicion01++;
	}
	cout << "El numero menor es: " << menor << " y esta en la posicion " << posicion << endl;
}

void ListaDoble::numeParImpar()
{
	if (head == nullptr)
	{
		cout << "La lista esta vacia" << endl;
		return;
	}

	NodoDoble* actual = head;
	int numeroPar = 0;
	int numeroImpar = 0;
	int posicion = 1;

	while (actual != nullptr)
	{
		if (actual->dato % 2 == 0)
		{
			cout << "El numero " << actual->dato << " en la posicion " << posicion << " par" << endl;
		}
		else
		{
			
			cout << "El numero " << actual->dato << " en la posicion " << posicion << " impar" << endl;

			
		}
		actual = actual->siguiente;
		posicion++;
	}

}
