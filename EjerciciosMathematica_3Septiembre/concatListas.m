concatLists[{}, ys_] := ys
concatLists[{x_, xs___}, ys_] := Prepend[concatLists[{xs}, ys], x]
