#include "type_def.h"

personne* creerPersonne(char nom, char prenom, int annee_naissance, int sexe,
                        personne* conjoint, personne* pere, personne* mere);

void mariage(personne* a, personne* b);

void afficherPersonne(personne* p);