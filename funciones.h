#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

//DECLARACION DE FUNCIONES

void pedirNombre(string& nombre); //Asigna el nombre ingresado a una variable por referencia

void tirarDados(int vDados[], int tam); //Carga un vector de un tamaño especificado con numeros aleatorios 1-6, recibe una constante por valor de la cantidad de lanzamientos por turno

void mostrarDados(int vDados[], int tam); //Muestra los valores obtenidos

void jugar(int puntajeObjetivo, int lanzamientosPorRonda, int cantidadDados, int vDados[]); // Llama a las demas funciones hasta que la partida termina

void mostrarMaxPuntuacion(string usuarioMaxPuntuacion, int maxPuntuacion); // Muestra la puntuacion maxima lograda y el usuario correspondiente

int calcularPuntos(int vDados[], int tam, int PUNTAJEOBJETIVO); // Devuelve los puntos segun las combinaciones de los dados

void mostrarInterfazTurno(string usuario, int ronda, int puntajeTotal, int maxPuntajeRonda, int nroLanzamiento); // Muestra la interfaz de usuario durante los lanzamientos

void mostrarInterfazEntreTurno(string usuario, int ronda, int puntajeTotal); // Muestra la interfaz del o los usuarios entre los turnos

int sumarDados(int vDados[]);

void ordenarDados(int vDados[], int tam);

bool escalera(int vDados[], int tam);

bool seisDeSeis(int vDados[]);

bool seisIguales(int vDados[]);

int jugarSimulado(int vDados[], int tirarDadosManual, int sumarDados, int ordenarDados, int escalera, int seisDeseis, int seisIguales, int tam); //Para ver la funcionalidad de cada funcion

void copiarTirarDados(int vDados[], int vDados2[], int tam);//Copia la funcion tirar dados


//IMPLEMENTACION DE FUNCIONES

void pedirNombre(string& nombre) {
	system("cls");
	cout << "Ingresar nombre del jugador: ";

	cin.ignore();
	getline(cin, nombre);

	system("cls");
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

void mostrarInterfazEntreTurno(string usuario, int ronda, int puntajeTotal) {

	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "'                                                         '" << endl;
	cout << "'                     RONDA Nº                            '" << endl;
	cout << "'                PROXIMO TURNO: JAVIER                    '" << endl;
	cout << "'                                                         '" << endl;
	cout << "'               PUNTAJE MARTA: 70 PUNTOS                  '" << endl;
	cout << "'                                                         '" << endl;
	cout << "'               PUNTAJE JAVIER: 70 PUNTOS                 '" << endl;
	cout << "'                                                         '" << endl;
	cout << "'- - - - - - - - - - - - - - - - - - - - - - - - - - - - -'" << endl;

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

void mostrarMaxPuntuacion(string usuarioMaxPuntuacion, int maxPuntuacion) {
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "                                                           " << endl;
	cout << "                   MAXIMA PUNTUACION                       " << endl;
	cout << "                                                           " << endl;
	cout << "              JUGADOR: "<< usuarioMaxPuntuacion<< endl;
	cout << "                                                           " << endl;
	cout << "              PUNTOS: " << maxPuntuacion << "PUNTOS" << endl;
	cout << "                                                           " << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}

void jugar(int PUNTAJE_OBJETIVO, int LANZAMIENTOS_POR_RONDA, int CANTIDAD_DADOS, int vDados[]) {
	string nombreJugador;
	pedirNombre(nombreJugador);

	int puntajeTotal = 0, ronda = 1; //Inicialización de variables
	int puntajeLanzamiento;

	//CICLO DE RONDAS
	while (puntajeTotal < PUNTAJE_OBJETIVO) {
		int maxPuntajeRonda = 0;
		system("cls");

		//CICLO DE LANZAMIENTOS DE DADOS
		for (int i = 0; i < LANZAMIENTOS_POR_RONDA; i++) {
			tirarDados(vDados, CANTIDAD_DADOS);
			puntajeLanzamiento = calcularPuntos(vDados, CANTIDAD_DADOS, PUNTAJE_OBJETIVO);

			if (puntajeLanzamiento == PUNTAJE_OBJETIVO) { //Si hay escalera, gana la partida
				maxPuntajeRonda = puntajeLanzamiento;
				mostrarInterfazTurno(nombreJugador, ronda, puntajeTotal, maxPuntajeRonda, i + 1);
				mostrarDados(vDados, CANTIDAD_DADOS);
				cout << "\n¡ESCALERA! !GANASTE LA PARTIDA¡" << endl;
				break; //Sale del ciclo for
			}
			else if (puntajeLanzamiento == 0) { //Si hay seis 6, resetea el puntaje a 0
				maxPuntajeRonda = puntajeLanzamiento;
				puntajeTotal = 0;
				mostrarInterfazTurno(nombreJugador, ronda, puntajeTotal, maxPuntajeRonda, i + 1);
				mostrarDados(vDados, CANTIDAD_DADOS);
				cout << "\nSEIS DE SEIS! TU PUNTAJE TOTAL FUE REINICIADO A CERO!\n" << endl;
				system("pause");
				continue; //Pasa a la siguiente iteración
			}
			else if (puntajeLanzamiento > maxPuntajeRonda)
				maxPuntajeRonda = puntajeLanzamiento;

			mostrarInterfazTurno(nombreJugador, ronda, puntajeTotal, maxPuntajeRonda, i + 1);
			mostrarDados(vDados, CANTIDAD_DADOS);

			system("pause");
		}
		puntajeTotal += maxPuntajeRonda;
		cout << "\nFIN DE LA RONDA NRO. " << ronda << "  |  PUNTAJE SUMADO: " << maxPuntajeRonda << endl;
		ronda++;
		system("pause");
	}

	cout << "\nFELICIDADES " << nombreJugador << "! GANASTE LA PARTIDA!" << endl;
	cout << "PUNTAJE FINAL: " << puntajeTotal << endl;
}

#endif // FUNCIONES_H_INCLUDED

