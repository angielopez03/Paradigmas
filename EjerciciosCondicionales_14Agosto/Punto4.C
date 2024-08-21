#include <stdio.h>

int main() 
{
	int n1; //Se crea la variable
	
	printf("Digite un numero entero: ");
	scanf("%d", &n1); //Se imprime el mensaje y se lee el numero
	
	if(n1%2==0) //Se pone la condicion, si el modulo del numero es 0 entonces imprima par o impar
	{
		printf("El numero es par");
	}
		else
		{
			printf("El numero es impar");
		}
}
