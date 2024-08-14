#include <stdio.h>

int main() {
    int n;  // Declara una variable entera 'n' para almacenar el número ingresado por el usuario

    printf("Ingrese un número entero positivo: "); // Solicita al usuario que ingrese un número entero positivo

    scanf("%d", &n); // Lee el número entero ingresado por el usuario y lo almacena en la variable 'n'

    if (n < 0) { // Verifica si el número ingresado es negativo
        printf("El número ingresado no es positivo.\n"); // Si el número es negativo, muestra un mensaje de error
    }
    
    else if (n == 0) { // Verifica si el número ingresado es 0
        printf("El número ingresado es 0.\n"); // Si el número es 0, muestra un mensaje específico
    }

    else { // Si el número es positivo y no es 0
        printf("La suma del entero positivo desde 1 hasta 'n' es: %d\n", (n*(n+1))/2); // Calcula la suma de los números enteros desde 1 hasta 'n'
    }

    return 0;  // Finaliza el programa y devuelve 0, indicando que se ejecutó correctamente
}
