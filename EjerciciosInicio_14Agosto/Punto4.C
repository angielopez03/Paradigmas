#include <stdio.h>
#include <math.h>    // Incluye la biblioteca matemática para usar la función pow

int main() 
{
  printf("Para la operación: ((3+2)/25)^2\n");   // Imprime la operación matemática que se va a realizar

  float operacion, total;  // Declara dos variables de tipo float para almacenar los resultados de la operación

  operacion = ((3 + 2) / 25.0); // Realiza la operación ((3+2)/25.0) y almacena el resultado en la variable operacion
                                // Se usa 25.0 para asegurar que la división sea en punto flotante

  total = pow(operacion, 2); // Calcula el cuadrado de operacion usando la función pow y almacena el resultado en la variable total

  printf("El resultado es: %f", total); // Imprime el resultado del cálculo

  return 0;  // Indica que el programa terminó exitosamente
}
