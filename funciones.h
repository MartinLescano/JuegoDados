#pragma once

//DECLARACION DE FUNCIONES

void pedirNombre(string nombreJugador[], int tam); //Asigna los nombres ingresados a un vector

void tirarDados(int vDados[], int tam); //Carga un vector de un tamaño especificado con numeros aleatorios 1-6, recibe una constante por valor de la cantidad de lanzamientos por turno

void mostrarDados(int vDados[], int tam); //Muestra los valores obtenidos

void mostrarDado(int valor);

int calcularPuntos(int vDados[], int tam, int PUNTAJEOBJETIVO); // Devuelve los maxPuntuacion segun las combinaciones de los dados

void mostrarInterfazTurno(string usuario, int ronda, int puntajeTotal, int maxPuntajeRonda, int nroLanzamiento); // Muestra la interfaz de usuario durante los lanzamientos

void mostrarInterfazEntreTurno(int ronda, string nombre[], int indice, int vPuntajeTotal[]);

int sumarDados(int vDados[]);

void ordenarDados(int vDados[], int tam);

bool escalera(int vDados[], int tam);

bool seisDeSeis(int vDados[]);

bool seisIguales(int vDados[]);

void copiarTirarDados(int vDados[], int vDados2[], int tam);//Copia la funcion tirar dados

void jugarSolo(int PUNTAJE_OBJETIVO, int LANZAMIENTOS_POR_RONDA, int CANTIDAD_DADOS, int vDados[], string& usuarioMaxPuntuacion, int& maxPuntuacion, bool MODO_SIMULADO);

void jugarDuo(int PUNTAJE_OBJETIVO, int LANZAMIENTOS_POR_RONDA, int CANTIDAD_DADOS, int vDados[], string& usuarioMaxPuntuacion, int& maxPuntuacion, bool MODO_SIMULADO);

void mostrarMaxPuntuacion(string usuarioMaxPuntuacion, int maxPuntuacion); // Muestra la puntuacion maxima lograda y el usuario correspondiente

void guardarMaxPuntuacion(int vPuntajeTotal[], int tam, string nombreJugador[], string& usuarioMaxPuntuacion, int& maxPuntuacion);//Guarda el usuario y la maxima puntuacion

bool evaluarCienPuntos(int vPuntajeTotal[], int tam, int PUNTAJE_OBJETIVO);//Evalua si se llegó al puntaje objetivo

int hallarIndiceGanador(int vPuntajeTotal[], int tam, int contadorLanzamiento[]); //Devuelve el indice del jugador ganador, en caso de empate devuelve -1

int menorLanzamiento(int contadorLanzamiento[]);

void desempatar(int PUNTAJE_OBJETIVO, int CANTIDAD_DADOS, int vDados[], string& usuarioMaxPuntuacion, int& maxPuntuacion, bool MODO_SIMULADO, string nombreJugador[], int vPuntajeTotal[], int& ronda);

//IMPLEMENTACION DE FUNCIONES

void pedirNombre(string nombreJugador[], int tam) {
    cin.ignore();
    for (int i = 0; i < tam; i++)
    {
        cout << "Ingresar nombre para Jugador " << i + 1 << ": ";
        getline(cin, nombreJugador[i]);
    }
}

void tirarDados(int vDados[], int tam) {
    for (int i = 0; i < tam; i++) {
        vDados[i] = (rand() % 6) + 1;
    }
}

