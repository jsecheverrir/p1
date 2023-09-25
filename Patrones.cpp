#include <iostream>
using namespace std;
void menu();//menu
void ejecp(int);//mensaje de ejecucion

//bool isPrime(int);// Funcion que determina si un numero es primo
void patron_1();//ejecuta el patron 1
void patron_2();//ejecuta el patron 2
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



/*****************************************************************
 * Funciones: Cada funcion corresponde a un patron  #            *
******************************************************************/

void patron_1()
{
    cout<<"En constriccion "<<endl;	
}

//************************************************************
void patron_2()
{
    cout<<"En constriccion "<<endl;	
}

//************************************************************
void patron_3()
{
    cout<<"En constriccion "<<endl;	
}

//************************************************************
void patron_4()
{
    cout<<"En constriccion "<<endl;	
}

//************************************************************

