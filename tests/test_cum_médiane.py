import numpy as np
import pytest
import aymane_tp

def test_erreur_donnees_repetees():
    données = np.array([2.0, 3.0, 1.0, 3.0, 5.0])
    with pytest.raises(RuntimeError):
        aymane_tp.cum_médiane(données)

def test_cinq_donnees_diapo():
    données = np.array([2.0, 3.0, 0.0, 1.0, 5.0])
    attendu = np.array([2.0, 2.5, 2.0, 1.5, 2.0])
    sortie = aymane_tp.cum_médiane(données)
    np.testing.assert_allclose(sortie, attendu)
