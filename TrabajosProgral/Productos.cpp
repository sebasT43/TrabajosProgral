#include "Productos.h"
#include <iostream>		

using namespace std;	

Productos::Productos() {
	precio = 0;
	nombre = "";
	stock = 0;
}

Productos::Productos(float p, string n, int s) {
	precio = p;
	nombre = n;
	stock = s;
}

void Productos::mostrarProducto() {
	cout << "Nombre del producto: " << nombre << endl;
	cout << "Precio del producto: " << precio << endl;
	cout << "Stock del producto: " << stock << endl;
}

void Productos::introducirProducto() {
	cout << "Ingrese el nombre del producto: ";
	cin >> nombre;
	cout << "Ingrese el precio del producto: ";
	cin >> precio;
	cout << "Ingrese el stock del producto: ";
	cin >> stock;
}