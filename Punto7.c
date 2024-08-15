#include <stdio.h>

int main()
{
	char n[50]; //se declara cada variable a utilizar, string
	float p=0.0; //puntos del usuario
	int a=0; //variable auxiliar
	int c=20000; //constante de la cantidad a pagar por premiacion
	
	printf("Ingrese el nombre del usuario: ");
	scanf("%s", n);
	
	printf("Ingrese la puntuacion del usuario: ");
	scanf("%f", &p);
	
	if(p>=0 && p<=0.2) //se declaran las condiciones para la premiacion y se imprime el mensaje dependiendo del mismo
	{
		printf("El usuario, %s", n);
		printf("\nno acumulo suficientes beneficios en el año");
	}
	
		else if(p>=0.3 && p<=0.9)
		{
			a=p*10;
			a=a*c;
			printf("El usuario, %s", n);
			printf("\nAcumulo un total de %.1f puntos, ganando $%d.\n", p, a);
		}
		
			else 
			{
				printf("La puntuacion del usuario %s no esta dentro del rango a premiar", n);
			}
}
