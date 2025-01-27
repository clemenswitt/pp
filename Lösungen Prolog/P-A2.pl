% Wissensbasis
mensch(aristoteles).
mensch(sokrates).
tier(schlange).
gott(zeus).
gott(apollo).

% Regelbasis
sterblich(X) :- mensch(X) ; tier(X).    % Alle Tiere und Menschen sind sterblich.
unsterblich(X) :- not(sterblich(X)).    % Alle Wesen, die keine Tiere oder Menschen sind, sind unsterblich.

% Anfragen
sterblich(sokrates).                    % Ist Sokrates sterblich?
tier(schlange), sterblich(schlange).    % Ist die Schlange ein Tier und sterblich?
unsterblich(zeus).                      % Ist Zeus unsterblich?