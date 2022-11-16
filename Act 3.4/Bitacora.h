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
	string month;
	int day;
	string hora;
	string ip;
	long long ipvalue;
	string error;
	bitacora(string m, int d, string h, string _ip, long long _ipv, string e) {
		month = m;
		day = d;
		hora = h;
		ip = _ip;
		ipvalue = _ipv;
		error = e;
	}
	bitacora() {

	}
	bitacora(long long _ipv) {
		ipvalue = _ipv;
	}
	void print() {//Funcion para imprimir los datos de la bitacora remplazando el mes numerico por mes literal
		cout << month << " " << day << " " << hora << " " << ip << error << std::endl;
	}
};
