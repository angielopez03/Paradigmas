#include <stdio.h>

int main() 
{
	float n1=0; //se declaran las variables donde se depositan los numeros
	float n2=0;
	printf("Ingrese dos numeros para dividir: ");
	scanf("%f", &n1);
	scanf("%f", &n2); //Se imprime el mensaje y se leen los numeros
	
	float r=0;
	if (n2!=0) //Se hace  la condicion para que el denominador no sea 0
	{
		r= (n1/n2);
		printf("El resultado de la division es, %f", r);
	}
		else 
		{
			printf("Error matematico"); //y en caso de que sea 0 imprimir error
		}
}
