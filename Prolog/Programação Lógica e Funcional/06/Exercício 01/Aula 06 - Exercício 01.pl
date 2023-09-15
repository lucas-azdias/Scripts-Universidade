xor(X, Y) :-
    (X; Y), (\+X; \+Y).
	% Podia ser também (X, \+Y); (\+X, Y).
