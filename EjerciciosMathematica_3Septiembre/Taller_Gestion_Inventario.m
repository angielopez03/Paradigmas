(* Agregar un nuevo producto al inventario *)
addProduct[inventory_, name_, price_, quantity_] := 
  Append[inventory, {name, price, quantity}]

(* Actualizar la cantidad de un producto existente *)
updateQuantity[inventory_, name_, newQuantity_] := 
  Map[
    If[#[[1]] === name, {#[[1]], #[[2]], newQuantity}, #] &,
    inventory
  ]

(* Eliminar un producto del inventario *)
removeProduct[inventory_, name_] := 
  Select[inventory, #[[1]] =!= name &]

(* Resumen del inventario: total de productos y valor total *)
inventorySummary[inventory_] := Module[
  {totalQuantity, totalValue},
  totalQuantity = Total[#[[3]] & /@ inventory];
  totalValue = Total[#[[2]] * #[[3]] & /@ inventory];
  {totalQuantity, totalValue}
]

(* Buscar un producto por su nombre *)
findProduct[inventory_, name_] := 
  FirstCase[inventory, {n_, p_, q_} /; n === name :> {p, q}, Missing["NotFound"]]

(* Aplicar un descuento a todos los productos *)
applyDiscount[inventory_, discount_] := 
  Map[{#[[1]], #[[2]] * (1 - discount / 100), #[[3]]} &, inventory]

(* Función principal *)
main[] := Module[
  {inventory, inventory1, inventory2, inventory3, inventory4, inventoryWithDiscount, summary, searchResult},
  
  inventory = {};
  inventory1 = addProduct[inventory, "Manzanas", 0.5, 100];
  inventory2 = addProduct[inventory1, "Platanos", 0.3, 150];
  inventory3 = updateQuantity[inventory2, "Manzanas", 120];
  inventory4 = removeProduct[inventory3, "Platanos"];
  inventoryWithDiscount = applyDiscount[inventory4, 10];
  summary = inventorySummary[inventoryWithDiscount];
  
  (* Imprimir el inventario final *)
  Print["Inventario Final: ", inventoryWithDiscount];
  Print["Total de productos en stock: ", summary[[1]]];
  Print["Valor total del inventario: ", summary[[2]]];
  
  (* Buscar un producto *)
  searchResult = findProduct[inventoryWithDiscount, "Manzanas"];
  If[searchResult === Missing["NotFound"],
    Print["Producto no encontrado"],
    Print["Precio: ", searchResult[[1]], ", Cantidad: ", searchResult[[2]]]
  ];
]

(* Ejecutar la función principal *)
main[]
