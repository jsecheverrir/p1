#include <iostream>
using namespace std;
void menu();//menu
void ejecp(int);//mensaje de ejecucion
void impr_Mat(int **mat, int v);//funcion para imprimir matriz
void fila_Par(bool Matriz[8][8], int Dimension, int i);//funcion para patron 3
void fila_Impar(bool Matriz[8][8], int Dimension, int i);// funcion para  patron 3
void arriba(bool Matriz[8][8], int, int, int );//funcion para patron 4
void abajo(bool Matriz[8][8], int, int, int);//funcion para patron 4
void patron_1();//ejecuta el patron 1_
void patron_2();//ejecuta el patron 2_
void patron_3();//ejecuta el patron 3
void patron_4();//ejecuta el patron 4
int main()
{
	int opc=1;
	menu();
	
	while (opc!=0)
	{
		cin>>opc;
		cout<<" "<<endl;
			
		switch(opc) 
		{ 
	    case 1:
			ejecp(1);
			patron_1(); 
	    	break;
	    case 2:
			ejecp(2);
			patron_2();
	    	break;
	    case 3:
			ejecp(3);
			patron_3();  
	    	break;
	    case 4:
	    	ejecp(4);
			patron_4();  
	    	break;
		default:
			if (opc!=0) 
	    	cout<<"Opcion no valida"<<endl;
	    	break;
    	}	
		
	}
		
	
}

//---------------------------------------------------------------------
// Funcion que muestra el menu de seleccion
void menu()
{
	cout<<"****************************************"<<endl;
	cout<<"*           Menu de seleccion          *"<<endl;
	cout<<"****************************************"<<endl;
	
	cout<<"Patron 1: 1"<<endl;
	cout<<"Patron 2: 2"<<endl;
	cout<<"Patron 3: 3"<<endl;
	cout<<"Patron 4: 4"<<endl;
	cout<<" "<<endl;
	cout<<"0: Salir del programa"<<endl;

}

//---------------------------------------------------------------------
//funcion que calcula un numero elevado a si mismo
unsigned long long potencia(int n)
{
	unsigned long long pot=1;// n max=15 con 16 se desborda
    unsigned long long suma=0;
    for(int i=1;i<=n;i++)
		pot*=n;
	return pot;
}

//---------------------------------------------------------------------
// Funcion muetra el numero del problema que se esta ejecutando
void ejecp(int o)
{
	cout<<"Ejecutando patron "<<o<<endl;
}

//---------------------------------------------------------------------
//Funcion para imprimir matriz cuadrada
void impr_Mat(int **mat, int v){
	cout << "Matriz : " << endl;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
	}
	
}
//---------------------------------------------------------------------
//Funcion para fila par patron 3
void fila_Par(bool Matriz[8][8], int Dimension, int i) {
    int pos;
        pos = 2;
        for (int k = 0; k < Dimension; k++) {
            if (i - i + k == pos) {
                Matriz[i][k] = false;
                pos += 3;
            } else {
                Matriz[i][k] = true;
            }
        }
    }

//---------------------------------------------------------------------
//Funcion para fila impar patron 3
void fila_Impar(bool Matriz[8][8], int Dimension, int i){
        for (int k = 0; k < Dimension; k++) {
            if (i - i + k % 3 == 0) {
                Matriz[i][k] = false;
            } else {
                Matriz[i][k] = true;
            }
        }
}

//---------------------------------------------------------------------
//funcion para patron 4
void arriba(bool Matriz[8][8], int Dimension, int i, int k){
    if (k - i < 0 or  k - i > Dimension/2 - 1){
        Matriz[i][k] = false;
    }else{
        Matriz[i][k] = true;
    }
}

//---------------------------------------------------------------------
//funcion para patron 4
void abajo(bool Matriz[8][8], int Dimension, int i, int k){
    if (k+i < Dimension - 1 or k + i > Dimension + (Dimension/2) - 2){
        Matriz[i][k] = false;
    }else{
        Matriz[i][k] = true;
    }
}
/*****************************************************************
 * Funciones: Cada funcion corresponde a un patron  #            *
******************************************************************/

