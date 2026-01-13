#include "type_def.h"
#include "utils.h"

int main() {
    // Création de deux personnes
    personne* alice;
    personne* bob = creerPersonne('Bob', 'Olivier', 1988, 1, alice, nullptr, nullptr);
    personne* charles = creerPersonne('Charles', 'Olivier', 2010, 1, nullptr, bob, alice);

    alice = creerPersonne('Alice', 'Marie', 1990, 2, bob, nullptr, nullptr);
    // Effectuer un mariage entre Alice et Bob
    mariage(alice, bob);

    // Afficher les informations des deux personnes
    afficherPersonne(alice);
    afficherPersonne(bob);
    afficherPersonne(charles);

    // Libération de la mémoire
    delete alice;
    delete bob;
    delete charles;

    return 0;
}