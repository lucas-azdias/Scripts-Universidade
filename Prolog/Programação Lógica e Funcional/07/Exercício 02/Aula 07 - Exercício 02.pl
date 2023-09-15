combiner([], Lista2, Lista2).

combiner([Head|Tail1], Lista2, [Head|TailResult]) :-
    combiner(Tail1, Lista2, TailResult).
