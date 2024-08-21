#include <stdio.h>
#include <string.h>

int main() 
{
	char c[] = "rwsy12"; //se declara la variable de la contrasena y su contenido
	
	char u[50]; //Se declara la variable en el que el usuario depositara su contrasena
	printf("Introduce la contrasena: ");
	scanf("%s", &u); //imprime y lee la contrasena depositada por el usuario
	
	if (strcmp(c, u) == 0) //compara los strings y si coinciden imprime un resultado u otro
	{
		printf("Contrasena exitosa, conincide");
	}
		else
		{
			printf("Contrasena invalida, no coincide");
		}
}
