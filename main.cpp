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

	return 0;
}