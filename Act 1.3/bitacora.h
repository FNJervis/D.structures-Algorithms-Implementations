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
	int Ttime;
	int month;
	int day;
	string hora;
	string ip;
	string error;
	

	bitacora(string, int, string, string, string);
	void print();//Funcion para imprimir los datos de la bitacora remplazando el mes numerico por mes literal
	
};

