#include <stdio.h>

int main()
{
	char n[50]; //Se declara la variable string
	 //Se declara lka variable char para leer un solo caracter
	char s;
	
	printf("Digite el nombre del estudiante: ");
	scanf("%s", n); //Se imprime el mensaje y se lee el nombre
	
	printf("Digite el sexo del estudiante(M/F): ");
	scanf(" %c", &s); //Se imprime el mensaje y se lee el caracter
	
	if(n[0] < 'm' && s == 'f') //Se declaran las condiciones para cada grupo
	{
		printf("El estudiante pertenece al grupo A");
	}
	
		else if (n[0] > 'n' && s == 'm')
		{
			printf("El estudiante pertenece al grupo A");
		}
		
			else //Y se imprime el mensaje conforme a las condiciones  puestas
			{
				printf("El estudiante pertenece al grupo B");
			}
		
}
