#include <stdio.h>

int main()
{
	int a; //Se declaran las variables
	int i;
	
	printf("Digite su edad: ");
	scanf("%d", &a); //Se imprime el mensaje y se lee el numero
	
	printf("Digite su ingreso mensual: ");
	scanf("%d", &i); //Se imprime el mensaje y se lee el numero
	
	if(a>16) //Se declara el condicional mediante la edad, para determinar el si tiene que tributar
	{
		printf("Cumple con la edad\n");
		
		if(i>=1000) //En caso de que cumpla con la edad se evalua si cumple con los ingresos
		{
			printf("Cumple con los ingresos necesarios\n");
			printf("\nDebe tributar");
		}
			else 
			{
				printf("No cumple con los ingresos necesarios\n");
				printf("\nNo debe tributar");
			}
	}
		else 
		{
			printf("No cumple no la edad\n");
			printf("\nNo debe tributar");
		}
}
