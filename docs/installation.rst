Installation
============

Il faut Python 3.9+ et un compilateur C++ (g++). pybind11 est installé
automatiquement par pip.

.. code-block:: bash

   git clone https://github.com/AymaneJoestar/aymane_tp.git
   pip install -v ./aymane_tp

Pour lancer les tests :

.. code-block:: bash

   pytest aymane_tp/tests/

Fichiers du package :

- ``setup.py`` : compile l'extension C++
- ``src/cum_médiane.h`` et ``src/cum_médiane.cpp`` : la fonction C++
- ``src/interface.cpp`` : conversion du tableau numpy en pointeur
- ``tests/test_cum_médiane.py`` : les tests
