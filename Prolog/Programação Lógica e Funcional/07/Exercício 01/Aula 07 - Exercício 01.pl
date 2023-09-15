dist(Ponto1, Ponto2, Dist) :-
    Ponto1 = ponto(X1, Y1),
    Ponto2 = ponto(X2, Y2),
    DeltaX is X2 - X1,
    DeltaY is Y2 - Y1,
    Dist is sqrt(DeltaX ^ 2 + DeltaY ^ 2).

colinear(Ponto1, Ponto2, Ponto3) :-
    Ponto1 = ponto(X1, Y1),
    Ponto2 = ponto(X2, Y2),
    Ponto3 = ponto(X3, Y3),
    ((X3 * Y2 + X1 * Y3 + X2 * Y1)-(X1 * Y2 + X3 * Y1 + X2 * Y3)) =:= 0. 
