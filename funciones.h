#pragma once

//DECLARACION DE FUNCIONES

void pedirNombre(string nombreJugador[], int opcion); //Asigna el nombre ingresado a una variable por referencia

void tirarDados(int vDados[], int tam); //Carga un vector de un tamaño especificado con numeros aleatorios 1-6, recibe una constante por valor de la cantidad de lanzamientos por turno

void mostrarDados(int vDados[], int tam); //Muestra los valores obtenidos

//void jugar(string nombreJugador[], int opcion, int PUNTAJE_OBJETIVO, int LANZAMIENTOS_POR_RONDA, int CANTIDAD_DADOS, int vDados[], string& usuarioMaxPuntuacion, int& maxPuntuacion); // Llama a las demas funciones hasta que la partida termina

int calcularPuntos(int vDados[], int tam, int PUNTAJEOBJETIVO); // Devuelve los maxPuntuacion segun las combinaciones de los dados

void mostrarInterfazTurno(string usuario, int ronda, int puntajeTotal, int maxPuntajeRonda, int nroLanzamiento); // Muestra la interfaz de usuario durante los lanzamientos

void mostrarInterfazEntreTurno(int ronda, string nombre[], int indice, int totalJ1, int totalJ2);

int sumarDados(int vDados[]);

void ordenarDados(int vDados[], int tam);

bool escalera(int vDados[], int tam);

bool seisDeSeis(int vDados[]);

bool seisIguales(int vDados[]);

void copiarTirarDados(int vDados[], int vDados2[], int tam);//Copia la funcion tirar dados

void jugarSolo(string nombreJugador[], int opcion, int PUNTAJE_OBJETIVO, int LANZAMIENTOS_POR_RONDA, int CANTIDAD_DADOS, int vDados[], string& usuarioMaxPuntuacion, int& maxPuntuacion);

void jugarDuo(string nombreJugador[], int opcion, int PUNTAJE_OBJETIVO, int LANZAMIENTOS_POR_RONDA, int CANTIDAD_DADOS, int vDados[], string &usuarioMaxPuntuacion, int &maxPuntuacion);

void jugarSimulado(string nombreJugador[], int opcion, int PUNTAJE_OBJETIVO, int LANZAMIENTOS_POR_RONDA, int CANTIDAD_DADOS, int vDados[], string& usuarioMaxPuntuacion, int& maxPuntuacion); //Modo Testing

void mostrarMaxPuntuacion(string &usuarioMaxPuntuacion, int &maxPuntuacion); // Muestra la puntuacion maxima lograda y el usuario correspondiente

void guardarMaxPuntuacion(int vTotal[], int ronda, string nombreJugador[], string& usuarioMaxPuntuacion, int& maxPuntuacion);//Guarda el usuario, la máxima puntuacion y si llega o supera 100.

bool evaluarCienPuntos(int vTotal[], int ronda, string nombreJugador[]);



//IMPLEMENTACION DE FUNCIONES

void pedirNombre(string nombreJugador[], int opcion) {
	string nombreJug;

	if (opcion == 1 || opcion == 4) //si la opción es '1' completa 1 solo jugador
	{
		cout << "Ingresar nombre para Jugador 1: ";
		cin.ignore();
		getline(cin, nombreJug);
		nombreJugador[0] = nombreJug;
		//nombreJugador[1] = "CPU";
	}
	else  // Sino, permite ingresar dos jugadores
	{
		cout << "Ingresar nombre para Jugador 1: ";
		cin.ignore();
		getline(cin, nombreJug);
		nombreJugador[0] = nombreJug;

		cout << "Ingresar nombre para Jugador 2: ";
		getline(cin, nombreJug);
		nombreJugador[1] = nombreJug;
	}
}

void tirarDados(int vDados[], int tam) {
	for (int i = 0; i < tam; i++) {
		vDados[i] = (rand() % 6) + 1;
	}
}

void mostrarInterfazTurno(string usuario, int ronda, int puntajeTotal, int maxPuntajeRonda, int nroLanzamiento) {
	system("cls");

	cout << "TURNO DE " << usuario;
	cout << "  |  ";
	cout << "RONDA Nro " << ronda;
	cout << "  |  ";
	cout << "PUNTAJE TOTAL: " << puntajeTotal << " PUNTOS" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "MAXIMO PUNTAJE DE LA RONDA: " << maxPuntajeRonda << " PUNTOS" << endl;
	cout << "LANZAMIENTO Nro " << nroLanzamiento << endl;
	cout << "-------------------------------------------------------------------" << endl;
}

