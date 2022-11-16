#include<iostream>
#include <vector>
using namespace std;
//Francisco Jervis A00835131 

//Algoritmos de busqueda****************

/*Busqueda secuencial recursiva
* 
* Este algoritmo de busqueda funciona al comparar cada elemento del vector con el valor el cual se desea encontrar
* Las entradas del algoritmo son: un vector (list), el valor a encontrar (target) y el valor inicial del indice de busca (guess)
* En caso de encontrar el valor, el algoritmo devuelve el indice en el cual se encuentra el valor de la busqeda. de lo contarrio devulve 0
* El algoritmo funciona en 3 partes a través de un metodo recursivo
* Su complejidad en el tiempo es de O(n) 
*/
int busqSecuencial(vector<int> list, int target, int guess) {
	if (guess >= list.size())//1. El algoritmo compara que el indice a buscar no este afuera del rango del vector
		return -1;//, en caso de ser asi, sigifica que el valor no se encuentra en vector y devuelve -1. Si el indice está adentro del rango del vector continua al paso 2

	if (list[guess] == target)//2. El algoritmo compara lo que se encuentra en el indice con el valor de busqueda
		return guess;//Si el valor que se encuentra en el indice es igual al valor de busqeda, devuelve el indice, de lo contario continua al paso 3
	else
		return busqSecuencial(list, target, guess + 1);//3. Se vuelve a llamar la funcion pero con el valor del indice de busqueda incrementado en 1 y se repite el paso 1
}

/*Busqueda secuencial recursiva
* *Este algoritmo debe recibir un vector ordenado para funcionar*
* El algoritmo de busqueda secuencial compara el elemnto que se encuentra en la mitad del y descarta la mitad de los elementos varias veces hasta encontrar el valor de busqueda
* La entradas del algoritmo son un vector (list), el valor a encontrar (target), el indice del inicio del vector y el indice del final del vector
* La salida del algoritmo es -1 si no se encontro el valor target o el indice en donde se encutra el target
* Este algoritmo funciona con un metodo recursivo el cual crea sub algoritmos descartando mitades de el vector donde no se encuntra el target
* Su complejidad en el tiempo es de O(nlogn)
*/
int busqBinaria(vector<int> list, int target, int start, int end) {
	int mid = (start + end) / 2 - 1; //se encuentra el valor del indice medio del vector
	if (mid >= 0) {
		if (list[mid] == target)//si el valor que se enccuentra en el indice medio es igual al target se devuelve el valor del indice medio
			return mid;
		else if (list[mid] < target)//si el valor que se encuentra en el indice medio es menor al target
			return busqBinaria(list, target, mid+1, end);//se descarta todos los valores con unindice menor al medio llamando la funcion otra vez peero con el valor medio como su valor de inicio
		else
			return busqBinaria(list, target, start, mid-1);//de lo contrario se llama la funcion con el valor del final igual al valor del medio, asi decartando todos los valores con indice moyor al medio
	}
	else
		return -1;
}
//Algoritmos de ordenamiento **********


/*Insertion Sort
* Este algoritmo ordena el vector a traves de un metodo de comparación de cada elemnto y si el elemento i-1 es mayor a i los cambia de lugar
* La entrada del algoritmo es un vector pasado por refrencia, es decir la dirección donde se encuentra el algoritmo en vez de sus valores
* El algoritmo no tiene una salida
* Su complejidad es de O(n^2)
*/
void ordenaInsertion(vector<int>& list) {
	int x;//variable que funcionará como el segundo iterador
	for (int i = 1; i < list.size(); i++) {//for loop la cual pasa por todo el vector
		int temp = list[i];//se crea una variable temporal con el valor del elemento encontrado en el indice i
		for (x = i; x > 0 && list[x - 1] > temp; x--)// loop anidada la cual compara todos los elementos con un indice menor a i y en caso de encontrar un valor mayor al elemento en  i los cambia de lugar
			list[x] = list[x - 1];
		list[x] = temp;
	}
}

/*Bubble sort
* Algoritmo de ordenamiento el cual funciona iterando por todos los elementos del elemento y los cambia de lugar mientras i+1 sea menor a i, despues de esto vuelve a itererar el vector hasta que logre iterar el vector sin hacer ningún cambio
* La entrada del algoritmo es un vector pasado por referencia
* No tiene una salida
* Su complejidad es de O(n^2)
*/
void ordenaBurbuja(vector<int>& list) {
	int noswaps = 0, //Variable para contar la cantidad de veces que no se hiceron cambios durante el loop
		size = list.size();
	while (noswaps < size) {//Condición para saber si el algoritmo ha hecho una iteración por todo el vector sin hacer un cambio lo que significaría que el vactor está ordenado
		for (int i = 0; i < size; i++) {//iteración por todo el vector 
			noswaps++;
			for (int x = i + 1; size > x && list[i] > list[x]; x++) {//loop el cual empieza en i e itera a traves del vector hasta encontrar un elemento mayor al elemento encontrado en i, cuando lo encuentra lo cambia de lugar
				int temp = list[i];
				list[i] = list[x];
				list[x] = temp;
				noswaps = 0;//al hacer un cambio se iguala a cero la variable noswaps 
			}
		}
	}
}

