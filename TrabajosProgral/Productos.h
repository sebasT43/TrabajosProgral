#pragma once
#include <string>	
using namespace std;

class Productos
{
	public:

		string nombre;
		float precio;
		int stock;

		Productos();
		Productos(float, string, int);
		void mostrarProducto();
		void introducirProducto();


};

