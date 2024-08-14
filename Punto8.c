#include <stdio.h>

int main() {

  int n, m, c, r;  // Declara variables enteras: 'n' para el primer número, 'm' para el segundo número, 'c' para el cociente y 'r' para el residuo
    
  printf("Ingrese un número entero 'n': "); // Solicita al usuario que ingrese un número entero para 'n'

  scanf("%d", &n); // Lee el valor entero ingresado por el usuario y lo almacena en la variable 'n'

  if (n < 0) { // Verifica si el número 'n' es negativo 
    printf("El número ingresado no es positivo.\n"); // Si 'n' es negativo, muestra un mensaje de error
  }
  
  else if (n == 0) { // Verifica si el número 'n' es 0
    printf("El número ingresado es 0.\n"); // Si 'n' es 0, muestra un mensaje específico
  }
  
  else {
    printf("Ingrese un número entero 'm': "); // Si 'n' es positivo, solicita al usuario que ingrese otro número entero para 'm'
    
    scanf("%d", &m); // Lee el valor entero ingresado por el usuario y lo almacena en la variable 'm'

    if (m < 0) { // Verifica si el número 'm' es negativo
      printf("El número ingresado no es positivo.\n"); // Si 'm' es negativo, muestra un mensaje de error
    }
        
    else if (m == 0) { // Verifica si el número 'm' es 0
      printf("El número ingresado es 0.\n"); // Si 'm' es 0, muestra un mensaje específico
    }
    
    else { // Si 'm' es positivo, calcula el cociente y el residuo de la división de 'n' entre 'm'
            
      c = n / m;  // Calcula el cociente
      r = n % m;  // Calcula el residuo

      printf("El cociente de la división de 'n' entre 'm' es: %d\n", c); // Imprime el cociente de la división
            
      printf("El residuo de la división de 'n' entre 'm' es: %d", r); // Imprime el residuo de la división
    }
  }

  return 0;  // Finaliza el programa y devuelve 0, indicando que se ejecutó correctamente
}
