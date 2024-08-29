-- Agregar un nuevo producto al inventario
addProduct :: [(String, Double, Int)] -> String -> Double -> Int -> [(String, Double, Int)]
addProduct inventory name price quantity = inventory ++ [(name, price, quantity)]

-- Actualizar la cantidad de un producto existente
updateQuantity :: [(String, Double, Int)] -> String -> Int -> [(String, Double, Int)]
updateQuantity [] _ _ = []
updateQuantity ((n, p, q):xs) name newQuantity
    | n == name = (n, p, newQuantity) : xs
    | otherwise = (n, p, q) : updateQuantity xs name newQuantity

-- Eliminar un producto del inventario
removeProduct :: [(String, Double, Int)] -> String -> [(String, Double, Int)]
removeProduct inventory name = filter (\(n, _, _) -> n /= name) inventory

-- Resumen del inventario: total de productos y valor total
inventorySummary :: [(String, Double, Int)] -> (Int, Double)
inventorySummary inventory = (totalQuantity, totalValue)
  where
    totalQuantity = sum [q | (_, _, q) <- inventory]
    totalValue = sum [p * fromIntegral q | (_, p, q) <- inventory]

-- Buscar un producto por su nombre
findProduct :: [(String, Double, Int)] -> String -> Maybe (Double, Int)
findProduct [] _ = Nothing
findProduct ((n, p, q):xs) name
    | n == name = Just (p, q)
    | otherwise = findProduct xs name

-- Aplicar un descuento a todos los productos
applyDiscount :: [(String, Double, Int)] -> Double -> [(String, Double, Int)]
applyDiscount inventory discount = [(name, price * (1 - discount / 100), quantity) | (name, price, quantity) <- inventory]

main :: IO ()
main = do
    let inventory = []
    let inventory1 = addProduct inventory "Manzanas" 0.5 100
    let inventory2 = addProduct inventory1 "Platanos" 0.3 150
    let inventory3 = updateQuantity inventory2 "Manzanas" 120
    let inventory4 = removeProduct inventory3 "Platanos"
    let inventoryWithDiscount = applyDiscount inventory4 10
    let (totalQty, totalValue) = inventorySummary inventoryWithDiscount

    -- Imprimir el inventario final
    putStrLn $ "Inventario Final: " ++ show inventoryWithDiscount
    putStrLn $ "Total de productos en stock: " ++ show totalQty
    putStrLn $ "Valor total del inventario: " ++ show totalValue

    -- Buscar un producto
    let searchResult = findProduct inventoryWithDiscount "Manzanas"
    case searchResult of
        Just (price, quantity) -> putStrLn $ "Precio: " ++ show price ++ ", Cantidad: " ++ show quantity
        Nothing -> putStrLn "Producto no encontrado"
