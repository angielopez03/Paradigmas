#include <stdio.h>
#include <math.h>  // Incluye la biblioteca matemática para usar la función pow

int main() {
    float deposito, ahorros;
    const float tasaInteres = 0.04;  // Tasa de interés anual del 4%

    printf("Ingrese la cantidad de dinero depositada en la cuenta de ahorros: "); // Solicita al usuario que ingrese el monto depositado
    scanf("%f", &deposito);

    ahorros = deposito * pow((1 + tasaInteres), 1); // Calcula el saldo después del primer año
    printf("Saldo después del primer año: %.2f\n", ahorros);
    
    ahorros = deposito * pow((1 + tasaInteres), 2); // Calcula el saldo después del segundo año
    printf("Saldo después del segundo año: %.2f\n", ahorros);

    ahorros = deposito * pow((1 + tasaInteres), 3); // Calcula el saldo después del tercer año
    printf("Saldo después del tercer año: %.2f\n", ahorros);

    return 0;  // Finaliza el programa y devuelve 0, indicando que se ejecutó correctamente
}
