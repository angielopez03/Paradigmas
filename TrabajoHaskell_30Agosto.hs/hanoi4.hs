hanoi4 :: Integer -> Char -> Char -> Char -> Char -> [(Char, Char)]
hanoi4 0 _ _ _ _ = []
hanoi4 n from to aux1 aux2 =
    let k = div n 2
    in  hanoi4 k from aux1 aux2 to ++            -- Mueve k discos de 'from' a 'aux1'
        hanoi (n - k) from to aux2 ++              -- Mueve los n-k discos de 'from' a 'to'
        hanoi4 k aux1 to from aux2 ++             -- Mueve k discos de 'aux1' a 'to'
        hanoi (n - k) to from aux1 ++              -- Mueve los n-k discos de 'to' a 'from'
        hanoi4 k to from aux2 aux1                -- Mueve k discos de 'to' a 'from'
