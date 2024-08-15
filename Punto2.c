#include <stdio.h>
#include <string.h>

int main() 
{
	char c[] = "rwsy12"; //se declara la variable de la contraseña y su contenido
	
	char u[50]; //Se declara la variable en el que el usuario depositara su contraseña
	printf("Introduce la contraseña: ");
	scanf("%s", &u); //imprime y lee la contraseña depositada por el usuario
	
	if (strcmp(c, u) == 0) //compara los strings y si coinciden imprime un resultado u otro
	{
		printf("Contraseña exitosa, conincide");
	}
		else
		{
			printf("Contraseña invalida, no coincide");
		}
}
