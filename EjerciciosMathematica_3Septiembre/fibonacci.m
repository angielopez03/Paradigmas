fibonacci[0] := 0
fibonacci[1] := 1
fibonacci[n_Integer?Positive] := fibonacci[n - 1] + fibonacci[n - 2]
