#include "type_def.h"

personne* creerPersonne() {
    personne* p = new personne;
    // Initialize fields (for example purposes, using dummy values)
    p->nom = 'A'; // Placeholder for name
    p->prenom = 'B'; // Placeholder for first name
    p->annee_naissance = 1990; // Placeholder for birth year
    p->sexe = 1; // Placeholder
}