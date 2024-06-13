#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include "funciones.h"
#include "constantes.h"
using namespace std;

void menu();

void menu() {
    int opcion;
    int vDados[6] = { 0 };

    string nombreJugador[2] = {};

    while (true) {
        system("cls");
        cout << "----------MENU PRINCIPAL----------" << endl;
        cout << endl;
        cout << "1- SOLITARIO" << endl;
        cout << "2- DUELO" << endl;
        cout << "----------------------------------" << endl;
        cout << "3- PUNTUACION MAS ALTA" << endl;
        cout << "0- SALIR" << endl;
        cout << endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            jugar(nombreJugador, opcion, PUNTAJE_OBJETIVO, LANZAMIENTOS_POR_RONDA, CANTIDAD_DADOS, vDados);
            break;

        case 2:
            jugar(nombreJugador, opcion, PUNTAJE_OBJETIVO, LANZAMIENTOS_POR_RONDA, CANTIDAD_DADOS, vDados);
            break;

        case 3:
            
            break;

        case 0:

            return;

        default:
            cout << "OPCION INEXISTENTE, PUEBE DE NUEVO" << endl;
            system("pause");

        }
    }
}


#endif // MENU_H_INCLUDED
