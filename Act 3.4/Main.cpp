#include "BST.h"
#include "SpalyTree.h"
#include "Bitacora.h"
using namespace std;

/*Act 3.4
* Programa para comparar la eficiencia y velocidad entre dos tipos de arboles binarios, BST y SplayTree
* 11/3/2022
* Autores:
* Francisco Nicolás Jervis Hidalgo A00835131
* Dan Herzberg Alperon A00834217
* Abraham Haziel Pérez López A00833807
*/


/*Funcion para encontrar el valor de cada ip en formato de 64 bits
* entrada: un string respresentando una ip
* salida: un numero de 64 bits equivalente al valor de la ip
* complejidad de O(1)
*/
long long getIpValue(string ip) {
	std::stringstream s(ip);
	int a, b, c, d;
	char ch;
	s >> a >> ch >> b >> ch >> c >> ch >> d;
	long long ip2 = static_cast<long long>(a) * 16777216 + static_cast<long long>(b) * 65536 + static_cast<long long>(c) * 256 + d;
	return ip2;
}
//Función para medir el tiempo de cada busqueda
double get_time(double start, double end) {
	double time = double(end - start) / double(CLOCKS_PER_SEC);
	return time;
}

int main() {
	//Declaración arboles 
	BST<bitacora> BS_tree;
	SplayTree<bitacora> SP_tree1, SP_tree2, SP_tree3, SP_tree4;

	//Vectores de busqueda en los cuales se guardará las ips para bucar en diferentes ordenes
	vector<long long> secuencia, acending, decending;

	//Leer el archivo bitacora.txt y guardar los datos en diferentes estructuras
	ifstream log("bitacora.txt");
	int day, fewcount = 0;
	long long ip2;
	string month, hour, ip, error, iptemp;
	while (log >> month >> day >> hour >> ip) {
		getline(log, error);
		ip2 = getIpValue(ip);
		bitacora temp(month, day, hour, ip, ip2, error);
		//Guardar en los arboles
		BS_tree.add(temp);
		SP_tree1.insert(temp);
		SP_tree2.insert(temp);
		SP_tree3.insert(temp);
		SP_tree4.insert(temp);
		//Guardar las ips en los vectores
		secuencia.push_back(ip2);
		acending.push_back(ip2);
		decending.push_back(ip2);
	}
	//Ordenar los vectores en el orden deseado
	sort(acending.begin(), acending.end());
	sort(decending.begin(), decending.end(), greater<long long>());

	//Cantidad de Busquedas
	int size = 16000;

	//Variables para medir el tiempo
	clock_t start, start2, end2, middle, end;



	/*Se utilizaran 4 casos de prueba los cuales se basan en buscar 16000 ips guardadas en diferentes vectores los cuales estan ordenados de diferentes maneras
	* 1. buscar ips sin un orden espesifico
	* 2. buscar ips en orden acendente
	* 3. buscar ips en orden decendente
	* 4. buscar pocas ips (500) de manera repetida (16000 veces)
	*/

	//Empezar a contar el tiempo
	start = clock();

	//Busquedas en BST
	//Secuencial
	for (int i = 0; i < size; i++, BS_tree.search(secuencia[i]));
		
	end2 = clock();
	double BS_sec = get_time(start, end2);//guardar el tiempo 
	start2 = clock();

	//Acendente
	for (int i = 0; i < size; i++, BS_tree.search(acending[i]));

	end2 = clock();
	double BS_ac = get_time(start2, end2);
	start2 = clock();
	
	//Decendete
	for (int i = 0; i < size; i++, BS_tree.search(decending[i]));

	end2 = clock();
	double BS_dec = get_time(start2, end2);
	start2 = clock();

	//Pocos datos repetidos
	for (int i = 0, i2 = 0; i < size; i++, i2++) {
		if (i2 < 500)
			BS_tree.search(secuencia[i2]);
		else
			i2 = -1;
	}

	middle = clock();
	double BS_few = get_time(start2, middle);
	start2 = clock();

	//Busquedas en SplayTree
	//Pocos datos repetidos
	for (int i = 0, i2 = 0; i < size; i++, i2++) {
		if (i2 < 50)
			SP_tree1.search(secuencia[i2]);
		else
			i2 = -1;
	}
	end2 = clock();
	double SP_few = get_time(start2, end2);
	start2 = clock();

	//Secuencial
	for (int i = 0; i < size; i++,SP_tree2.search(secuencia[i]));

	end2 = clock();
	double SP_sec = get_time(start2, end2);
	start2 = clock();

	//Acendente
	for (int i = 0; i < size; i++,SP_tree3.search(acending[i]));

	end2 = clock();
	double SP_ac = get_time(start2, end2);
	start2 = clock();

	//Decendente
	for (int i = 0; i < size; i++,SP_tree4.search(decending[i]));

	end = clock();
	double SP_dec = get_time(start2, end);

	//guardar tiempos finales
	double Bst = get_time(start, middle), Spt = get_time(middle, end);


	cout << "Tiempos de busquedas en BTS:\n"
		<< "Secuencial: " << BS_sec << "s\n"
		<< "Decendiente: " << BS_dec << "s\n"
		<< "Acendente: " << BS_ac << "s\n"
		<< "Pocos datos repetidos:" << BS_few << "s\n"
		<< "\nTiempos de busquedas en SplayTree:\n"
		<< "Secuencial: " << SP_sec << "s\n"
		<< "Decendiente: " << SP_dec << "s\n"
		<< "Acendente: " << SP_ac << "s\n"
		<< "Pocos datos repetidos:" << SP_few << "s\n"
		<< "\nEl tiempo total para correr los 4 casos de prueba en el BST es: " << Bst << "s\n"
		<< "El tiempo total para correr los 4 casos de prueba en el SplayTree es: " << Spt << "s\n";

	/*Analisis de tiempos finales:
	* En 3 de los 4 casos de prueba el BST es mas eficiente y obtiene los resultados mas rapido estos siendo los casos 1, 2 y 3,
	* y en el tiempo general el cual suma todos los tiempos de ejecucion el BST tambien logra completar los casos de prueba en un menor tiempo
	* pero en caso 4 El splay tree es mas rapido, esto se debe a su habilidad de llevar el nodo el cual se acaba buscar hacia la raiz del arbol lo que significa que una busqueda a un nodo el cual ya fue buscado resultara mas rapida 
	*/
}