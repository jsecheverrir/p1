#include <iostream>
#include "funciones.h"
using namespace std;

int main() {
    int opcion;
    int repeticiones;
    int duracion_segundos;
    int matriz[TAMANO_MATRIZ][TAMANO_MATRIZ] = {{0}};  // Inicializar la matriz con todos los LEDs apagados

    do {
        cout << "Menú:" << endl;
        cout << "1. Generar matriz e imprimir matriz" << endl;
        cout << "2. Realizar verificación de LEDs" << endl;
        cout << "3. Ingresar un patrón personalizado en la matriz" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese su opción: "<< endl;
        cin >> opcion;

        // Descartar el carácter de nueva línea del búfer
        cin.ignore();

        switch (opcion) {
            case 1:
                generarMatriz(matriz);
                break;
            case 2:
                cout << "Ingrese el número de repeticiones para la verificación: ";
                cin >> repeticiones;
                cout << "Ingrese la duración en segundos para cada encendido y apagado de LEDs: ";
                        cin >> duracion_segundos;
                verificacion(duracion_segundos, repeticiones);
                break;
            case 3:
                imagen(matriz);
                break;
            case 4:
                publik();
                break;

            case 5:
                cout << "Saliendo del programa." << endl;
                break;
        }

    } while (opcion != 5);

    return 0;
}



