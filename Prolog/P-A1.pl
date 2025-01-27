lernt(otto, mathe).
lernt(paula, englisch).
lernt(rainer, mathe).
lernt(bibi, biologie).

lehrt(heinz, mathe).
lehrt(friedrich, physik).
lehrt(sleiglinde, englisch).

lehrer(X, Y) :- lehrt(X, C), lernt(Y, C).

gleiches_fach(X, Y) :- lernt(X, C), lernt(Y, C).

% Aufgabe 7-2
lernt(otto, Fach), lehrt(heinz, Fach). % Ist Heinz der Lehrer von Otto?
lernt(paul, Fach), lehrt(heinz, Fach). % Ist Heinz der Lehrer von Paul?
gleiches_fach(otto, rainer). % Lernen Otto und Rainer dasselbe Fach?

% Aufgabe 7-3
lehrt(max, physik).
geschwister(otto, rainer).
geschwister(paula, bibi).

% Aufgabe 7-4
zusammen_lernen(X, Y) :- geschwister(X, Y), gleiches_fach(X, Y).    % Zusammen lernen ist möglich, wenn zwei Kinder Geschwister sind und dasselbe Fach lernen.

% Aufgabe 7-5
zusammen_lernen(bibi, rainer).  % Können Bibi und Rainer zusammen lernen?
zusammen_lernen(bibi, paula).   % Können Bibi und Paula zusammen lernen?