#include <stdio.h>
#include <string.h>

int main() 
{
	char c[] = "rwsy12"; //se declara la variable de la contrase�a y su contenido
	
	char u[50]; //Se declara la variable en el que el usuario depositara su contrase�a
	printf("Introduce la contrase�a: ");
	scanf("%s", &u); //imprime y lee la contrase�a depositada por el usuario
	
	if (strcmp(c, u) == 0) //compara los strings y si coinciden imprime un resultado u otro
	{
		printf("Contrasena exitosa, conincide");
	}
		else
		{
			printf("Contrasena invalida, no coincide");
		}
}
