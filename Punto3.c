#include <stdio.h>

int main() {
    char nombre[100];  // Declara un arreglo de caracteres (cadena) de tamaño 100 para almacenar el nombre del usuario

    printf("Por favor ingrese su nombre: ");  // Muestra un mensaje solicitando al usuario que ingrese su nombre

    scanf("%99s", nombre);  // Lee una cadena de caracteres desde la entrada estándar y la almacena en el arreglo 'nombre'
                             // %99s asegura que se lean hasta 99 caracteres para evitar el desbordamiento de búfer

    printf("¡Hola %s!", nombre);  // Imprime un saludo utilizando el nombre ingresado por el usuario

    return 0;  // Indica que el programa terminó exitosamente
}
