% Regelbasis
% 1. Wenn Karl Rita liebt, dann liebt Werner Birgit. 
liebt(werner, birgit) :- liebt(karl, rita).

% 2. Wenn Herbert jedoch Birgit liebt, dann liebt Fritz Karin. 
liebt(fritz, karin) :- liebt(herbert, birgit).

% 3. Für den Fall dass Birgit nur von Werner geliebt wird, liebt Herbert Claudia. 
liebt(herbert, claudia) :- liebt(werner, birgit), not(liebt(herbert, birgit); liebt(fritz, birgit); liebt(karl, birgit)).

% 4. Karl liebt Birgit aber nur, wenn Fritz nicht in Karin verliebt ist. 
liebt(karl, birgit) :- not(liebt(fritz, karin)).

% 5. Karl schwärmt für Rita. 
liebt(karl, rita).

% 6. Fritz liebt diejenigen der Damen, für die sich die übrigen Herren nicht erwärmen können.  
liebt(fritz, FRAU) :- not(liebt(werner, FRAU)), not(liebt(herbert, FRAU)), not(liebt(karl, FRAU)).

% Anfrage:
liebt(X, Y).    % Wer liebt wen?