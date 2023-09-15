% MUNDO
% X é casado com Y
casado(me, w).
casado(f, d).

% X é pai de Y
pai(me, s1).
pai(w, s1).
pai(w, d).
pai(f, me).
pai(f, s2).
pai(d, s2).

% REGRAS
% X é pai em lei de Y
paiEmLei(X, Y) :-
    (casado(X, Z); casado(Z, X)),
    pai(Z, Y).

% X é filho de Y
filho(X, Y) :-
    pai(Y, X).

% X é avô de Y
avo(X, Y) :-
    (pai(X, Z), pai(Z, Y));
    (paiEmLei(X, Z), paiEmLei(Z, Y)).
