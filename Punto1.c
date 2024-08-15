#include <stdio.h>

int main() 
{
	int e;
	printf("Cual es su edad?"); 
	scanf("%d", &e); //pregunta al usuario su edad y la almacena en una variable
	
	if(e<18) //se hace un condicional
	{
		printf("El usuario no es mayor de edad"); //si es menor a 18 imprime indicandole que no es mayor de edad
	}
		else
		{
			printf("El usuario es mayor de edad"); //si es mayor a 18 imprime indicandole que si
		}
  
}
