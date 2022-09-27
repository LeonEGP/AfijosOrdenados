//Programa que: Implementa Algoritmos sobre Arreglos de Sufijos.
//Programadores: León Emiliano García Pérez [A00573074] y Carla Morales López [A01639225].
//Fecha de entrega: Martes 27 de Septiembre de 2022.

//Inclusión de librerías.
#include<iostream>
#include<string>
#include<algorithm>

//Ajuste a estandar.
using namespace std;

//Función que imprime un espacio en consola, no recibe valores, no tiene valor de retorno.
void espacio() {
    cout << endl;
}

//Creación de la Estructura "Sufijo".
struct sufijo {
    int indice;
    string sufi;
};

//Función auxiliar para la comparación de dos strings, recibe dos strings, un valor entero n y retorna un valor entero. 
int comparacionStrings(string string1, string string2, int n) {
    int i = 0;
    while (n--) {
        if (string1[i] != string2[i]) {
            return string1[i] - string2[i];
        }
        else {
            i++;
        }
    }
    return 0;
}

//Función que compara dos strings, recibe dos estructuras sufijo, y retorna un valor booleano. 
bool comparacionSufijos(sufijo sufijo1, sufijo sufijo2) {
    if (sufijo1.sufi < sufijo2.sufi) {
        return true;
    }
    else {
        return false;
    }
}

//Función que crea el Arreglo de Sufijos de una palabra dada, también tomo como parámetro el tamaño n de la misma y retorna el Arreglo de Sufijos.
void arregloDeSufijos(string palabra, sufijo arregloSufijos[]) {
    int n = palabra.size();
    sufijo sufijos[n];

    for (int i = 0; i < n; i++) {
        sufijos[i].indice = i;
        sufijos[i].sufi = palabra.substr(i);
    }

    sort(sufijos, sufijos + n, comparacionSufijos);

    for (int j = 0; j < n; j++) {
        arregloSufijos[j].indice= sufijos[j].indice;
        arregloSufijos[j].sufi = sufijos[j].sufi;
    }
}

//Función que implementa la busqueda binaria sobre el Arreglo de Sufijos, recibe el arreglo de la búsqueda, el de la palábra, recibe el Arreglo de Sufijos y las longitudes de la palábra búsqueda, n y m (respectivamente).
void buscar(string palabra, string busqueda, sufijo arregloSufijos[], int arregloBusqueda[], int* indice) {
    int longitudBusqueda;
    int longitudPalabra;
    int izquierda;
    int derecha;
    longitudBusqueda = busqueda.size();
    longitudPalabra = palabra.size();
    izquierda = 0;
    derecha = longitudPalabra - 1;

    while (izquierda <= derecha) {

        int medio = izquierda + (derecha - izquierda) / 2;
        string stringAuxiliar = palabra.substr(arregloSufijos[medio].indice);
        int resultado = comparacionStrings(busqueda, stringAuxiliar, longitudBusqueda);

        if (resultado == 0) {
            (*indice)++;
            arregloBusqueda[(*indice)] = arregloSufijos[medio].indice;
        }

        if (resultado < 0) {
            derecha = medio - 1;
        }
        else {
            izquierda = medio + 1;
        }
    }
}

//Función que implementa la impresión de un Arreglo, recibe el arreglo y su tamaño m, no tiene valor de retorno.
void mostrarArreglo(sufijo arreglo[], int n) {
    for (int k = 0; k < n; k++) {
        cout << arreglo[k].indice << " " << arreglo[k].sufi << endl;
    }
    espacio();
}

//Función main de ejecución del programa, no recibe valores, retorna un valor 0 al finalizar la ejecución.
int main() {

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

    //Creación e impresión del Arreglo de sufijos.
    sufijo arregloSufijos[palabra.size()];
    arregloDeSufijos(palabra, arregloSufijos);
    espacio();
    cout << "ARREGLO DE SUFIJOS GENERADO:" << endl;
    mostrarArreglo(arregloSufijos, palabra.length());
    espacio();

    //Muestra del Índice del Patrón buscado.

    int arregloBusqueda[palabra.size()];
    int index = -1;
    buscar(palabra, busqueda, arregloSufijos, arregloBusqueda, &index);

    if (index == -1) {
        cout << "INDICE DE LA BUSQUEDA: " << endl;
        cout << "PATRON NO ENCONTRADO!!!" << endl;
        espacio();
    }
    else {
        for (int i = 0; i <= index; i++) {
            cout << "INDICE DE LA BUSQUEDA: " << endl << arregloBusqueda[i] << endl;
        }
        espacio();
    }

    //Finaliza el programa.
    return 0;
}
