#pragma once
#include "type_def.h"

personne* creerPersonne(string nom, string prenom, int annee_naissance, int sexe,
                        personne* conjoint, personne* pere, personne* mere);

void mariage(personne* a, personne* b);

void afficherPersonne(personne* p);

bool verifierAncetres(personne* p, personne* ancetre);