void tirarDadosSimulado(int vDados[], int tam) {
    system("cls");
    cout << "MODO SIMULADO (DESACTIVAR DESDE 'constantes.h')\nINGRESAR VALORES MANUALMENTE" << endl;

    for (int i = 0; i < tam; i++) {
        cout << "Dado " << i + 1 << ": ";
        cin >> vDados[i];
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

void mostrarInterfazEntreTurno(int ronda, string nombre[], int indice, int vPuntajeTotal[]) {
    cout << "*-----------------------------------------*" << endl;
    cout << "              RONDA N° " << ronda << endl;
    cout << "        PROXIMO TURNO: " << nombre[indice] << endl;
    cout << endl;
    cout << "        PUNTAJE " << nombre[0] << ": " << vPuntajeTotal[0] << " PUNTOS" << endl;
    cout << "        PUNTAJE " << nombre[1] << ": " << vPuntajeTotal[1] << " PUNTOS" << endl;
    cout << endl;
    cout << "*------------------**---------------------*" << endl;
    system("pause");
    system("cls");
}

void mostrarDado(int valor) {
    switch (valor)
    {

    case 1:
        rlutil::setColor(rlutil::BLACK);
        rlutil::setBackgroundColor(rlutil::WHITE);
        cout << "     " << endl;
        cout << "  o  " << endl;
        cout << "     " << endl;

        break;
    case 2:
        rlutil::setColor(rlutil::BLACK);
        rlutil::setBackgroundColor(rlutil::WHITE);
        cout << " o   " << endl;
        cout << "     " << endl;
        cout << "   o " << endl;

        break;
    case 3:
        rlutil::setColor(rlutil::BLACK);
        rlutil::setBackgroundColor(rlutil::WHITE);
        cout << " o   " << endl;
        cout << "  o  " << endl;
        cout << "   o " << endl;

        break;
    case 4:
        rlutil::setColor(rlutil::BLACK);
        rlutil::setBackgroundColor(rlutil::WHITE);
        cout << " o o " << endl;
        cout << "     " << endl;
        cout << " o o " << endl;

        break;
    case 5:
        rlutil::setColor(rlutil::BLACK);
        rlutil::setBackgroundColor(rlutil::WHITE);
        cout << " o o " << endl;
        cout << "  o  " << endl;
        cout << " o o " << endl;


        break;
    case 6:
        rlutil::setColor(rlutil::BLACK);
        rlutil::setBackgroundColor(rlutil::WHITE);
        cout << " o o " << endl;
        cout << " o o " << endl;
        cout << " o o " << endl;

        break;
    default:
        cout << "Error: valor de dado no válido." << endl;
    }
}

void mostrarDados(int vDados[], int CANTIDAD_DADOS) {
    for (int i = 0; i < CANTIDAD_DADOS; i++)
    {
        mostrarDado(vDados[i]);
        cout << endl;
    }
    rlutil::setColor(rlutil::WHITE);
    rlutil::setBackgroundColor(rlutil::BLACK);
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

void copiarTirarDados(int vDados[], int vDados2[], int tam) {
    int i;
    for (i = 0; i < tam; i++)
    {
        vDados2[i] = vDados[i];
    }
}

void mostrarMaxPuntuacion(string usuarioMaxPuntuacion, int maxPuntuacion) {

    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << "                                                           " << endl;
    cout << "                   MAXIMA PUNTUACION                       " << endl;
    cout << "                                                           " << endl;
    cout << "              JUGADOR: " << usuarioMaxPuntuacion << endl;
    cout << "                                                           " << endl;
    cout << "              PUNTOS: " << maxPuntuacion << " PUNTOS" << endl;
    cout << "                                                           " << endl;
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    system("pause");
    system("cls");
}

bool evaluarCienPuntos(int vPuntajeTotal[], int tam, int PUNTAJE_OBJETIVO) {
    for (int i = 0; i < tam; i++) {
        if (vPuntajeTotal[i] >= PUNTAJE_OBJETIVO) {
            return true;
        }
    }
    return false;
}

void guardarMaxPuntuacion(int vPuntajeTotal[], int tam, string nombreJugador[], string& usuarioMaxPuntuacion, int& maxPuntuacion) {
    bool record = false;
    for (int i = 0; i < tam; i++) {
        if (vPuntajeTotal[i] > maxPuntuacion) {
            record = true; //Si hay nueva puntuacion maxima, asigna true a la variable. Si mas de un jugador supera el record, no hace cout en cada iteracion, solo la mas alta
            maxPuntuacion = vPuntajeTotal[i];
            usuarioMaxPuntuacion = nombreJugador[i];
        }
    }

    if (record) {
        cout << "\nNUEVA PUNTUACION MAXIMA!\n" << endl;
    }
}

void jugarSolo(int PUNTAJE_OBJETIVO, int LANZAMIENTOS_POR_RONDA, int CANTIDAD_DADOS, int vDados[], string& usuarioMaxPuntuacion, int& maxPuntuacion, bool MODO_SIMULADO) {

    int ronda = 1; //Inicialización de variables
    int puntajeLanzamiento;

    string nombreJugador[1];
    pedirNombre(nombreJugador, 1);

    //A CADA JUGADOR LE CORRESPONDE UN INDICE DE MAXIMO PUNTAJE Y DE TOTAL
    int vMaxPuntajeRonda[1] = { 0 }, vPuntajeTotal[2] = { 0 };

    //CICLO DE RONDAS
    while (vPuntajeTotal[0] < PUNTAJE_OBJETIVO) {

        // Resetea el maximo puntaje de la ronda finalizada.
        vMaxPuntajeRonda[0] = 0;
        system("cls");

        //CICLO DE LANZAMIENTOS DE DADOS
        for (int i = 0; i < LANZAMIENTOS_POR_RONDA; i++) {

            if (MODO_SIMULADO)
                tirarDadosSimulado(vDados, CANTIDAD_DADOS);
            else
                tirarDados(vDados, CANTIDAD_DADOS);

            puntajeLanzamiento = calcularPuntos(vDados, CANTIDAD_DADOS, PUNTAJE_OBJETIVO);

            if (puntajeLanzamiento == PUNTAJE_OBJETIVO) { //Si hay escalera, gana la partida
                vMaxPuntajeRonda[0] = puntajeLanzamiento;
                mostrarInterfazTurno(nombreJugador[0], ronda, vPuntajeTotal[0], vMaxPuntajeRonda[0], i + 1);
                mostrarDados(vDados, CANTIDAD_DADOS);
                cout << "\n¡ESCALERA!\n" << endl;
                system("pause");
                system("cls");
                break; //Sale del ciclo for
            }
            else if (puntajeLanzamiento == 0) { //Si hay seis 6, resetea el puntaje a 0
                vMaxPuntajeRonda[0] = puntajeLanzamiento;
                vPuntajeTotal[0] = 0;
                mostrarInterfazTurno(nombreJugador[0], ronda, vPuntajeTotal[0], vMaxPuntajeRonda[0], i + 1);
                mostrarDados(vDados, CANTIDAD_DADOS);
                cout << "\nSEIS DE SEIS! TU PUNTAJE TOTAL FUE REINICIADO A CERO!\n" << endl;
                system("pause");
                system("cls");
                continue; //Pasa a la siguiente iteracion
            }
            else if (puntajeLanzamiento > vMaxPuntajeRonda[0])
                vMaxPuntajeRonda[0] = puntajeLanzamiento;

            mostrarInterfazTurno(nombreJugador[0], ronda, vPuntajeTotal[0], vMaxPuntajeRonda[0], i + 1);
            mostrarDados(vDados, CANTIDAD_DADOS);
            system("pause");
        }

        //Termina la ronda y asigna al total de cada jugador el mayor puntaje obtenido en la ronda.
        vPuntajeTotal[0] += vMaxPuntajeRonda[0];

        cout << "\nFIN DE LA RONDA NRO. " << ronda << "  |  PUNTAJE SUMADO: " << vMaxPuntajeRonda[0] << endl;
        ronda++;
        system("pause");
    }

    cout << "*-------------------------------------------------------------------*" << endl;
    cout << "     ¡FELICIDADES " << nombreJugador[0] << ", GANASTE LA PARTIDA!" << endl;
    cout << endl;
    cout << "      PUNTAJE FINAL: " << vPuntajeTotal[0] << endl;
    cout << endl;
    cout << "*---------------------------------------------------------------*" << endl;

    guardarMaxPuntuacion(vPuntajeTotal, 1, nombreJugador, usuarioMaxPuntuacion, maxPuntuacion);
    system("pause");
}



void jugarDuo(int PUNTAJE_OBJETIVO, int LANZAMIENTOS_POR_RONDA, int CANTIDAD_DADOS, int vDados[], string& usuarioMaxPuntuacion, int& maxPuntuacion, bool MODO_SIMULADO) {

    int ronda = 1, indiceGanador; //Inicialización de variables
    int puntajeLanzamiento;
    int contadorLanzamiento[2] = {0};
    int mayorPuntajeAcumulado = 0;

    //SETEAR UN MAXIMO DE RONDAS (OPCIONAL)
    int maxRondas;
    cout << "Ingresar cantidad de rondas (0 sin limite): ";
    cin >> maxRondas;
    system("cls");

    string nombreJugador[2];
    pedirNombre(nombreJugador, 2);

    //A CADA JUGADOR LE CORRESPONDE UN INDICE DE MAXIMO PUNTAJE Y DE TOTAL
    int vMaxPuntajeRonda[2] = { 0 }, vPuntajeTotal[2] = { 0 };


    //CICLO DE RONDAS
    //Mientras ningun jugador alcance la puntuacion objetivo, sigue la partida.
    while (!evaluarCienPuntos(vPuntajeTotal, 2, PUNTAJE_OBJETIVO) && (ronda <= maxRondas || maxRondas == 0)) {

        // Resetea el maximo puntaje de la ronda finalizada.
        for (int i = 0; i < 2; i++) {
            vMaxPuntajeRonda[i] = 0;
            contadorLanzamiento[i] = 0;
        }
        

        system("cls");

        //CICLO DE CAMBIO DE JUGADOR
        for (int j = 0; j < 2; j++) {
            mostrarInterfazEntreTurno(ronda, nombreJugador, j, vPuntajeTotal);

            mayorPuntajeAcumulado = 0;

            //CICLO DE LANZAMIENTOS DE DADOS
            for (int i = 0; i < LANZAMIENTOS_POR_RONDA; i++) {


                if (MODO_SIMULADO)
                    tirarDadosSimulado(vDados, CANTIDAD_DADOS);
                else
                    tirarDados(vDados, CANTIDAD_DADOS);

                puntajeLanzamiento = calcularPuntos(vDados, CANTIDAD_DADOS, PUNTAJE_OBJETIVO);

                if (puntajeLanzamiento == PUNTAJE_OBJETIVO) { //Si hay escalera, gana la partida
                    vMaxPuntajeRonda[j] = puntajeLanzamiento;
                    mostrarInterfazTurno(nombreJugador[j], ronda, vPuntajeTotal[j], vMaxPuntajeRonda[j], i + 1);
                    mostrarDados(vDados, CANTIDAD_DADOS);
                    cout << "\nESCALERA!" << endl;
                    vPuntajeTotal[j] += PUNTAJE_OBJETIVO;
                    system("pause");
                    system("cls");

                    //PANTALLA DE GANADOR
                    cout << "*---------------------------------------------------------------*" << endl;
                    cout << "     ¡FELICIDADES " << nombreJugador[j] << ", GANASTE LA PARTIDA!" << endl;
                    cout << endl;
                    cout << "      PUNTAJE FINAL" << endl << endl;
                    cout << "      " << nombreJugador[0] << ": " << vPuntajeTotal[0] << endl;
                    cout << "      " << nombreJugador[1] << ": " << vPuntajeTotal[1] << endl;
                    cout << endl;
                    cout << "*---------------------------------------------------------------*" << endl;

                    guardarMaxPuntuacion(vPuntajeTotal, 2, nombreJugador, usuarioMaxPuntuacion, maxPuntuacion);
                    system("pause");
                    return; //Termina la partida y vuelve al menu
                }
                else if (puntajeLanzamiento == 0) { //Si hay seis 6, resetea el puntaje a 0
                    vMaxPuntajeRonda[j] = puntajeLanzamiento;
                    vPuntajeTotal[j] = 0;
                    mostrarInterfazTurno(nombreJugador[j], ronda, vPuntajeTotal[j], vMaxPuntajeRonda[j], i + 1);
                    mostrarDados(vDados, CANTIDAD_DADOS);
                    cout << "\nSEIS DE SEIS! TU PUNTAJE TOTAL FUE REINICIADO A CERO!\n" << endl;
                    system("pause");
                    system("cls");
                    continue; //Pasa a la siguiente iteraci≤n
                }
                else if (puntajeLanzamiento > vMaxPuntajeRonda[j]) {
                    vMaxPuntajeRonda[j] = puntajeLanzamiento;
                }
                mostrarInterfazTurno(nombreJugador[j], ronda, vPuntajeTotal[j], vMaxPuntajeRonda[j], i + 1);
                mostrarDados(vDados, CANTIDAD_DADOS);

                if ((puntajeLanzamiento + vPuntajeTotal[j]) > mayorPuntajeAcumulado){
                    contadorLanzamiento[j] = i+1;
                }
                mayorPuntajeAcumulado = vPuntajeTotal[j] + vMaxPuntajeRonda[j];

                system("pause");
                system("cls");

            } //Acá itera los tres lanzamientos


        //Termina el turno y asigna al total de cada jugador el mayor puntaje obtenido en la ronda.
            vPuntajeTotal[j] += vMaxPuntajeRonda[j];

        } //Acá itera entre los dos jugadores.

        ronda++;
    }

    //DETERMINAR EL GANADOR
    indiceGanador = hallarIndiceGanador(vPuntajeTotal, 2, contadorLanzamiento);

    if (indiceGanador != -1) { //Si no hay empate
        //PANTALLA DE GANADOR
        cout << "*---------------------------------------------------------------*" << endl;
        cout << "     ¡FELICIDADES " << nombreJugador[indiceGanador] << ", GANASTE LA PARTIDA!" << endl;
        cout << endl;
        cout << "      PUNTAJE FINAL" << endl << endl;
        cout << "      " << nombreJugador[0] << ": " << vPuntajeTotal[0] << endl;
        cout << "      " << nombreJugador[1] << ": " << vPuntajeTotal[1] << endl;
        cout << endl;
        cout << "*---------------------------------------------------------------*" << endl;
    }
    else
    {
        cout << "*------------------------------------------*" << endl;
        cout << endl;
        cout << "                 ¡EMPATE!" << endl;
        cout << endl;
        cout << "    "<<nombreJugador[0] << ": " << vPuntajeTotal[0] << endl;
        cout << "    "<<nombreJugador[1] << ": " << vPuntajeTotal[1] << endl;
        cout << endl;
        cout << "    CONTINUAR LANZANDO UNA VEZ CADA UNO" << endl;
        cout << endl;
        cout << "*------------------------------------------*" << endl;
        system("pause");
        system("cls");

        desempatar(PUNTAJE_OBJETIVO, CANTIDAD_DADOS, vDados, usuarioMaxPuntuacion, maxPuntuacion, MODO_SIMULADO, nombreJugador, vPuntajeTotal, ronda);
    }


    guardarMaxPuntuacion(vPuntajeTotal, 2, nombreJugador, usuarioMaxPuntuacion, maxPuntuacion);
    system("pause");

}

int hallarIndiceGanador(int vPuntajeTotal[], int tam, int contadorLanzamiento[]) {
    if (vPuntajeTotal[0] > vPuntajeTotal[1])
    {
        return 0;
    }
    else if (vPuntajeTotal[1] > vPuntajeTotal[0])
    {
        return 1;
    }
    else if (vPuntajeTotal[0] == vPuntajeTotal[1])
    {
        return menorLanzamiento(contadorLanzamiento);
    }
}

int menorLanzamiento(int contadorLanzamiento[]) {

    //Retorna el índice del jugador con menos lanzamientos al llegar a 100
    if (contadorLanzamiento[0] < contadorLanzamiento[1]) {
        return 0;
    }
    else if (contadorLanzamiento[0] > contadorLanzamiento[1])
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void desempatar(int PUNTAJE_OBJETIVO, int CANTIDAD_DADOS, int vDados[], string& usuarioMaxPuntuacion, int& maxPuntuacion, bool MODO_SIMULADO, string nombreJugador[], int vPuntajeTotal[], int& ronda) {
    int indiceGanador; //Inicialización de variables
    int puntajeLanzamiento;
    int contadorLanzamiento[2] = { 0 };

    //A CADA JUGADOR LE CORRESPONDE UN INDICE DE MAXIMO PUNTAJE Y DE TOTAL
    int vMaxPuntajeRonda[2] = { 0 };
    
    //CICLO DE RONDAS
    //Mientras sigan empatados, sigue la partida.
    while (vPuntajeTotal[0] == vPuntajeTotal[1]) {

        // Resetea el maximo puntaje de la ronda finalizada.
        for (int i = 0; i < 2; i++) {
            vMaxPuntajeRonda[i] = 0;
        }


        system("cls");

        //CICLO DE CAMBIO DE JUGADOR
        for (int j = 0; j < 2; j++) {
            mostrarInterfazEntreTurno(ronda, nombreJugador, j, vPuntajeTotal);

            //CICLO DE LANZAMIENTOS DE DADOS
            if (MODO_SIMULADO)
                tirarDadosSimulado(vDados, CANTIDAD_DADOS);
            else
                tirarDados(vDados, CANTIDAD_DADOS);

            puntajeLanzamiento = calcularPuntos(vDados, CANTIDAD_DADOS, PUNTAJE_OBJETIVO);

            if (puntajeLanzamiento == PUNTAJE_OBJETIVO) { //Si hay escalera, gana la partida
                vMaxPuntajeRonda[j] = puntajeLanzamiento;
                mostrarInterfazTurno(nombreJugador[j], ronda, vPuntajeTotal[j], vMaxPuntajeRonda[j], 1);
                mostrarDados(vDados, CANTIDAD_DADOS);
                cout << "\nESCALERA!\n" << endl;
                vPuntajeTotal[j] += PUNTAJE_OBJETIVO;
                system("pause");
                system("cls");

                //PANTALLA DE GANADOR
                cout << "*---------------------------------------------------------------*" << endl;
                cout << "     ¡FELICIDADES " << nombreJugador[j] << ", GANASTE LA PARTIDA!" << endl;
                cout << endl;
                cout << "      PUNTAJE FINAL" << endl << endl;
                cout << "      " << nombreJugador[0] << ": " << vPuntajeTotal[0] << endl;
                cout << "      " << nombreJugador[1] << ": " << vPuntajeTotal[1] << endl;
                cout << endl;
                cout << "*---------------------------------------------------------------*" << endl;
                guardarMaxPuntuacion(vPuntajeTotal, 2, nombreJugador, usuarioMaxPuntuacion, maxPuntuacion);
                system("pause");
                system("cls");
                return; //Termina la partida y vuelve al menu
            }
            else if (puntajeLanzamiento == 0) { //Si hay seis 6, resetea el puntaje a 0
                vMaxPuntajeRonda[j] = puntajeLanzamiento;
                vPuntajeTotal[j] = 0;
                mostrarInterfazTurno(nombreJugador[j], ronda, vPuntajeTotal[j], vMaxPuntajeRonda[j], 1);
                mostrarDados(vDados, CANTIDAD_DADOS);
                cout << "\nSEIS DE SEIS! TU PUNTAJE TOTAL FUE REINICIADO A CERO!\n" << endl;
                system("pause");
                system("cls");
                continue; //Pasa a la siguiente iteracion
            }
            else if (puntajeLanzamiento > vMaxPuntajeRonda[j]) {
                vMaxPuntajeRonda[j] = puntajeLanzamiento;
            }
            mostrarInterfazTurno(nombreJugador[j], ronda, vPuntajeTotal[j], vMaxPuntajeRonda[j], 1);
            mostrarDados(vDados, CANTIDAD_DADOS);

            system("pause");
            system("cls");

            vPuntajeTotal[j] += vMaxPuntajeRonda[j];
        }

        ronda++;
    }

    //DETERMINAR EL GANADOR
    indiceGanador = hallarIndiceGanador(vPuntajeTotal, 2, contadorLanzamiento);

    if (indiceGanador != -1) {
        //PANTALLA DE GANADOR
        cout << "*---------------------------------------------------------------*" << endl;
        cout << "     ¡FELICIDADES " << nombreJugador[indiceGanador] << ", GANASTE LA PARTIDA!" << endl;
        cout << endl;
        cout << "      PUNTAJE FINAL" << endl << endl;
        cout << "      " << nombreJugador[0] << ": " << vPuntajeTotal[0] << endl;
        cout << "      " << nombreJugador[1] << ": " << vPuntajeTotal[1] << endl;
        cout << endl;
        cout << "*---------------------------------------------------------------*" << endl;
    }

}


