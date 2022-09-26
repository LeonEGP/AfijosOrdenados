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
struct suffix {
    int index;
    string suff;
};

//Función auxiliar para la comparación de dos strings, recibe dos strings, un valor entero n y retorna un valor entero. 
int strCompare(string st1, string st2, int n) {
    int i = 0;
    while (n--) {
        if (st1[i] != st2[i])
            return st1[i] - st2[i];
        i++;
    }
    return 0;
}

//Funciónn que compara dos strings, recibe dos estructuras sufijo, y retorna un valor booleano. 
bool comp(suffix suff1, suffix suff2) {     //compare two strings for sorting
    if (suff1.suff < suff2.suff)
        return true;
    return false;
}

//Función que crea el Arreglo de Sufijos de una palabra dada, también tomo como parámetro el tamaño n de la misma y retorna el Arreglo de Sufijos.
void fillSuffixArray(string mainString, int suffArr[]) {
    int n = mainString.size();
    suffix allSuffix[n];    //array to hold all suffixes

    for (int i = 0; i < n; i++) {
        allSuffix[i].index = i;
        allSuffix[i].suff = mainString.substr(i);    //from ith position to end
    }

    sort(allSuffix, allSuffix + n, comp);
    for (int i = 0; i < n; i++)
        suffArr[i] = allSuffix[i].index;    //indexes of all sorted suffix
}

//Función que implementa la busqueda binaria sobre el Arreglo de Sufijos, recibe el arreglo de la búsqueda, el de la palábra, recibe el Arreglo de Sufijos y las longitudes de la palábra búsqueda, n y m (respectivamente).
void suffixArraySearch(string mainString, string pattern, int suffArr[], int array[], int* index) {
    int patLen = pattern.size();
    int strLen = mainString.size();
    int left = 0, right = strLen - 1;    //left and right for binary search

    while (left <= right) {
        int mid = left + (right - left) / 2;
        string tempStr = mainString.substr(suffArr[mid]);
        int result = strCompare(pattern, tempStr, patLen);

        if (result == 0) {    //the pattern is found
            (*index)++;
            array[(*index)] = suffArr[mid];
        }

        if (result < 0)
            right = mid - 1;
        else
            left = mid + 1;
    }
}

//Función que implementa la impresión de un Arreglo, recibe el arreglo y su tamaño m, no tiene valor de retorno.
void mostrarArreglo(int arreglo[], int n) {
    for (int k = 0; k < n; k++) {
        cout << arreglo[k] << " ";
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

    int locArray[palabra.size()];
    int index = -1;

    int suffArr[palabra.size()];
    fillSuffixArray(palabra, suffArr);

    espacio();
    cout << "ARREGLO DE SUFIJOS GENERADO:" << endl;
    mostrarArreglo(suffArr, palabra.length());

    espacio();
    suffixArraySearch(palabra, busqueda, suffArr, locArray, &index);

    if (index == -1){
        cout << "INDICE DE LA BUSQUEDA: " << endl;
        cout << "PATRON NO ENCONTRADO!!!" << endl;
        espacio();
    }
    else {
        for (int i = 0; i <= index; i++) {
            cout << "INDICE DE LA BUSQUEDA: " << endl << locArray[i] << endl;
        }
        espacio();
    }
  
    //Finaliza el programa.
    return 0;
}