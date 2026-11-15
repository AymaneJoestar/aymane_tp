#include "cum_médiane.h"
#include <set>
#include <iterator>

int cum_médiane(
    const double* données_ptr, const int taille, double* sortie_ptr) {
    std::set<double> valeurs_triées;
    std::set<double>::iterator milieu;

    for (int indice = 0; indice < taille; indice++) {
        double valeur = données_ptr[indice];
        auto insertion = valeurs_triées.insert(valeur);
        if (!insertion.second) {
            return ERROR_DONNÉES_RÉPÉTÉES;
        }

        bool nombre_pair = valeurs_triées.size() % 2 == 0;
        if (valeurs_triées.size() == 1) {
            milieu = insertion.first;
        } else if (nombre_pair && valeur < *milieu) {
            milieu--;
        } else if (!nombre_pair && valeur > *milieu) {
            milieu++;
        }

        if (nombre_pair) {
            sortie_ptr[indice] = (*milieu + *std::next(milieu)) / 2;
        } else {
            sortie_ptr[indice] = *milieu;
        }
    }
    return SUCCESS;
}
