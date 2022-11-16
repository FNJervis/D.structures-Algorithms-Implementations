#include "bitacora.h"
/*Act 2.3
* Programa para guradar datos de un archivo en un vector, ordenarlo segun el valor de sus ips y guardarlo en un archivo nuevo 
* 10/13/2022
* Autores: 
* Francisco Nicolás Jervis Hidalgo A00835131
* Dan Herzberg Alperon A00834217
* Abraham Haziel Pérez López A00833807
*/

/*Algoritmo basado en merge sort el cual utiliza el valor de la ip de cada log para el ordenamiento
* Algoritmo de ordenamiento el cual funciona por un metodo recursivo, El funcionamiento se basa en descomponer el vector en subvectores mas pequeños, despues de esto el algoritmo compara cada uno de estos subvectores singulares y los va combinado a subvectores mas grandes ya ordenados
* Las entradas del algoritmo son: un vector pasado por referencia, el primer indice del vector y el ultimo indice del vector
* No tiene una salida
* Su complejidad es de O(nlog(n))
*/

void Merge(vector<bitacora>& list, int start, int mid, int end) {
	vector<bitacora> temp;
	int i = start,
		x = mid + 1;
	while (i <= mid && x <= end) {
		if (list[i].ipvalue <= list[x].ipvalue) {
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

void sortlog(vector<bitacora>& list, int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		sortlog(list, start, mid);
		sortlog(list, mid + 1, end);
		Merge(list, start, mid, end);
	}
}

/*Función para imprimir los datos de un vector a un archivo de texto
* entrada: archivo tipo ofstream y un vector, ambos por referencia
* salida: ninguna
* comlejidad de O(n)
*/
void print_to_f(std::ofstream& file, vector<bitacora>& list) {
	for (int i = 0; i < list.size(); i++) {
		string m;
		if (list[i].month == 6)
			m = "Jun";
		else if (list[i].month == 7)
			m = "Jul";
		else if (list[i].month == 8)
			m = "Aug";
		else if (list[i].month == 9)
			m = "Sep";
		else if (list[i].month == 10)
			m = "Oct";
		else if (list[i].month == 11)
			m = "Nov";
		else if (list[i].month == 12)
			m = "Dic";
		else if (list[i].month == 1)
			m = "Jan";
		else if (list[i].month == 2)
			m = "Feb";
		else if (list[i].month == 3)
			m = "Mar";
		else if (list[i].month == 4)
			m = "Apr";
		else if (list[i].month == 5)
			m = "May";



		file << m << " " << list[i].day << " " << list[i].hora << " " << list[i].ip << list[i].error << std::endl;
	}
}
/*FUncion para encontrar el valor de cada ip en formato de 64 bits
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

int main() {
	//Declaración de variables necesarias
	std::ifstream log("bitacora.txt");
	vector<bitacora> lista;
	int day;
	long long ip2, ipB, ipA;
	string month, hour, ip, error, iptemp;

	//loop para leer el archivo y guardarlo en un vector
	while (log >> month >> day >> hour >> ip) {
		getline(log, error);
		ip2 = getIpValue(ip);
		bitacora temp(month, day, hour, ip, ip2, error);
		lista.push_back(temp);
	}
	//Ordenar el vector con los valores guardados
	sortlog(lista, 0, lista.size() - 1);

	//Guardar datos del vector en un archivo de texto
	std::ofstream log2("bitacora2.txt");
	print_to_f(log2, lista);

	//Pedir limites de busqueda
	cout << "Ingreasar limite bajo para busqueda de ip\n Formato: a.b.c.d\n";
	cin >> iptemp;
	ipB = getIpValue(iptemp);

	cout << "Ingreasar limite alto para busqueda de ip\n Formato: a.b.c.d\n";
	cin >> iptemp;
	ipA = getIpValue(iptemp);

	//iterar el vector hasta encontrar el limite bajo e imprimir los elemnetos hasta encontrar el limite alto
	int index;
	for (index = 0; lista[index].ipvalue <= ipB; index++);
	for (; lista[index].ipvalue < ipA; index++)
		lista[index].print();
}
