#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include "cum_médiane.h"

namespace py = pybind11;

py::array_t<double> cum_médiane_interface(
    py::array_t<double, py::array::c_style | py::array::forcecast> données) {
    py::buffer_info entrée_info = données.request();
    if (entrée_info.ndim != 1) {
        throw std::runtime_error("Le tableau doit être 1D");
    }

    auto médianes = py::array_t<double>(entrée_info.size);
    py::buffer_info sortie_info = médianes.request();

    double* données_ptr = (double*) entrée_info.ptr;
    double* sortie_ptr = (double*) sortie_info.ptr;
    int taille = entrée_info.size;

    int statut = cum_médiane(données_ptr, taille, sortie_ptr);
    if (statut == ERROR_DONNÉES_RÉPÉTÉES) {
        throw std::runtime_error("Erreur : données répétées");
    }

    return médianes;
}

PYBIND11_MODULE(aymane_tp, module) {
    module.doc() = R"pbdoc(
aymane_tp
=========

Module C++ de calcul de médiane cumulative pour NumPy.
)pbdoc";

    module.def("cum_médiane", &cum_médiane_interface, R"pbdoc(
Calcule la médiane cumulative d'un tableau NumPy 1D.

Parameters
----------
données : numpy.ndarray
    Tableau 1D de réels sans répétition.

Returns
-------
numpy.ndarray
    Tableau 1D contenant les médianes cumulatives.
)pbdoc");
}