void mostrarInterfazEntreTurno(int ronda, string nombre[], int indice, int totalJ1, int totalJ2) {
	cout << "*-----------------------------------------*" << endl;
	cout << "              RONDA N° " << ronda << endl;
	cout << "        PROXIMO TURNO: " << nombre[indice] << endl;
	cout << endl;
	cout << "        PUNTAJE " << nombre[0] << ": " << totalJ1 << " PUNTOS" << endl;
	cout << "        PUNTAJE " << nombre[1] << ": " << totalJ2 << " PUNTOS" << endl;
	cout << endl;
	cout << "*------------------**---------------------*" << endl;
	system("pause"); 
	system("cls");
}

void mostrarDados(int vDados[], int tam)
{
	for (int i = 0; i < tam; i++)
	{
		cout << "Dado " << i + 1 << " - " << vDados[i] << endl;
	}
}

int sumarDados(int vDados[]) {
	int suma = 0;
	for (int i = 0; i < 6; i++) {
		suma += vDados[i];
	}
	return suma;
}

void ordenarDados(int vDados[], int tam) {
	int i, j, posmin, aux;
	for (i = 0; i < tam - 1; i++) {
		posmin = i;
		for (j = i + 1; j < tam; j++) {
			if (vDados[j] < vDados[posmin]) {
				posmin = j;
			}
		}
		aux = vDados[i];
		vDados[i] = vDados[posmin];
		vDados[posmin] = aux;
	}
	//for (int i = 0; i < 6; i++)
	//{
	//	cout << "[" << vDados[i] << "]";

	//}
}

bool escalera(int vDados[], int tam) {
	int vDadosCopia[6];  //CREA UNA COPIA DEL VECTOR DADOS

	copiarTirarDados(vDados, vDadosCopia, tam);

	ordenarDados(vDadosCopia, tam); //ORDENA LA COPIA PARA VERIFICAR SI HAY ESCALERA, SIN AFECTAR EL VECTOR ORIGINAL

	int contador = 0;
	for (int i = 0; i < 6; i++) {
		if (vDadosCopia[i] == i + 1) {
			contador++;
		}
	}

	if (contador == 6) {
		//cout << "escalera" << endl; //PRUEBA
		return true;
	}
	else
	{
		return false;
	}
}

bool seisDeSeis(int vDados[]) {
	int contador = 0;
	for (int i = 0; i < 6; i++)
	{
		if (vDados[i] == 6) {
			contador++;
		}
	}
	if (contador == 6)
	{
		//cout << "Seis dados 6";
		return true;
	}
	else
	{
		return false;
	}
}

bool seisIguales(int vDados[]) {
	int repetidos = 0;
	for (int i = 1; i < 6; i++)
	{
		if (vDados[i] == vDados[i - 1])
		{
			repetidos++;
		}
	}
	if (repetidos == 5)
	{
		//cout << "Seis dados iguales";
		return true;
	}
	else
	{
		return false;
	}
}

int calcularPuntos(int vDados[], int tam, int PUNTAJEOBJETIVO) {
	int calculo = -1;

	if (escalera(vDados, tam)) {
		calculo = PUNTAJEOBJETIVO;
	}
	else if (seisDeSeis(vDados)) {
		//Seis dados SEIS, devuelve 0
		calculo = 0;
	}
	else if (seisIguales(vDados)) {
		//Seis dados IGUALES, devuelve valor repetido * 10
		calculo = vDados[0] * 10;
	}
	else {
		//Sumar todos los dados
		calculo = sumarDados(vDados);
	}

	return calculo;
}

int jugarSimulado(int vDados[], int tirarDadosManual, int sumarDados, int ordenarDados, int escalera, int seisDeseis, int seisIguales, int tam)
{

	for (int i = 0; i < tam; i++)
	{
		cout << "INGRESE DADO: ";
		cin >> vDados[i];
	}

	int i, j, posmin, aux;
	for (i = 0; i < tam - 1; i++)
	{
		posmin = i;
		for (j = i + 1; j < tam; j++)
		{
			if (vDados[j] < vDados[posmin]) posmin = j;
		}
		aux = vDados[i];
		vDados[i] = vDados[posmin];
		vDados[posmin] = aux;
	}

	int contador = 0;
	for (int i = 0; i < 6; i++)
	{
		if (vDados[i] == i + 1)
		{
			contador++;
		}
	}

	if (contador == 6)
	{
		cout << "escalera";
		return true;
	}
	else
	{
		int contador = 0;
		for (int i = 0; i < 6; i++)
		{
			if (vDados[i] == 6)
			{
				contador++;
			}
		}

		if (contador == 6)
		{
			cout << "Seis dados 6";
			return true;
		}
		else
		{
			int repetidos = 0;
			for (int i = 1; i < 6; i++)
			{
				if (vDados[i] == vDados[i - 1])
				{
					repetidos++;
				}
			}

			if (repetidos == 5 && vDados[0] != 6)
			{
				cout << "Seis dados iguales";
				return true;
			}
			else
			{
				int suma = 0;
				for (int i = 0; i < 6; i++)
				{
					suma += vDados[i];
				}
				cout << "La suma es: " << suma;
			}
		}
	}
}

