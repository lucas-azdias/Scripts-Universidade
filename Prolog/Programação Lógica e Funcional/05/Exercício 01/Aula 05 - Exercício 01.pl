casado(me, w).
casado(f, d).
pai(me, s1).
pai(w, s1).
pai(w, d).
pai(f, me).
pai(f, s2).
pai(d, s2).

paiEmLei(X, Y) :-
    (casado(X, Z); casado(Z, X)),
    pai(Z, Y).

avo(X, Y) :-
    pai(X, Z),
    pai(Z, Y).
