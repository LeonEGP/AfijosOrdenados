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
void espacio() { //Complejidad Computacional: O(1).
    cout << endl;
}

//Creación de la Estructura "Sufijo", que consta de un entero índice y un string con el sufijo.
struct sufijo {
    int indice;
    string sufi;
};

//Función auxiliar para la comparación de dos strings, recibe dos strings, y retorna un valor entero. 
int comparacionStrings(string string1, string string2) { //Complejidad Computacional: O(n), donde n es el tamaño del primer string. 
    int i;
    int n;
    i = 0;
    n = string1.size();

    for (int i = n; i >= 0; i--){
        if (string1[i] != string2[i]) {
            return string1[i] - string2[i];
        }
        else {
            i++;
        }
    }

    return 0;
}

//Función que compara dos sufijos, recibe dos estructuras sufijo, y retorna un valor booleano. 
bool comparacionSufijos(sufijo sufijo1, sufijo sufijo2) { //Complejidad Computacional: O(k), donde K es la longitud máxima del sufijo (string) proporcionado.
    if (sufijo1.sufi < sufijo2.sufi) {
        return true;
    }
    else {
        return false;
    }
}

//Función que crea el Arreglo de Sufijos de una palabra dada (recibe un string), también toma como parámetro el Arreglo de Sufijos en el que se almacenará el resultado, no tiene valor de retorno.
void arregloDeSufijos(string palabra, sufijo arregloSufijos[]) { //Complejidad Computacional: O(n k log n). Donde n es el tamaño del string, y k es la longitud máxima de string en el arreglo dado.
    int n = palabra.size();
    sufijo sufijos[n];

    for (int i = 0; i < n; i++) {
        sufijos[i].indice = i;
        sufijos[i].sufi = palabra.substr(i);
    }

    sort(sufijos, sufijos + n, comparacionSufijos); //Complejidad de Algoritmo de Ordenamiento: O(n log n). Así mismo, la comparación de dos strings tiene una complejidad de O(k), donde K es la longitud máxima del sufijo (string) proporcionado.

    for (int j = 0; j < n; j++) {
        arregloSufijos[j].indice = sufijos[j].indice;
        arregloSufijos[j].sufi = sufijos[j].sufi;
    }
}

//Función que implementa una adaptación de la busqueda binaria sobre el Arreglo de Sufijos, recibe el string de búsqueda, el string palabra, recibe el Arreglo de Sufijos, el Arreglo de Búsqueda y un apuntador de entero índice. No tiene valor de retorno.
void buscar(string palabra, string busqueda, sufijo arregloSufijos[], int arregloBusqueda[], int* indice) { //Complejidad Computacional: O(m log n), siendo n el tamaño del string "palabra" y m el tamaño del string "busqueda".
    int longitudPalabra;
    int izquierda;
    int derecha;
    longitudPalabra = palabra.size();
    izquierda = 0;
    derecha = longitudPalabra - 1;

    while (izquierda <= derecha) {

        int medio = izquierda + (derecha - izquierda) / 2;
        string stringAuxiliar = palabra.substr(arregloSufijos[medio].indice);
        int resultado = comparacionStrings(busqueda, stringAuxiliar); //Complejidad O(m), siendo m el tamaño del string "busqueda". Por esta comparación, aumenta la complejidad base de O(log n) de una Búsqueda Binaria Normal.

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

//Función que imprime un Arreglo de Sufijos, recibe el arreglo y su tamaño n, no tiene valor de retorno.
void mostrarArreglo(sufijo arreglo[], int n) { //Complejidad Computacional: O(n), donde n es el tamaño del arreglo.
    for (int k = 0; k < n; k++) {
        cout << arreglo[k].indice << " " << arreglo[k].sufi << endl;
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

    //Creación e impresión del Arreglo de sufijos.
    sufijo arregloSufijos[palabra.size()];
    arregloDeSufijos(palabra, arregloSufijos);
    espacio();
    cout << "ARREGLO DE SUFIJOS GENERADO:" << endl;
    mostrarArreglo(arregloSufijos, palabra.length());

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