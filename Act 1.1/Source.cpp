//Francisco Jervis A00835131
#include <iostream>
using namespace std;

int sumIterativa(int n) {//Funcion para sumar los numeros de 1 hasta por metodo iterativo (loop)
	//Complejidad computacional de O(n)
	int sum=0;
	for (int i = 0; i < n; i++)
	{
		sum= sum + (n - i);
	};
	return sum;
}
int sumRecursiva(int n) {//Funcion para sumar los numeros de 1 hasta por metodo recursivo
	//Complejidad computacional de O(n)
	if (n != 1) {
		return n + sumRecursiva(n - 1);
	}
}
int sumDirecta(int n) {//Funcion para sumar los numeros de 1 hasta por metodo matematico
	//Complejidad computacional de O(1)
	return (n * (n + 1)) / 2;
}

int main() {
	int n,//variable para la suma hasta n
	opcion,//variable para el metodo a utilizar
	menu=1;//variable para loop de menu
	cout << "Introduzca un entero positivo" << endl;
	cin >> n;
	cout << "n= " << n << endl;
	while (menu==1)//while loop para revisar que la opcion introducida sea valida
	{
		cout << "1: Metodo Recursivo\n2: Metodo Iterativo\n3: Metodo Diercto" << endl;
		cout << "Opcion:";
		cin >> opcion;
		switch (opcion)
		{
		case 1://Recursiva
			menu = 0;
			cout << "suma =" << sumRecursiva(n) << endl;
			break;

		case 2://Iterativa
			cout << "suma =" << sumIterativa(n) << endl;
			menu = 0;
			break;

		case 3://Directa
			cout << "suma =" << sumDirecta(n) << endl;
			menu = 0;
			break;
		
		}
		if (opcion!=1 && opcion != 2 && opcion != 3)
		{
			cout << "Opcion invalida" << endl;
		}
		
	}	
}