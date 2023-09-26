#include <iostream>
using namespace std;
#include "funciones.h"

int main() {
    int opcion;

    do {
        cout << "Menu:" << endl;
                cout << "1. Publik" << endl;
        cout << "2. Salir" << endl;
        cout << "Ingrese su opcion: ";
                cin >> opcion;



        switch (opcion) {
        case 1:
            publik();
            break;
        case 2:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opcion no valida. Por favor, ingrese una opcion valida." << endl;
                break;
        }

    } while (opcion != 2);

    return 0;
}

