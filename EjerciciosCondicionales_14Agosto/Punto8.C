#include <stdio.h>

int main()
{
	int e; //se declara la varible para depositar la edad
	
	printf("Ingrese la edad del cliente: ");
	scanf("%d", &e); //imprime el mensaje y lee la edad
	
	while(e>0) //se condiciona para que solo acepte numeros positivos
	{
		if(e<4) //se hace la condicion para cada edad, cuanto debe pagar y que lo imprima segun eso
		{
			printf("el cliente puede ingresar de manera gratuita");
			break; //Se rompe el ciclo una vez cumple con alguna de las condiciones
		}
		
			else if(e>=4 && e<=18)
			{
				printf("El cliente debe pagar un valor de $5");
				break;
			}
			
				else if(e>=18 && e<=60)
				{
					printf("El cliente debe pagar un valor de $10");
					break;
				}
				
					else 
					{
						printf("Dato invalido");
						break;
					}
	}
}
