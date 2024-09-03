(* Función para resolver las Torres de Hanoi *)
hanoi[n_, from_, to_, aux_] := Module[
  {moves},
  moves = If[n == 0,
    {},
    Join[
      hanoi[n - 1, from, aux, to],       (* Mueve n-1 discos de 'from' a 'aux' *)
      {{from, to}},                       (* Mueve el disco más grande de 'from' a 'to' *)
      hanoi[n - 1, aux, to, from]         (* Mueve los n-1 discos de 'aux' a 'to' *)
    ]
  ];
  moves
]

(* Función principal *)
main[] := Module[
  {numDiscos, movimientos},
  numDiscos = 3;
  movimientos = hanoi[numDiscos, "A", "B", "C"];
  Print[movimientos]
]

(* Ejecutar la función principal *)
main[]
