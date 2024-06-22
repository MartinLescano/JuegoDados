#pragma once

void menu();

void menu() {
    int opcion;
    int vDados[6] = { 0 };

    string usuarioMaxPuntuacion = "???";
    int maxPuntuacion = 0;

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
        cout << "----------------------------------" << endl;
        cout << endl;
        cout << "INGRESE OPCION: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            jugarSolo(PUNTAJE_OBJETIVO, LANZAMIENTOS_POR_RONDA, CANTIDAD_DADOS, vDados, usuarioMaxPuntuacion, maxPuntuacion, MODO_SIMULADO);
            break;

        case 2:
            jugarDuo(PUNTAJE_OBJETIVO, LANZAMIENTOS_POR_RONDA, CANTIDAD_DADOS, vDados, usuarioMaxPuntuacion, maxPuntuacion, MODO_SIMULADO);
            break;

        case 3:
            mostrarMaxPuntuacion(usuarioMaxPuntuacion, maxPuntuacion);
            break;
        case 0:

            return;

        default:
            cout << "OPCION INEXISTENTE, PRUEBE DE NUEVO" << endl;
            system("pause");

        }
    }
}

