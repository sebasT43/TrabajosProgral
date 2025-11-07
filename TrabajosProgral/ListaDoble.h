#pragma once
#include "NodoDoble.h"
class ListaDoble
{
public:
	NodoDoble* head;
	ListaDoble();

	void Insertar(int valor);
	void Mostrar();
	void Eliminar(int valor);
	void Buscar(int valor);
	void BuscarMultiplos(int numero);
	double Promedio();	
};
// End of ListaDoble.h
// #pragma endregion