//Funcion Merge para unir los sub vectores ordenados
void Merge(vector<int>& list, int start, int mid, int end) {
	vector<int> temp;
	int i = start,
		x = mid + 1;
	while (i <= mid && x <= end) {
		if (list[i] <= list[x]) {
			
			temp.push_back(list[i]);
			i++;
		}
		else {
			temp.push_back(list[x]);
			x++;
		}
	}
	while (i <= mid) {
		temp.push_back(list[i]);
		i++;
	}
	while (x <= end) {
		temp.push_back(list[x]);
		x++;
	}
	for (int i = start; i <= end; ++i)
		list[i] = temp[i - start];
}
/*Merge sort
* Algoritmo de ordenamiento el cual funciona por un metodo recursivo, El funcionamiento se basa en descomponer el vector en subvectores mas pequeños, despues de esto el algoritmo compara cada uno de estos subvectores singulares y los va combinado a subvectores mas grandes ya ordenados
* Las entradas del algoritmo son: un vector pasado por referencia, el primer indice del vector y el ultimo indice del vector
* No tiene una salida
* Su complejidad es de O(nlog(n))
*/
void ordenaMerge(vector<int>& list, int start, int end) {
	if (start < end) {//condicion para verificar que se mantega dentro del tamaño del vector
		int mid = (start + end) / 2;//variable para encontrar el punto de divición del vector pur el cual se realizara una divición a dos sub vectores
		ordenaMerge(list, start, mid);//Sub vector izquierdo
		ordenaMerge(list, mid + 1, end);//Sub vector izquierdo
		Merge(list, start, mid, end);//Función la cual combina todos los sub vectores en un nuevo vector ya ordenado
	}
}
//Funciones auxiliares
void print(vector<int> list) {//Función la cual itera todo el vector imprimiendo sus elemntos, comlejidad de O(n)
	for (int i = 0; i < list.size(); i++)
		cout << list[i] << " ";
}
void check(int x) {//Función que imprime el resultado de la busqueda ya sea el valor del indice o un mensaje indicando que el valor no existe en el vector, complejidad de O(1)
	if (x != -1)
		cout << "\n\nEl valor se encuentra en: " << x;
	else
	cout << "\n\nNo se encontro el valor en el vector";
}

int main() {
	//Declaracíon de 4 vectores de diferentes tamaños
	vector<int> list1 = { 7,0,8,9,3,6,1,4,5,2 },
		list2 = { 10,3,8,5,6,10,4,7,2,9,1,11 },
		list3 = { 7,4,6,5,14,1,9,2,3,10,13 };

	//Ordenamiento de vectores
	/* 1. Se imprimirá el vector original usando la función print
	*  2. Se utilizaran los 3 algoritmos de ordenamiento declarados previamente para ordenar las 3 listas
	*  3. Se imprimirá el vector ordenado
	*/

	cout << "Vector 1 fuera de orden original:\n";
	print(list1);//1.
	cout << "\nOrdenamiento Insertion en Vector 1:\n ";
	ordenaInsertion(list1);//2.
	print(list1);//3.

	cout << "\n\nVector 2 fuera de orden original:\n";
	print(list2);
	cout << "\nOrdenamiento Burbuja en Vector 2:\n ";
	ordenaBurbuja(list2);
	print(list2);

	cout << "\n\nVector 3 fuera de orden original:\n";
	print(list3);
	cout << "\nOrdenamiento Merge en Vector 3:\n ";
	ordenaMerge(list3,0,list3.size()-1);
	print(list3);

	//Busqeda 
	/* 1. Se utilizará ambos algoritmos de ordenamiento en los vectores ordenados para encontrar 3 valores diferentes
	*  2. Se utilizará la función check para analizar los resulttados de la busqueda e imprimirlos
	*/
	int b1 = 7, 
		b2 = 9,  
		b3 = 1;
	
	cout << "\n\n---Valor a encotrar:" << b1 << endl;
	check(busqBinaria(list1, b1, 0, list1.size()));
	check(busqSecuencial(list1, b1, 0));

	cout << "\n\n---Valor a encotrar:" << b2 << endl;
	check(busqBinaria(list2, b2, 0, list2.size()));
	check(busqSecuencial(list2, b2, 0));
	
	cout << "\n\n---Valor a encotrar:" << b3 << endl;
	check(busqBinaria(list3, b3, 0, list3.size()));
	check(busqSecuencial(list3, b3, 0));

	return 1;
}

