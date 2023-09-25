#include <iostream>
using namespace std;

const int TAMANO_MATRIZ = 8;

void impr_Mat(int **mat, int v);

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
        }
    }

    cout << "Patrón ingresado:" << endl;
            imprimirMatriz(matriz);
}

// Función para mostrar patrones
void mostrarPatrones() {
    int opcion_patron;
    int n = 8; // Número de filas y columnas en el patrón
    int **matriz = new int *[n];

    for (int k = 0; k < n; k++) {
        matriz[k] = new int[n];
    }

    cout << "Menú Patrones:" << endl;
                cout << "1. Mostrar Patrón 1" << endl;
                cout << "2. Mostrar Patrón 2" << endl;
                cout << "Ingrese su opción: ";
            cin >> opcion_patron;

    // Descartar el carácter de nueva línea del búfer
    cin.ignore();

    switch (opcion_patron) {
    case 1: {
        // Generar Patrón 1
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                if (j >= n / 2 - 1 - i && j <= n / 2 + i) {
                    matriz[i][j] = 1;
                } else {
                    matriz[i][j] = 0;
                }
            }
        }

        // Espejo de la matriz 1_4 eje vertical
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                matriz[i][j + n / 2] = matriz[i][n / 2 - 1 - j];
            }
        }

        // Espejo de la matriz 1_2 eje horizontal
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n; j++) {
                matriz[i + n / 2][j] = matriz[n / 2 - 1 - i][j];
            }
        }

        impr_Mat(matriz, n);

        break;
    }
    case 2: {
        // Generar Patrón 2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j || i + j == n - 1) {
                    matriz[i][j] = 1;
                } else {
                    matriz[i][j] = 0;
                }
            }
        }

        impr_Mat(matriz, n);

        break;
    }
    default:
        cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
            break;
    }

    // Liberar la memoria de la matriz
    for (int i = 0; i < n; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

// Función para imprimir matriz cuadrada
void impr_Mat(int **mat, int v) {
    cout << "Matriz : " << endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
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
    cout << "3. Mostrar patrones" << endl;
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
        mostrarPatrones();
        break;
    default:
        cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
            break;
    }
}
