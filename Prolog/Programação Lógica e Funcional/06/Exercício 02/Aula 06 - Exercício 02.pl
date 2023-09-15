sum(X, Y, Result) :-
    Result is X + Y.

ehPar(X) :-
    X mod 2 =:= 0.

circleArea(Radius, Result) :-
    Result is Radius * Radius * 3.14.

calculator :-
    write("Calculator 3000"), nl,
    repeat,
    read(X),
    read(Y),
    read(Op),
    (Op == +, R is X + Y; true),
    (Op == -, R is X - Y; true),
    (Op == *, R is X * Y; true),
    (Op == /, R is X / Y; true),
    (Op == //, R is X // Y; true),
    (Op == mod, R is X mod Y; true),
    write(R), nl,
    write("Continue? 0 to end"),
    read(Response),
    (Response =:= 0 -> !; true).
