#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using std::vector;
using std::cin;
using std::string;
using std::cout;
//Clase para guardar el formato de los logs
class bitacora
{
public:
	int month;
	int day;
	string hora;
	string ip;
	long long ipvalue;
	string error;
	bitacora(string, int, string, string, long long, string);
	void print();//Funcion para imprimir los datos de la bitacora remplazando el mes numerico por mes literal

};
