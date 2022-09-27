//Programa que: Implementa Algoritmos sobre Arreglos de Sufijos.
//Programadores: León Emiliano García Pérez [A00573074] y Carla Morales López [A01639225].
//Fecha de entrega: Martes 27 de Septiembre de 2022.

//Inclusión de librerías.
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>

//Ajuste a estandar.
using namespace std;

//Función que imprime un espacio en consola, no recibe valores, no tiene valor de retorno.
void espacio() { //Complejidad Computacional: O(1).
	cout << endl;
}

//Creación de la Estructura "Sufijo", que consta de un entero índice y un apuntador caractéres.
struct sufijo {
	int indice;
	char* sufijo;
};

//Función que compara dos sufijos, recibe dos estructuras sufijo y retorna un valor entero. 
int comparacion(sufijo a, sufijo b) { //Complejidad Computacional: O(k), donde K es la longitud máxima de string proporcionado.
	if ((strcmp(a.sufijo, b.sufijo)) < 0) {
		return 1;
	}
	else {
		return 0;
	}
}


//Función que crea el Arreglo de Sufijos de una palabra dada en forma de un arreglo de caractéres, también toma como parámetro el tamaño n de la palabra y retorna el Arreglo de Sufijos.
sufijo* arregloDeSufijos(char* palabra, int n) { //Complejidad Computacional: O(n k log n). Donde n es la cantidad de elementos del arreglo, y k es la longitud máxima de string en el arreglo dado.
	sufijo sufijos[n];

	for (int i = 0; i < n; i++) {
		sufijos[i].indice = i;
		sufijos[i].sufijo = (palabra + i);
	}

	sort(sufijos, sufijos + n, comparacion); //Complejidad de Algoritmo de Ordenamiento: O(n log n). Así mismo, la comparación de dos strings tiene una complejidad de O(k), donde k es la longitud máxima de un string en cierto arreglo.

	sufijo* arregloSufijos = new sufijo[n];

	for (int j = 0; j < n; j++) {
		arregloSufijos[j].indice = sufijos[j].indice;
		arregloSufijos[j].sufijo = sufijos[j].sufijo;
	}

	return  arregloSufijos;
}

//Función que implementa una adaptación de la busqueda binaria sobre el Arreglo de Sufijos, recibe el arreglo de la búsqueda, el arreglo de la palabra, recibe el Arreglo de Sufijos y las longitudes de la palabra y de la búsqueda, n y m (respectivamente). No tiene valor de retorno.
void buscar(char* busqueda, char* palabra, sufijo* arregloSufijos, int n, int m) { //Complejidad Computacional: O(m log n), siendo n la cantidad de elementos del arreglo "palabra" y m la cantidad de elementos del arreglo "busqueda".
	int izquierda;
	int derecha;
	izquierda = 0,
	derecha = n - 1;

	while (izquierda <= derecha) {

		int medio;
		int resultado;
		medio = izquierda + (derecha - izquierda) / 2;
		resultado = strncmp(busqueda, palabra + arregloSufijos[medio].indice, m);

		if (resultado == 0) {
			cout << arregloSufijos[medio].indice << endl;
			return;
		}

		if (resultado < 0) {
			derecha = medio - 1;
		}
		else {
			izquierda = medio + 1;
		}
	}
	cout << "PATRON NO ENCONTRADO!!!" << endl;
}

//Función que imprime un Arreglo de Sufijos, recibe el arreglo y su tamaño n, no tiene valor de retorno.
void mostrarArreglo(sufijo arreglo[], int n) { //Complejidad Computacional: O(n), donde n es el tamaño del arreglo.
	for (int k = 0; k < n; k++) {
		cout << arreglo[k].indice << " " << arreglo[k].sufijo << endl;
	}
	espacio();
}

//Función main de ejecución del programa, no recibe valores, retorna un valor 0 al finalizar la ejecución.
int main() { //Complejidad Computacional O(1).

	//Inicia el programa.
	espacio();

	//Declaración de variables.
	string palabra;
	string busqueda;

	//Toma de datos del usuario.
	cout << "INGRESA LA PALABRA BASE: " << endl;
	cin >> palabra;
	espacio();
	cout << "INGRESA EL PATRON A BUSCAR: " << endl;
	cin >> busqueda;

	//Creación de los arreglos de characters.
	int n = palabra.length();
	int m = busqueda.length();
	char plb[n + 1];
	char bsq[m + 1];
	strcpy(plb, palabra.c_str());
	strcpy(bsq, busqueda.c_str());
	espacio();

	//Creación e impresión del Arreglo de sufijos.
	sufijo* arregloSufijos = arregloDeSufijos(plb, n);
	cout << "ARREGLO DE SUFIJOS GENERADO:" << endl;
	mostrarArreglo(arregloSufijos, n);

	//Muestra del Índice del Patrón buscado.
	cout << "INDICE DE LA BUSQUEDA:" << endl;
	buscar(bsq, plb, arregloSufijos, n, m);
	espacio();

	//Finaliza el programa.
	return 0;
}