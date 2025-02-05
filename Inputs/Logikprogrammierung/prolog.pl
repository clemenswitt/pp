% Fakten: Personen
person(anna).
person(maria).
person(susanne).
person(peter).
person(klaus).
person(hans).

% Fakten: Geschlechter
weiblich(anna).
weiblich(maria).
weiblich(susanne).
maennlich(peter).
maennlich(klaus).
maennlich(hans).

% Fakten: Kind-Beziehungen
kind(anna, maria).   % Anna ist ein Kind von Maria
kind(anna, peter).   % Anna ist ein Kind von Peter
kind(peter, klaus).  % Peter ist ein Kind von Klaus
kind(maria, susanne).% Maria ist ein Kind von Susanne
kind(maria, hans).   % Maria ist ein Kind von Hans

% Regeln: Verwandtschaftsbeziehungen
vater(Vater, Kind) :- kind(Kind, Vater), maennlich(Vater).
mutter(Mutter, Kind) :- kind(Kind, Mutter), weiblich(Mutter).
eltern(Elternteil, Kind) :- kind(Kind, Elternteil).
grosseltern(Grosselternteil, Kind) :- kind(Kind, Elternteil), kind(Elternteil, Grosselternteil).

% Beispielanfragen
eltern(X, anna).                            % Wer sind die Eltern von Anna?
kind(X, maria).                             % Wer sind die Kinder von Maria?
grosseltern(X, Y).                          % Welche Großeltern-Beziehungen existieren in der Wissensbasis?
person(X), not(vater(X, _); mutter(X, _)).  % Existieren Personen in der Wissensbasis, die weder Vater noch Mutter sind?