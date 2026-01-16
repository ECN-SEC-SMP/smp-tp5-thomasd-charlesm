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
personne* creerPersonne(string nom, 
                        string prenom, 
                        int annee_naissance, 
                        int sexe,
                        personne* conjoint, 
                        personne* pere, 
                        personne* mere) 
{
    personne* p = new personne;
    
    p->nom = nom;
    p->prenom = prenom; 
    p->annee_naissance = annee_naissance; 
    p->sexe = sexe;
    p->conjoint = conjoint;
    p->pere = pere;
    p->mere = mere;
    return p;
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
        cout << "Annee de naissance: " << p->annee_naissance << endl;
        cout << "Sexe : " << (p->sexe == 1 ? "Garcon" : "Fille") << endl;
        if (p->conjoint != nullptr) {
            if (p->conjoint->sexe == 1) {
                cout << "Epoux : " << p->conjoint->prenom << endl;
            } else if (p->conjoint->sexe == 2) {
                cout << "Epouse : " << p->conjoint->prenom << endl;
            }
        } else {
            cout << "Conjoint: Aucun" << endl;
        }
        if (p->pere != nullptr) {
            cout << "Pere : " << p->pere->prenom << endl;
        } else {
            cout << "Pere : Inconnu" << endl;
        }
        if (p->mere != nullptr) {
            cout << "Mere : " << p->mere->prenom << endl;
        } else {
            cout << "Mere : Inconnue" << endl;
        }
        cout << endl;
    }
}

/**
 * @brief Vérifie si deux personnes sont frères ou sœurs
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool frereEtSoeur(personne* a,personne* b)
{
    /* 
    Vérification des conditions pour être frères ou sœurs
        - Les deux personnes ne doivent pas être nulles.
        - Les deux personnes doivent avoir un père et une mère définis.
        - Les pères des deux personnes doivent être les mêmes.
        - Les mères des deux personnes doivent être les mêmes.
    */
    bool condition =   (a       != nullptr &&
                        b       != nullptr &&
                        a->pere != nullptr &&
                        a->mere != nullptr &&
                        b->pere != nullptr &&
                        b->mere != nullptr && 
                        a->pere == b->pere &&
                        a->mere == a->mere);
    return condition;
}

/**
 * @brief Vérifie si une personne est un ancêtre d'une autre personne
 * 
 * @param p 
 * @param ancetre 
 * @return true 
 * @return false 
 */
bool verifierAncetres(personne* p, personne* ancetre) {
    if (p == nullptr || ancetre == nullptr) {
        cout << "Personne ou ancetre est nul." << endl;
        return false;
    }

    if (p == ancetre) {
        cout << "La personne est son propre ancetre." << endl;
        return false;
    }

    bool trouve = false;

    // Vérification récursive des ancêtres
    // On commence par chercher l'ancêtre du côté du père
    if (p->pere != nullptr) {
        if (p->pere == ancetre) {
            trouve = true;
        } else {
            trouve = verifierAncetres(p->pere, ancetre);
        }
    }

    // Si pas trouvé du côté du père, on cherche du côté de la mère
    if (!trouve && p->mere != nullptr) {
        if (p->mere == ancetre) {
            trouve = true;
        } else {
            trouve = verifierAncetres(p->mere, ancetre);
        }
    }
    return trouve;
}
/**
 * @brief 
 * Calcule le nombre de générations à partir d'une personne
 * en remontant jusqu'aux ancêtres les plus éloignés.    
 * 
 * @param p 
 * @return int 
 */
int generation(personne* p)

{
    if (p != nullptr)
    {
        int hpere = generation(p->pere);
        int hmere = generation(p->mere); 
        return 1 + max(hpere,hmere);
    }
    else
    {
        return 0;
    }
}

/**
 * @brief Vérifie si deux personnes peuvent se marier
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool testMariage(personne* a, personne* b)
{
    return (a != nullptr && b != nullptr &&
            a != b &&
            a->conjoint == nullptr &&
            b->conjoint == nullptr &&
            !verifierAncetres(a, b) &&
            !verifierAncetres(b, a) &&
            !frereEtSoeur(a, b) &&
            ((a->mere == nullptr && a->pere == nullptr && 
              b->mere == nullptr && b->pere == nullptr)||
             (a->mere != b->mere && a->pere != b->pere)));
}

/**
 * @brief Calcule la taille de l'arbre généalogique d'une personne
 * 
 * @param p 
 * @return int 
 */
int tailleArbre(personne* p)
{
    if (p != nullptr)
    {
        int taillePere = tailleArbre(p->pere);
        int tailleMere = tailleArbre(p->mere);
        return 1 + taillePere + tailleMere;
    }
    else
    {
        return 0;
    }
}
