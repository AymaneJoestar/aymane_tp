aymane_tp
=========

Package Python pour le TP 8. Il calcule la médiane cumulative d'un
tableau numpy avec une fonction écrite en C++ (via pybind11).

Pour chaque position i, la sortie contient la médiane des i premières
valeurs du tableau.

.. code-block:: python

   >>> import numpy as np
   >>> import aymane_tp
   >>> aymane_tp.cum_médiane(np.array([2.0, 3.0, 0.0, 1.0, 5.0]))
   array([2. , 2.5, 2. , 1.5, 2. ])

.. toctree::
   :maxdepth: 2

   installation
   utilisation
   algorithme
   api
