#include <stdio.h>

int main() {
    int cantidad;  // Variable para almacenar el número de barras vendidas
    const float precio = 3.49;  // Precio habitual de una barra de pan
    const float descuento = 0.60;  // Descuento del 60% para pan que no es del día
    float precioDescuento, total;  // Variables para el cálculo del precio con descuento y el costo total

    printf("Ingrese el número de barras de pan vendidas que no son del día: "); // Solicita al usuario que ingrese el número de barras de pan que no son del día
    scanf("%d", &cantidad);

    precioDescuento = precio * (1 - descuento); // Calcula el precio con descuento

    total = precioDescuento * cantidad; // Calcula el costo total

    printf("Precio de una barra de pan: %.2f Pesos\n", precio); // Muestra el precio habitual de una barra de pan
    
    printf("Descuento aplicado por no ser fresco: %.2f Pesos\n", precio - precioDescuento); // Muestra el descuento aplicado

    printf("Total después del descuento: %.2f Pesos\n", total); // Muestra el total

    return 0;  // Finaliza el programa y devuelve 0, indicando que se ejecutó correctamente
}
 