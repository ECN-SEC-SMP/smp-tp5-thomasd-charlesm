#pragma once
#include <string>

using namespace std;

struct personne
{
    string nom;
    string prenom;
    int annee_naissance; 
    int sexe; // 1: garcon, 2: fille
    personne* conjoint;
    personne* pere;
    personne* mere;
    
};


