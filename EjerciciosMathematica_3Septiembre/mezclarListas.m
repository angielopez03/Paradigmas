mergeSorted[xs_List, ys_List] := 
  Which[
    Length[xs] === 0, ys,
    Length[ys] === 0, xs,
    xs[[1]] <= ys[[1]], Prepend[mergeSorted[Rest[xs], ys], xs[[1]]],
    True, Prepend[mergeSorted[xs, Rest[ys]], ys[[1]]]
  ]
