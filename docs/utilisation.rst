Utilisation
===========

Exemple de la diapo
-------------------

.. code-block:: python

   >>> données = np.array([2.0, 3.0, 0.0, 1.0, 5.0])
   >>> aymane_tp.cum_médiane(données)
   array([2. , 2.5, 2. , 1.5, 2. ])

========  =================  =========
Position  Valeurs vues       Médiane
========  =================  =========
1         2                  2
2         2, 3               2.5
3         0, 2, 3            2
4         0, 1, 2, 3         1.5
5         0, 1, 2, 3, 5      2
========  =================  =========

Données répétées
----------------

Les valeurs doivent être toutes différentes, sinon on a une erreur :

.. code-block:: python

   >>> aymane_tp.cum_médiane(np.array([2.0, 3.0, 1.0, 3.0]))
   RuntimeError: Erreur : données répétées

Le tableau doit aussi être en 1D.
