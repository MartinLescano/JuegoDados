#include <iostream>
#include <locale.h>
#include <ctime>
#include "menu.h"
using namespace  std;

int main()
{
	setlocale(LC_CTYPE, "Spanish");
	srand(time(0));
	
	menu();

	/*int vector[6] = { 6,2,4,5,3,1 };
	escalera(vector);
	seisDeSeis(vector);
	seisIguales(vector);
	cout << endl;
	mostrarDados(vector, 6);
	calcularPuntos(vector, 6);*/

	return 0;
}