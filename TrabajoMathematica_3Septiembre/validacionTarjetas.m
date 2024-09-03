(* Función para convertir un número a una lista de dígitos *)
toDigits[n_] := If[n <= 0, {}, ToExpression[Characters[ToString[n]]]]

(* Función para convertir un número a una lista de dígitos en orden inverso *)
toDigitsRev[n_] := Reverse[toDigits[n]]

(* Función para duplicar cada segundo dígito comenzando desde la derecha *)
doubleEveryOther[xs_] := Reverse[
  MapThread[
    If[EvenQ[#1], #2 * 2, #2] &,
    {Range[Length[xs]], Reverse[xs]}
  ]
]

(* Función para calcular la suma de los dígitos *)
sumDigits[xs_] := Total[Flatten[ToDigits /@ xs]]

(* Función para validar el número según el algoritmo de Luhn *)
validate[n_] := Mod[sumDigits[doubleEveryOther[toDigits[n]]], 10] === 0

(* Función principal para probar todas las funciones *)
main[] := Module[
  {number, digits, digitsRev, doubled, digitSum, isValid},
  number = ToExpression[InputString["Ingrese un número: "]];
  
  digits = toDigits[number];
  digitsRev = toDigitsRev[number];
  doubled = doubleEveryOther[digits];
  digitSum = sumDigits[doubled];
  isValid = validate[number];
  
  Print["Lista de dígitos:"];
  Print[digits];
  
  Print["Lista de dígitos en orden inverso:"];
  Print[digitsRev];
  
  Print["Duplica cada segundo dígito comenzando desde la derecha:"];
  Print[doubled];
  
  Print["Suma de los dígitos:"];
  Print[digitSum];
  
  Print["¿Es un número de tarjeta válido?"];
  Print[isValid]
]

(* Ejecutar la función principal *)
main[]