void patron_1()
{
    int n = 8;// Número de filas y columnas en el patrón
	int **matriz=new int*[n]; //se declara un puntero doble para una matriz
	// Se crean las filas y las columnas de una matriz
	for (int k=0; k<n;k++){
		matriz[k]=new int[n];
	}
	// genera 1_4 del patron
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            if (j >= n/2-1- i && j <= n/2 + i) {
                matriz[i][j]=1;
            } else {
                matriz[i][j]=0;
            }
        }
    }
    
	//Espejo de la matriz 1_4 eje vertical
	for(int i=0; i<n/2;i++){//recorre 4 filas
		for(int j=0;j<n/2;j++){//recorre 4 columnas
			matriz[i][j+n/2]=matriz[i][n/2-1-j];
		}
	}
	// Espejo de la matriz 1_2 eje horizontal
	for(int i=0;i<n/2;i++){//recorre n/2=4 filas
		for(int j=0; j<n; j++){//recorre las n=8 filas
			matriz[i+n/2][j]=matriz[n/2-1-i][j];
		}	
	} 

	impr_Mat(matriz, n);
	
	// Liberar la memoria de la matriz
    for (int i = 0; i < n; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
    
}
//************************************************************
void patron_2()
{
     int n = 8;// Número de filas y columnas en el patrón
	int **matriz=new int*[n]; //se declara un puntero doble para una matriz
	// Se crean las filas y las columnas de una matriz
	for (int k=0; k<n;k++){
		matriz[k]=new int[n];
	}
	// genera 1_4 del patron
    for (int i = 0; i < n/2; i++) {
        for (int j = 0; j < n/2; j++) {
            if (i==j) {
                matriz[i][j]=true;
        }else{
        	matriz[i][j]=false;
		}
    }
	}
	//Espejo de la matriz 1_4 eje vertical
	for(int i=0; i<n/2;i++){//recorre 4 filas
		for(int j=0;j<n/2;j++){//recorre 4 columnas
			matriz[i][j+n/2]=matriz[i][n/2-1-j];
		}
	}
	// Espejo de la matriz 1_2 eje horizontal
	for(int i=0;i<n/2;i++){//recorre n/2=4 filas
		for(int j=0; j<n; j++){//recorre las n=8 filas
			matriz[i+n/2][j]=matriz[n/2-1-i][j];
		}	
	} 

	impr_Mat(matriz, n);
	
	// Liberar la memoria de la matriz
    for (int i = 0; i < n; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

//************************************************************
void patron_3()
{
    bool Matriz[8][8];
    int Dimension = 8;

    //Funcion que alterna las filas de la matriz //
    for (int i = 0; i < Dimension; i ++){
        if ((i/2) % 2 == 0 ){
            fila_Par (Matriz, Dimension, i);
        }else{
            fila_Impar(Matriz, Dimension, i);
        }
    }
    // Imprimir matriz
	for (int i = 0; i < Dimension; i++) {
        for (int j = 0; j < Dimension; j++) {
            cout << Matriz[i][j] << " ";
        }
        cout << endl;
    }
}

//************************************************************
void patron_4()
{
    bool Matriz[8][8];
    int Dimension = 8;

     // Parte arriba//
    for (int i = 0; i < Dimension; i++){
        for (int k = 0; k < Dimension; k++){
            if (i < Dimension/2){
                arriba(Matriz, Dimension, i, k);
            }else{
                abajo(Matriz, Dimension, i, k);
            }
        }
    }


    // Imprimir la matriz
    for (int i = 0; i < Dimension; i++) {
        for (int j = 0; j < Dimension; j++) {
            cout << Matriz[i][j] << " ";
        }
        cout << std::endl;
    }
}

//************************************************************

