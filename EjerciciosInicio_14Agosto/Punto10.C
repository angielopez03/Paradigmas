#include <stdio.h>

int main () {
  
  const int pesoPayaso = 112, pesoMuneca = 75;
  int cantidadPayasos, cantidadMunecas, peso_total;
  
  printf("Ingrese la cantidad de payasos vendidos: "); // Solicita la cantidad de payasos vendidos
  scanf("%d", &cantidadPayasos);

  if (cantidadPayasos < 0) { // Verifica que la cantidad de payasos no sea negativa
    printf("La cantidad de payasos no puede ser negativa.");
    return 1;
  }

  printf("Ingrese la cantidad de muñecas vendidas: "); // Solicita la cantidad de muñecas vendidas
  scanf("%d", &cantidadMunecas);
  
  if (cantidadMunecas < 0) { // Verifica que la cantidad de muñecas no sea negativa
    printf("La cantidad de muñecas no puede ser negativa.");
    return 1;
  }

  peso_total = (cantidadPayasos * pesoPayaso) + (cantidadMunecas * pesoMuneca); // Calcula el peso total del paquete

  printf("Peso total del paquete: %d gramos", peso_total); // Muestra el peso total del paquete

  return 0;  
}
