maxList[xs_List] := Module[{first, rest},
  If[xs === {}, 
    Throw["Lista vacía"], 
    If[Length[xs] === 1, 
      xs[[1]], 
      first = xs[[1]];
      rest = Rest[xs];
      Max[first, maxList[rest]]
    ]
  ]
]
