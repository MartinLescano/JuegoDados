#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>

using namespace std;

//DECLARACION DE FUNCIONES

void pedirNombre(string& nombre); //Asigna el nombre ingresado a una variable por referencia

void tirarDados(int vDados[], int tam); //Carga un vector de un tamaño especificado con numeros aleatorios 1-6, recibe una constante por valor de la cantidad de lanzamientos por turno

void mostrarDados(int vDados[], int tam); //Muestra los valores obtenidos

void jugar(int puntajeObjetivo, int lanzamientosPorRonda, int cantidadDados); // Llama a las demas funciones hasta que la partida termina

void mostrarMaxPuntuacion(string usuarioMaxPuntuacion, int maxPuntuacion); // Muestra la puntuacion maxima lograda y el usuario correspondiente

int calcularPuntos(int vDados[], int tam); // Devuelve los puntos segun las combinaciones de los dados

void mostrarInterfazTurno(string usuario, int ronda, int puntajeTotal, int maxPuntajeRonda, int nroLanzamiento); // Muestra la interfaz de usuario durante los lanzamientos

void mostrarInterfazEntreTurno(string usuario, int ronda, int puntajeTotal); // Muestra la interfaz del o los usuarios entre los turnos

int sumarDados(int vDados[]);

void ordenarDados(int vDados[], int tam);

bool escalera(int vDados[], int tam);

bool seisDeSeis(int vDados[]);

bool seisIguales(int vDados[]);

int jugarSimulado(int vDados[], int tirarDadosManual, int sumarDados, int ordenarDados, int escalera, int seisDeseis, int seisIguales, int tam); //Para ver la funcionalidad de cada funcion


//IMPLEMENTACION DE FUNCIONES

void pedirNombre(string& nombre) {
	system("cls");
	cout << "Ingresar nombre del jugador: ";
	cin >> nombre;
	system("cls");
}

void tirarDados(int vDados[], int tam) {
	for (int i = 0; i < tam; i++) {
		vDados[i] = (rand() % 6) + 1;
	}
}

void mostrarInterfazTurno(string usuario, int ronda, int puntajeTotal, int maxPuntajeRonda, int nroLanzamiento) {

	cout << "TURNO DE"; cout << "  |  "; cout << "RONDA Nº"; cout << "  |  "; cout << "PUNTAJE TOTAL: " << "PUNTOS" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "MAXIMO PUNTAJE DE LA RONDA:" << "   PUNTOS" << endl;
	cout << "LANZAMIENTO Nº" << endl;
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

	ordenarDados(vDados, tam);

	int contador = 0;
	for (int i = 0; i < 6; i++)
	{
		if (vDados[i] == i + 1) {
			contador++;
		}
	}

	if (contador == 6)
	{
		//cout << "escalera";
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

int calcularPuntos(int vDados[], int tam) {
	int calculo = 0;

	if (escalera(vDados, tam)) {
		calculo = 100;
	}
	else if (seisDeSeis(vDados))
	{
		//Seis dados SEIS, devuelve 0
		calculo = 0;
	}
	else if (seisIguales(vDados))
	{
		//Seis dados IGUALES, devuelve valor repetido * 10
		calculo = vDados[0] * 10;
	}
	else
	{
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

#endif // FUNCIONES_H_INCLUDED

