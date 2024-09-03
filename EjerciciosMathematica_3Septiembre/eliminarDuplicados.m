removeDuplicates[{}] := {}
removeDuplicates[{x_, xs___}] := 
  If[MemberQ[{xs}, x], 
     removeDuplicates[{xs}], 
     Prepend[removeDuplicates[{xs}], x]]
