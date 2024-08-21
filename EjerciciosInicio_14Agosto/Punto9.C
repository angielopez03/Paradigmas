#include <stdio.h>
#include <math.h>  // Incluye la biblioteca matemática para usar la función pow

int main() {
    float inversion, interes, anios, capital;
    
    printf("Ingrese la cantidad a invertir: "); // Solicita al usuario la cantidad a invertir
    scanf("%f", &inversion);

    printf("Ingrese el interés anual (en porcentaje): "); // Solicita al usuario el interés anual (en porcentaje)
    scanf("%f", &interes);

    printf("Ingrese el número de años: "); // Solicita al usuario el número de años
    scanf("%f", &anios);

    
    float tasaInteres = interes / 100.0; // Convierte el interés anual de porcentaje a decimal

    capital = inversion * pow((1 + tasaInteres), anios); // Calcula el capital obtenido usando la fórmula del interés compuesto

    printf("El capital obtenido después de %.1f años es: %.2f\n", anios, capital); // Muestra el capital obtenido

    return 0;  // Finaliza el programa y devuelve 0, indicando que se ejecutó correctamente
}
