#include <iostream>
#include <locale.h>
#include <ctime>
#include <string>

using namespace  std;
#include "rlutil.h"
#include "funciones.h"
#include "constantes.h"
#include "menu.h"

int main()
{
	setlocale(LC_CTYPE, "Spanish");
	srand(time(0));

	menu();

	return 0;
}