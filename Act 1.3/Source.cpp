#include "bitacora.h"
/*Act 1.3
* Programa para organizar y buscar por fecha diferentes etradas en una bitacora en forma de texto
* 09/14/2022
* Autores: Francisco Nicolás Jervis Hidalgo A00835131
* Dan Herzberg Alperon A00834217
* Abraham Haziel Pérez López A00833807
*/

/*Algoritmo basado en merge sort el cual utiliza la sumatoria de el tiempo total de cada log para el ordenamiento
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
		if (list[i].Ttime <= list[x].Ttime) {
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
*/
void print_to_f(std::ofstream& file, vector<bitacora>& list){
	for (int i = 0; i < list.size(); i++){
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



		file << m << " " << list[i].day << " " << list[i].hora << " " << list[i].ip << list[i].error<< std::endl;
	}
}
/*Función para obtener el tiempo total en segundos de cada log
* entrada: un vector tipo bitacora
* salida: ninguna
*/
void getTime(vector<bitacora>& list) {
	int temp,temp2=0;
	vector<int> vect;
	for (int i = 0; i < list.size(); i++)
	{
		
		std::stringstream ss(list[i].hora);
		for (int x; ss >> x;) {
			vect.push_back(x);
			if (ss.peek() == ':')
				ss.ignore();	
		}
		temp2= vect[0]*3600  + vect[1]*60  + vect[2];
		temp = list[i].month * 2592000 + list[i].day*86400+temp2;
		list[i].Ttime = temp;
		vect.clear();
	}
}


int main() {
	//Declaración de variables necesarias
	std::ifstream log("bitacora.txt");
	vector<bitacora> lista;
	int day, diainicial, diafinal, mesinicial, mesfinal;
	string month, hour, ip, error;

	//loop para leer el archivo y guardarlo en un vector
	while (log>>month>>day>>hour>>ip){
		getline(log, error);
		bitacora temp(month,day,hour,ip,error);
		lista.push_back(temp);
	}
	//Obtener el tiempo de cada log
	getTime(lista);

	//Ordenar el vector con los valores guardados
	sortlog(lista,0,lista.size()-1);
	//Guardar datos del vector en un archivo de texto
	std::ofstream log2("bitacora2.txt");
	print_to_f(log2, lista);

	//Pedir al usuario fechas limites para busqueda
	cout << "Ingresar Fecha de inicio de busqueda en formato numerico con un espacio de separacion (mes dia)\n";
	cin >> mesinicial >> diainicial;
	cout << "\nIngresar Fecha de fin de busqueda en formato numerico con un espacio de separacion (mes dia)\n";
	cin >> mesfinal >> diafinal;

	//loop para imprimir los logs en caso de que el dia sea igual
	if (mesinicial == mesfinal) {
		for (int i = 0; i < lista.size(); i++) {
			if ((lista[i].month == mesinicial) && (lista[i].day >= diainicial && lista[i].day <= diafinal))
				lista[i].print();
		}
	}
	//loop para imprimir los logs basados en las fechas limites
	else{
		for (int i = 0; i < lista.size(); i++) {
			if ((lista[i].month == mesfinal && lista[i].day <= diafinal) ||
				(lista[i].month == mesinicial && lista[i].day >= diainicial) ||
				(lista[i].month<mesfinal && lista[i].month>mesinicial))
				lista[i].print();
		}
	}
	return 1;
}