void copiarTirarDados(int vDados[], int vDados2[], int tam)
{
	cout << "La copia del los dados es: ";
	int i;
	for (i = 0; i < tam; i++)
	{
		vDados2[i] = vDados[i];
		cout << vDados2[i] << "\t";
	}
}

void mostrarMaxPuntuacion(string &usuarioMaxPuntuacion, int &maxPuntuacion) {

	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "                                                           " << endl;
	cout << "                   MAXIMA PUNTUACION                       " << endl;
	cout << "                                                           " << endl;
	cout << "              JUGADOR: "<< usuarioMaxPuntuacion << endl;
	cout << "                                                           " << endl;
	cout << "              PUNTOS: " << maxPuntuacion<< " PUNTOS" << endl;
	cout << "                                                           " << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	system("pause");
	system("cls");
}

bool evaluarCienPuntos(int vTotal[], int ronda, string nombreJugador[]){
	
	if (vTotal[0] > vTotal[1])
	{
		if (vTotal[0] >= 100)
		{
			cout << "*-----------------------------------------*" << endl;
			cout << "\nFELICIDADES " << nombreJugador[0] << "! GANASTE LA PARTIDA!" << endl;
			cout << "PUNTAJE FINAL: " << vTotal[0] << endl;
			cout << "TOTAL DE RONDAS: " << ronda << endl;
			cout << "*-----------------------------------------*" << endl;
			system("pause");
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (vTotal[1] >= 100)
		{
			cout << "*-----------------------------------------*" << endl;
			cout << "\nFELICIDADES " << nombreJugador[1] << "! GANASTE LA PARTIDA!" << endl;
			cout << "PUNTAJE FINAL: " << vTotal[1] << endl;
			cout << "TOTAL DE RONDAS: " << ronda << endl;
			cout << "*-----------------------------------------*" << endl;
			system("pause");
			return true;
		}
		else
		{
			return false;
		}
	}
}

void guardarMaxPuntuacion(int vTotal[], int ronda, string nombreJugador[], string& usuarioMaxPuntuacion, int& maxPuntuacion) {
	if (vTotal[0] > vTotal[1])
	{
		if (vTotal[0] > maxPuntuacion)
		{
			maxPuntuacion = vTotal[0];
			usuarioMaxPuntuacion = nombreJugador[0];
		}
	}
	else
	{
		if (vTotal[1] > maxPuntuacion)
		{
			maxPuntuacion = vTotal[1];
			usuarioMaxPuntuacion = nombreJugador[1];
		}
	}
}

void jugarDuo(string nombreJugador[], int opcion, int PUNTAJE_OBJETIVO, int LANZAMIENTOS_POR_RONDA, int CANTIDAD_DADOS, int vDados[], string& usuarioMaxPuntuacion, int& maxPuntuacion) {

	int puntajeTotal = 0, ronda = 1; //Inicialización de variables
	int puntajeLanzamiento;
	/*int maxPuntuacion = 0;
	string usuarioMaxPuntuacion;*/

	//A CADA JUGADOR LE CORRESPONDE UN INDICE DE MAXIMO PUNTAJE Y DE TOTAL
	int vMaxPuntajeRonda[2] = { 0 }, vTotal[2] = { 0 };

	pedirNombre(nombreJugador, opcion);

	//CICLO DE RONDAS
	while (puntajeTotal < PUNTAJE_OBJETIVO) {
		
		int maxPuntajeRonda = 0;
		system("cls");

		//CICLO DE LANZAMIENTOS DE DADOS
		for (int i = 0; i < LANZAMIENTOS_POR_RONDA; i++) {
			
			//CICLO  PARA INTERCALAR LANZAMIENTOS
			for (int j = 0; j < 2; j++) { 

				mostrarInterfazEntreTurno(ronda, nombreJugador, j, vTotal[0], vTotal[1]);

				tirarDados(vDados, CANTIDAD_DADOS);
				puntajeLanzamiento = calcularPuntos(vDados, CANTIDAD_DADOS, PUNTAJE_OBJETIVO);

				if (puntajeLanzamiento == PUNTAJE_OBJETIVO) { //Si hay escalera, gana la partida
					vMaxPuntajeRonda[j] = puntajeLanzamiento;

					mostrarInterfazTurno(nombreJugador[j], ronda, vTotal[j], vMaxPuntajeRonda[j], i + 1);
					mostrarDados(vDados, CANTIDAD_DADOS);
					cout << "\n¡ESCALERA! !GANASTE LA PARTIDA¡" << endl;
					vTotal[j] = 100;
					system("pause");
					system("cls");
					return; //Vuelve al menú
				}
				else if (puntajeLanzamiento == 0) { //Si hay seis 6, resetea el puntaje a 0
					vMaxPuntajeRonda[j] = puntajeLanzamiento;
					vTotal[j] = 0;
					mostrarInterfazTurno(nombreJugador[j], ronda, vTotal[j], vMaxPuntajeRonda[j], i + 1);
					mostrarDados(vDados, CANTIDAD_DADOS);
					cout << "\nSEIS DE SEIS! TU PUNTAJE TOTAL FUE REINICIADO A CERO!\n" << endl;
					system("pause");
				}
				else if (puntajeLanzamiento > vMaxPuntajeRonda[j]) {
					vMaxPuntajeRonda[j] = puntajeLanzamiento;
				}
				mostrarInterfazTurno(nombreJugador[j], ronda, vTotal[j], vMaxPuntajeRonda[j], i + 1);
				mostrarDados(vDados, CANTIDAD_DADOS);
				system("pause");
				system("cls");

			}

		}

		//Termina la ronda y asigna al total de cada jugador el mayor puntaje obtenido en la ronda.
		vTotal[0] += vMaxPuntajeRonda[0]; 
		vTotal[1] += vMaxPuntajeRonda[1];

		// Resetea el máximo puntaje de la ronda finalizada.
		for (int i = 0; i < 2; i++) 
		{
			vMaxPuntajeRonda[i] = 0;
		}

		guardarMaxPuntuacion(vTotal, ronda, nombreJugador, usuarioMaxPuntuacion, maxPuntuacion);

		if (evaluarCienPuntos(vTotal, ronda, nombreJugador))
		{
			break; //Para que salga del ciclo una vez alcanzado el puntaje 100
		}

		ronda++;
		//system("pause");
	}

}

void jugarSolo(string nombreJugador[], int opcion, int PUNTAJE_OBJETIVO, int LANZAMIENTOS_POR_RONDA, int CANTIDAD_DADOS, int vDados[], string& usuarioMaxPuntuacion, int& maxPuntuacion) {
	int puntajeTotal = 0, ronda = 1; //Inicialización de variables
	int puntajeLanzamiento;

	//A CADA JUGADOR LE CORRESPONDE UN INDICE DE MAXIMO PUNTAJE Y DE TOTAL
	int vMaxPuntajeRonda[2] = { 0 }, vTotal[2] = { 0 };
	
	pedirNombre(nombreJugador, opcion);

	//CICLO DE RONDAS
	while (puntajeTotal < PUNTAJE_OBJETIVO) {

		int maxPuntajeRonda = 0;
		system("cls");

		//CICLO DE LANZAMIENTOS DE DADOS
		for (int i = 0; i < LANZAMIENTOS_POR_RONDA; i++) {

				tirarDados(vDados, CANTIDAD_DADOS);

				puntajeLanzamiento = calcularPuntos(vDados, CANTIDAD_DADOS, PUNTAJE_OBJETIVO);

				if (puntajeLanzamiento == PUNTAJE_OBJETIVO) { //Si hay escalera, gana la partida
					vMaxPuntajeRonda[0] = puntajeLanzamiento;

					mostrarInterfazTurno(nombreJugador[0], ronda, vTotal[0], vMaxPuntajeRonda[0], i + 1);
					mostrarDados(vDados, CANTIDAD_DADOS);
					cout << "\n¡ESCALERA! !GANASTE LA PARTIDA¡" << endl;
					return; //vuelve al menú
				}
				else if (puntajeLanzamiento == 0) { //Si hay seis 6, resetea el puntaje a 0
					vMaxPuntajeRonda[0] = puntajeLanzamiento;
					vTotal[0] = 0;
					mostrarInterfazTurno(nombreJugador[0], ronda, vTotal[0], vMaxPuntajeRonda[0], i + 1);
					mostrarDados(vDados, CANTIDAD_DADOS);
					cout << "\nSEIS DE SEIS! TU PUNTAJE TOTAL FUE REINICIADO A CERO!\n" << endl;
					system("pause");
				}
				else if (puntajeLanzamiento > vMaxPuntajeRonda[0]) {
					vMaxPuntajeRonda[0] = puntajeLanzamiento;
				}
				mostrarInterfazTurno(nombreJugador[0], ronda, vTotal[0], vMaxPuntajeRonda[0], i + 1);
				mostrarDados(vDados, CANTIDAD_DADOS);
				system("pause");
				system("cls");

		}

		//Termina la ronda y asigna al total de cada jugador el mayor puntaje obtenido en la ronda.
		vTotal[0] += vMaxPuntajeRonda[0];

		// Resetea el máximo puntaje de la ronda finalizada.
		for (int i = 0; i < 2; i++)
		{
			vMaxPuntajeRonda[i] = 0;
		}

		guardarMaxPuntuacion(vTotal, ronda, nombreJugador, usuarioMaxPuntuacion, maxPuntuacion);

		if (evaluarCienPuntos(vTotal, ronda, nombreJugador))
		{
			break; //Para que salga del ciclo una vez alcanzado el puntaje 100
		}

		ronda++;
		//system("pause");
	}
}

void jugarSimulado(string nombreJugador[], int opcion, int PUNTAJE_OBJETIVO, int LANZAMIENTOS_POR_RONDA, int CANTIDAD_DADOS, int vDados[], string& usuarioMaxPuntuacion, int& maxPuntuacion) {
	cout << "INGRESASTE AL MODO TESTING!" << endl;
	int puntajeTotal = 0, ronda = 1; //Inicialización de variables
	int puntajeLanzamiento;

	//A CADA JUGADOR LE CORRESPONDE UN INDICE DE MAXIMO PUNTAJE Y DE TOTAL
	int vMaxPuntajeRonda[2] = { 0 }, vTotal[2] = { 0 };

	pedirNombre(nombreJugador, opcion);

	//CICLO DE RONDAS
	while (puntajeTotal < PUNTAJE_OBJETIVO) {

		int maxPuntajeRonda = 0;
		system("cls");

		//CICLO DE LANZAMIENTOS DE DADOS
		for (int i = 0; i < LANZAMIENTOS_POR_RONDA; i++) {

			//CARGAR DADOS MANUELMENTE
			int vDados[6] = { 0 }, num;
			for (int i = 0; i < 6; i++)
			{
				cout << "Ingresar dado " << i + 1 << ": ";
				cin >> num;
				vDados[i] = num;
				cout << endl;
			}

			puntajeLanzamiento = calcularPuntos(vDados, CANTIDAD_DADOS, PUNTAJE_OBJETIVO);

			if (puntajeLanzamiento == PUNTAJE_OBJETIVO) { //Si hay escalera, gana la partida
				vMaxPuntajeRonda[0] = puntajeLanzamiento;

				mostrarInterfazTurno(nombreJugador[0], ronda, vTotal[0], vMaxPuntajeRonda[0], i + 1);
				mostrarDados(vDados, CANTIDAD_DADOS);
				cout << "\n¡ESCALERA! !GANASTE LA PARTIDA¡" << endl;
				break; //Sale del ciclo for
			}
			else if (puntajeLanzamiento == 0) { //Si hay seis 6, resetea el puntaje a 0
				vMaxPuntajeRonda[0] = puntajeLanzamiento;
				vTotal[0] = 0;
				mostrarInterfazTurno(nombreJugador[0], ronda, vTotal[0], vMaxPuntajeRonda[0], i + 1);
				mostrarDados(vDados, CANTIDAD_DADOS);
				cout << "\nSEIS DE SEIS! TU PUNTAJE TOTAL FUE REINICIADO A CERO!\n" << endl;
				system("pause");
			}
			else if (puntajeLanzamiento > vMaxPuntajeRonda[0]) {
				vMaxPuntajeRonda[0] = puntajeLanzamiento;
			}
			mostrarInterfazTurno(nombreJugador[0], ronda, vTotal[0], vMaxPuntajeRonda[0], i + 1);
			mostrarDados(vDados, CANTIDAD_DADOS);
			system("pause");
			system("cls");

		}

		//Termina la ronda y asigna al total de cada jugador el mayor puntaje obtenido en la ronda.
		vTotal[0] += vMaxPuntajeRonda[0];

		// Resetea el máximo puntaje de la ronda finalizada.
		for (int i = 0; i < 2; i++)
		{
			vMaxPuntajeRonda[i] = 0;
		}

		guardarMaxPuntuacion(vTotal, ronda, nombreJugador, usuarioMaxPuntuacion, maxPuntuacion);

		if (evaluarCienPuntos(vTotal, ronda, nombreJugador))
		{
			break; //Para que salga del ciclo una vez alcanzado el puntaje 100
		}

		ronda++;
		//system("pause");
	}
}


