#include "type_def.h"
#include <iostream>

using namespace std;

/**
 * @brief Création d'une personne
 * 
 * @param nom 
 * @param prenom 
 * @param annee_naissance 
 * @param sexe 
 * @param conjoint 
 * @return personne* 
 */
personne* creerPersonne(char nom, char prenom, int annee_naissance, int sexe, personne* conjoint) {
    personne* p = new personne;
    
    p->nom = nom; 
    p->prenom = prenom; 
    p->annee_naissance = annee_naissance; 
    p->sexe = sexe; 
    p->conjoint = conjoint;
}

/**
 * @brief Effectue un mariage (lien) entre deux personnes
 * 
 * @param a 
 * @param b 
 */
void mariage(personne* a, personne* b) {
    if (a != nullptr && b != nullptr) {
        a->conjoint = b;
        b->conjoint = a;
    }
}

/**
 * @brief Affiche les informations d'une personne
 * 
 * @param p 
 */
void afficherPersonne(personne* p) {
    if (p != nullptr) {
        cout << "Nom: " << p->nom << ", Prenom: " << p->prenom << endl;
        cout << ", Annee de naissance: " << p->annee_naissance << endl;
        cout << ", Sexe: " << (p->sexe == 1 ? "Garcon" : "Fille") << endl;
        if (p->conjoint != nullptr) {
            if (p->conjoint->sexe == 1) {
                cout << "Epoux : " << p->conjoint->prenom << endl;
            } else if (p->conjoint->sexe == 2) {
                cout << "Epouse : " << p->conjoint->prenom << endl;
            }
        } else {
            cout << "Conjoint: Aucun" << endl;
        }
    }
}