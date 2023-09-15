enqueue(Val, Queue, [Queue|Val]).

dequeue([X], [], X).

dequeue([Head|Tail], [Head|Queue], Val) :-
    dequeue(Tail, Queue, Val).
