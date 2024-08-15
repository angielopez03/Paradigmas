#include <stdio.h>

int main()
{
	char pre; //se declaran las variables a utilizar, las dos guardan las respuestas del usuario
	char i;
	
	printf("Bienvenido a nuestra pizzeria");
	printf("\nDesea ordenar una pizza vegetariana? (S/N)");
	scanf("%c", &pre); //Muestra los mensajes y la respuesta del usuario en la variable
	
	switch(pre) //se hace un switch para cada caso que el usuario haya respodido
	{
		case 's': //en el caso de la pizza vegetariana
			
			printf("\nEn el caso de nuestra pizza vegetariana");
			printf("\nTenemos dos ingredientes para seleccionar aparte de la mozzarella y el tomate que están en todas la pizzas");
			printf("\nTenemos disponibles pimiento(P) y tofu(T), elija uno con su inicial: ");
			scanf("%s", &i);
		
			if(i=='p' || i=='P') //dependiendo de la respuesta de cual ingrediente prefiera, se imprime el resultado
			{
				printf("\nListo!");
				printf("\nSu pedido fue una pizza vegetariana con: ");
				printf("\n- Mozzarella");
				printf("\n- Tomate");
				printf("\n- Pimiento");
				printf("\nGracias por preferirnos! En breve estara lista su orden");
			}
			
				else if(i=='t' || i=='T')
				{
					printf("\nListo!");
					printf("\nSu pedido fue una pizza vegetariana con: ");
					printf("\n- Mozzarella");
					printf("\n- Tomate");
					printf("\n- Tofu");
					printf("\nGracias por preferirnos! En breve estara lista su orden");
				}
				
					else
					{
						printf("Dato invalido");
					}
		break;			
		
		case 'n': //en el caso de la pizza no vegetariana
			
			printf("\nEn el caso de nuestra pizza no vegetariana");
			printf("\nTenemos tres ingredientes para seleccionar aparte de la mozzarella y el tomate que están en todas la pizzas");
			printf("\nTenemos disponibles peperoni(P), jamon(J) y salmon(S), elija uno con su inicial: ");
			scanf("%s", &i);
			
			if(i=='p' || i=='P') //dependiendo de la respuesta de cual ingrediente prefiera, se imprime el resultado
			{
				printf("\nListo!");
				printf("\nSu pedido fue una pizza no vegetariana con: ");
				printf("\n- Mozzarella");
				printf("\n- Tomate");
				printf("\n- Peperoni");
				printf("\nGracias por preferirnos! En breve estara lista su orden");
			}
			
				else if(i=='j' || i=='J')
				{
					printf("\nListo!");
					printf("\nSu pedido fue una pizza no vegetariana con: ");
					printf("\n- Mozzarella");
					printf("\n- Tomate");
					printf("\n- jamon");
					printf("\nGracias por preferirnos! En breve estara lista su orden");
				}
				
					else if(i=='s' || i=='S')
					{
						printf("\nListo!");
						printf("\nSu pedido fue una pizza no vegetariana con: ");
						printf("\n- Mozzarella");
						printf("\n- Tomate");
						printf("\n- Salmon");
						printf("\nGracias por preferirnos! En breve estara lista su orden");
					}
					
						else
						{
							printf("Dato invalido"); 
						}
		break;				
	}
}
