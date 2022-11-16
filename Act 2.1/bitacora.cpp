#include "bitacora.h"


bitacora::bitacora()
{
}

bitacora::bitacora(string m, int d, string h, string _ip, string e)
{
	day = d;
	hora = h;
	ip = _ip;
	error = e;


	if (m == "Jun")
		month = 6;
	else if (m == "Jul")
		month = 7;
	else if (m == "Aug")
		month = 8;
	else if (m == "Sep")
		month = 9;
	else if (m == "Oct")
		month = 10;
	else if (m == "Nov")
		month = 11;
	else if (m == "Dic")
		month = 12;
	else if (m == "Jan")
		month = 1;
	else if (m == "Feb")
		month = 2;
	else if (m == "Mar")
		month = 3;
	else if (m == "Apr")
		month = 4;
	else if (m == "May")
		month = 5;

}

void bitacora::print()
{
	string m;
	if (month == 6)
		m = "Jun";
	else if (month == 7)
		m = "Jul";
	else if (month == 8)
		m = "Aug";
	else if (month == 9)
		m = "Sep";
	else if (month == 10)
		m = "Oct";
	else if (month == 11)
		m = "Nov";
	else if (month == 12)
		m = "Dic";
	else if (month == 1)
		m = "Jan";
	else if (month == 2)
		m = "Feb";
	else if (month == 3)
		m = "Mar";
	else if (month == 4)
		m = "Apr";
	else if (month == 5)
		m = "May";

	cout << m << " " << day << " " << hora << " " << ip << error << std::endl;

}



