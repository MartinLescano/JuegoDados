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
    string usuarioMaxPuntuacion = "???";
    int maxPuntuacion=0;

    while (true) {
        system("cls");
        cout << "----------MENU PRINCIPAL----------" << endl;
        cout << endl;
        cout << "1- SOLITARIO" << endl;
        cout << "2- DUELO" << endl;
        cout << "----------------------------------" << endl;
        cout << "3- PUNTUACION MAS ALTA" << endl;
        //      "4-MODO SIMULADO
        cout << "0- SALIR" << endl;
        cout << endl;
        cout << "----------------------------------" << endl;
        cout << endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            jugar(nombreJugador, opcion, PUNTAJE_OBJETIVO, LANZAMIENTOS_POR_RONDA, CANTIDAD_DADOS, vDados, usuarioMaxPuntuacion, maxPuntuacion);
            break;

        case 2:
            jugar(nombreJugador, opcion, PUNTAJE_OBJETIVO, LANZAMIENTOS_POR_RONDA, CANTIDAD_DADOS, vDados, usuarioMaxPuntuacion, maxPuntuacion);
            break;

        case 3:
            mostrarMaxPuntuacion(usuarioMaxPuntuacion, maxPuntuacion);
            break;
        case 4:
            jugarSimulado(nombreJugador, opcion, PUNTAJE_OBJETIVO, LANZAMIENTOS_POR_RONDA, CANTIDAD_DADOS, vDados);
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
