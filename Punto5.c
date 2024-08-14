#include <stdio.h>

int main() {
    int horas, coste;  // Declara dos variables enteras: 'horas' para el número de horas trabajadas y 'coste' para el coste por hora

    printf("Ingrese el número de horas trabajadas: "); // Solicita al usuario que ingrese el número de horas trabajadas

    scanf("%d", &horas); // Lee el número de horas ingresadas por el usuario y las almacena en la variable 'horas'

    printf("Ingrese el coste por hora: "); // Solicita al usuario que ingrese el coste por hora

    scanf("%d", &coste); // Lee el coste por hora ingresado por el usuario y lo almacena en la variable 'coste'

    printf("La paga que le corresponde es: $%d", horas * coste); // Calcula la paga total multiplicando el número de horas por el coste por hora e imprime el resultado

    return 0;  // Finaliza el programa indicando que se ejecutó correctamente
}