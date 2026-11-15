Algorithme
==========

On garde les valeurs déjà vues dans un ``std::set`` (toujours trié) et
un itérateur ``milieu`` qui pointe sur la valeur du milieu.

À chaque nouvelle valeur v :

- si c'est la première valeur, ``milieu`` pointe dessus
- si le nombre de valeurs devient pair et que v < ``*milieu``, on fait
  ``milieu--``
- si le nombre de valeurs devient impair et que v > ``*milieu``, on
  fait ``milieu++``

La médiane est ``*milieu`` si le nombre de valeurs est impair, sinon
c'est la moyenne de ``*milieu`` et de la valeur suivante.

Chaque insertion dans le set coûte O(log n), donc le tout est en
O(n log n).

Si une valeur est déjà dans le set, l'insertion échoue et la fonction
retourne ``ERROR_DONNÉES_RÉPÉTÉES`` (1) au lieu de ``SUCCESS`` (0).
