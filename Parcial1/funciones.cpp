#include <iostream>
using namespace std;

const int TAMANO_MATRIZ = 8;

// Función para imprimir la matriz de LEDs
void imprimirMatriz(int matriz[TAMANO_MATRIZ][TAMANO_MATRIZ]) {
    for (int i = 0; i < TAMANO_MATRIZ; i++) {
        for (int j = 0; j < TAMANO_MATRIZ; j++) {
            cout << matriz[i][j] << " ";  // Imprimir el valor (0 o 1)
        }
        cout << endl;
    }
    cout << endl;
}

// Función para generar y mostrar la matriz
void generarMatriz(int matriz[TAMANO_MATRIZ][TAMANO_MATRIZ]) {
    // Inicializar la matriz con todos los LEDs apagados
    for (int i = 0; i < TAMANO_MATRIZ; i++) {
        for (int j = 0; j < TAMANO_MATRIZ; j++) {
            matriz[i][j] = 0;
        }
    }

    cout << "Matriz generada:" << endl;
    imprimirMatriz(matriz);
}

// Función para realizar la verificación de los LEDs
void verificacion(int duracion_segundos, int repeticiones) {
    int matriz[TAMANO_MATRIZ][TAMANO_MATRIZ] = {{0}};  // Inicializar la matriz con todos los LEDs apagados

    cout << "Iniciando verificación de LEDs..." << endl;

        for (int r = 0; r < repeticiones; r++) {
        // Encender todos los LEDs
        for (int i = 0; i < TAMANO_MATRIZ; i++) {
            for (int j = 0; j < TAMANO_MATRIZ; j++) {
                matriz[i][j] = 1;  // 1 representa encendido
            }
        }

        // Imprimir la matriz
        imprimirMatriz(matriz);

        // Esperar la duración especificada en segundos
        for (int i = 0; i < duracion_segundos; i++) {
        }

        // Apagar todos los LEDs
        for (int i = 0; i < TAMANO_MATRIZ; i++) {
            for (int j = 0; j < TAMANO_MATRIZ; j++) {
                matriz[i][j] = 0;  // 0 representa apagado
            }
        }

        // Imprimir la matriz
        imprimirMatriz(matriz);

        // Esperar la duración especificada en segundos
        for (int i = 0; i < duracion_segundos; i++) {
            // Puedes agregar alguna lógica adicional si lo deseas
        }
    }

    cout << "Verificación completa." << endl;
}


// Función para permitir al usuario ingresar un patrón personalizado en la matriz de LEDs por filas
void imagen(int matriz[TAMANO_MATRIZ][TAMANO_MATRIZ]) {
    cout << "Ingrese el patrón en la matriz de LEDs (0 para apagado, 1 para encendido) por filas." << endl;

        for (int i = 0; i < TAMANO_MATRIZ; i++) {
        cout << "Fila " << i + 1 << ": ";
        for (int j = 0; j < TAMANO_MATRIZ; j++) {
            if (!(cin >> matriz[i][j])) {
                matriz[i][j] = 0; // Si no se ingresan más números, asumir 0
            }
            cin.ignore();  // Descartar el carácter de nueva línea
        }
    }

    cout << "Patrón ingresado:" << endl;
            imprimirMatriz(matriz);
}
// Función para manejar las opciones de Publik
void publik() {
            int opcion_publik;
            int duracion_segundos;
            int repeticiones;
            int matriz[TAMANO_MATRIZ][TAMANO_MATRIZ] = {{0}};  // Inicializar la matriz con todos los LEDs apagados

            cout << "Menú Publik:" << endl;
                    cout << "1. Verificar funcionamiento de LEDs" << endl;
            cout << "2. Mostrar imagen de prueba" << endl;
            cout << "3. Mostrar patrones 1 al 4 de forma alternada" << endl;
            cout << "Ingrese su opción: ";
                    cin >> opcion_publik;

            // Descartar el carácter de nueva línea del búfer
            cin.ignore();

            switch (opcion_publik) {
            case 1:
        cout << "Ingrese el número de repeticiones para la verificación: ";
        cin >> repeticiones;
        cout << "Ingrese la duración en segundos para cada encendido y apagado de LEDs: ";
                cin >> duracion_segundos;
        verificacion(duracion_segundos, repeticiones);
        break;
            case 2:
        imagen(matriz);
        break;
            case 3:
        // Este caso está vacío, no realiza ninguna acción
        break;
            default:
        cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
            break;
            }
}
