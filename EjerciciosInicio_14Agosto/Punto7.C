#include <stdio.h> 
#include <math.h> // Incluye la biblioteca matemática para usar la función pow

int main() {

  float kg, m, imc; // Declara variables de tipo float para almacenar el peso (kg), altura (m) y el índice de masa corporal (imc)

  printf("Ingrese su peso en kg: "); // Solicita al usuario que ingrese su peso en kilogramos

  scanf("%f", &kg); // Lee el valor del peso en kilogramos ingresado por el usuario y lo almacena en la variable 'kg'

  if (kg < 0) { // Verifica si el peso ingresado es negativo
    printf("El número ingresado no es positivo.\n"); // Si el peso es negativo, muestra un mensaje de error
  }
    
  else if (kg == 0) { // Verifica si el peso ingresado es 0
    printf("El número ingresado es 0.\n"); // Si el peso es 0, muestra un mensaje específico
  }
    
  else {
    
    printf("Ingrese su altura en m: "); // Si el peso es positivo, solicita al usuario que ingrese su altura en metros
      
    scanf("%f", &m); // Lee el valor de la altura en metros ingresado por el usuario y lo almacena en la variable 'm'

    if (m < 0) { // Verifica si la altura ingresada es negativa
      printf("El número ingresado no es positivo.\n"); // Si la altura es negativa, muestra un mensaje de error
    }
        
    else if (m == 0) { // Verifica si la altura ingresada es 0
      printf("El número ingresado es 0.\n"); // Si la altura es 0, muestra un mensaje específico
    }  
    
    else {
      
      imc = kg / pow(m, 2); // Si el peso y la altura son válidos, calcula el índice de masa corporal     
    
      printf("Tu índice de masa corporal es: %.2f", imc); // Imprime el índice de masa corporal con dos decimales de precisión
    }

    return 0;  // Finaliza el programa y devuelve 0, indicando que se ejecutó correctamente
  }
}
