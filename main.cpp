#include "type_def.h"
#include "utils.h"
#include <iostream>

#define EMPTY nullptr

void testAfficherPersonne();
void testVerifierMariage();
void testAncetre ();
void testGeneration();
void testFrereSoeur();
void testTailleArbre();
void testMariagePossible();

int main() {
    testAfficherPersonne();
    testVerifierMariage();
    testAncetre ();
    testGeneration();
    testFrereSoeur();
    testTailleArbre();
    testMariagePossible();
    return 0;
}

// Tests

void testAfficherPersonne() {
    cout << "-----------------------------------" << endl;
    cout << "testAfficherPersonne & creerPersonne:" << endl;
    cout << endl;

    // Création d'une personne
    personne* p = creerPersonne("Doe", "John", 1980, 1, EMPTY, EMPTY, EMPTY);

    // Affichage des informations de la personne
    afficherPersonne(p);

    delete p;
}

void testVerifierMariage() {
    cout << "-----------------------------------" << endl;
    cout << "testVerifierMariage:" << endl;
    cout << endl;

    // Création de deux personnes
    personne* p1 = creerPersonne("Smith", "Jane", 1992, 2, EMPTY, EMPTY, EMPTY);
    personne* p2 = creerPersonne("Brown", "Mike", 1990, 1, EMPTY, EMPTY, EMPTY);

    // Effectuer le mariage
    mariage(p1, p2);

    // Afficher les informations des deux personnes pour vérifier le mariage
    // Le conjoint de p1 doit être p2 et vice versa
    afficherPersonne(p1);
    afficherPersonne(p2);

    delete p1;
    delete p2;
}

void testAncetre (){
    cout << "-----------------------------------" << endl;
    cout << "testAncetre:" << endl;
    cout << endl;

    // Création de l'arbre généalogique + 1 inconnu
    personne* inconnu    = creerPersonne("Inconnu"  , "Inconnu" , 1900, 1, EMPTY, EMPTY     , EMPTY     );
    personne* grandPere1 = creerPersonne("Grand"    , "Pere 1"  , 1950, 1, EMPTY, EMPTY     , EMPTY     );
    personne* grandPere2 = creerPersonne("Grand"    , "Pere 2"  , 1950, 1, EMPTY, EMPTY     , EMPTY     );
    personne* grandMere1 = creerPersonne("Grand"    , "Mere 1"  , 1950, 2, EMPTY, EMPTY     , EMPTY     );
    personne* grandMere2 = creerPersonne("Grand"    , "Mere 2"  , 1950, 2, EMPTY, EMPTY     , EMPTY     );
    personne* pere       = creerPersonne("Super"    , "Papa"    , 1975, 2, EMPTY, grandPere1, grandMere1);
    personne* mere       = creerPersonne("Super"    , "Maman"   , 1975, 2, EMPTY, grandPere2, grandMere2);
    personne* enfant     = creerPersonne("Petit"    , "Enfant"  , 2000, 1, EMPTY, pere      , EMPTY     );
    // Test de la fonction verifierAncetres
    if (verifierAncetres(enfant, grandPere1)) {
        cout << "Test Ancetre (grandPere1) : Succes (attendu)" << endl;
    } else {
        cout << "Test Ancetre (grandPere1) : Echec (faux)" << endl;
    }

    if (verifierAncetres(enfant, inconnu)) {
        cout << "Test Ancetre (inconnu) : Echec (faux)" << endl;
    } else {
        cout << "Test Ancetre (inconnu) : Succes (attendu)" << endl;
    }

    delete inconnu;
    delete grandPere1;
    delete grandPere2;
    delete grandMere1;
    delete grandMere2;
    delete pere;
    delete mere;
    delete enfant;
}

void testFrereSoeur() {
    cout << "-----------------------------------" << endl;
    cout << "testFrereSoeur:" << endl;
    cout << endl;

    // Création de deux frères et sœurs leurs parents et un cousin
    personne* pere      = creerPersonne("Parent", "Pere"    , 1970, 1, EMPTY, EMPTY , EMPTY );
    personne* mere      = creerPersonne("Parent", "Mere"    , 1970, 2, EMPTY, EMPTY , EMPTY );
    personne* frere     = creerPersonne("Enfant", "Frere"   , 2000, 1, EMPTY, pere  , mere  );
    personne* soeur     = creerPersonne("Enfant", "Soeur"   , 2002, 2, EMPTY, pere  , mere  );
    personne* cousin    = creerPersonne("Cousin", "Cousin"  , 2001, 1, EMPTY, EMPTY , EMPTY );

    // Tests de la fonction frereEtSoeur
    if (frereEtSoeur(frere, soeur)){
        cout << "Test Frere et Soeur (frere, soeur): Succes (attendu)" << endl;
    } else {
        cout << "Test Frere et Soeur (frere, soeur): Echec (faux)" << endl;
    }
    cout << endl;
    if (frereEtSoeur(frere, cousin)){
        cout << "Test Frere et Soeur (frere, cousin): Succes (faux)" << endl;
    } else {
        cout << "Test Frere et Soeur (frere, cousin): Echec (attendu)" << endl;
    }

    delete pere;
    delete mere;
    delete frere;
    delete soeur;
    delete cousin;
}

void testGeneration() {
    cout << "-----------------------------------" << endl;
    cout << "testGeneration:" << endl;
    cout << endl;

    // Création d'une famille avec plusieurs générations
    personne* arriereGrandPere  = creerPersonne("ArriereGrand", "Pere"  , 1920, 1, EMPTY, EMPTY           , EMPTY    );
    personne* grandPere         = creerPersonne("Grand"       , "Pere"  , 1940, 1, EMPTY, EMPTY           , EMPTY    );
    personne* grandMere         = creerPersonne("Grand"       , "Mere"  , 1945, 2, EMPTY, arriereGrandPere, EMPTY    );
    personne* pere              = creerPersonne("Papa"        , "Papa"  , 1970, 1, EMPTY, grandPere       , grandMere);
    personne* enfant            = creerPersonne("Enfant"      , "Enfant", 2000, 1, EMPTY, pere            , EMPTY    );

    // Tests de la fonction generation
    int genEnfant = generation(enfant);
    int genPere = generation(pere);
    int genGrandPere = generation(grandPere);
    
    // Affichage des résultats
    cout << "Generation de l'enfant     : " << genEnfant << " (attendu: 4)" << endl;
    cout << "Generation du pere         : " << genPere << " (attendu: 3)" << endl;
    cout << "Generation du grand-pere   : " << genGrandPere << " (attendu: 1)" << endl;
    cout << "Generation de la grand-mere: " << generation(grandMere) << " (attendu: 2)" << endl;

    delete grandPere;
    delete grandMere;
    delete pere;
    delete enfant;
}

void testTailleArbre() {
    cout << "-----------------------------------" << endl;
    cout << "testTailleArbre:" << endl;
    cout << endl;

    // Création d'une famille avec plusieurs générations
    personne* GrandPere1 = creerPersonne("Grand" , "Pere1"   , 1940, 1, EMPTY, EMPTY     , EMPTY     );
    personne* GrandMere1 = creerPersonne("Grand" , "Mere1"   , 1945, 2, EMPTY, EMPTY     , EMPTY     );
    personne* GrandPere2 = creerPersonne("Grand" , "Pere2"   , 1940, 1, EMPTY, EMPTY     , EMPTY     );
    personne* GrandMere2 = creerPersonne("Grand" , "Mere2"   , 1945, 2, EMPTY, EMPTY     , EMPTY     );
    personne* mere       = creerPersonne("Maman" , "Maman"   , 1970, 2, EMPTY, GrandPere1, GrandMere1);
    personne* pere       = creerPersonne("Papa"  , "Papa"    , 1970, 1, EMPTY, GrandPere2, GrandMere2);
    personne* enfant     = creerPersonne("Enfant", "Enfant"  , 2000, 1, EMPTY, pere      , mere      );

    /* Si on veut compter la famille du conjoint, on peut créer un nouvelle famille et marier les deux enfants
       Mais il faut calculer l'arbre généalogique à partir du conjoint aussi.
       On ne peut pas le faire dans la fonction tailleArbre car cela créerait des boucles infinies. */

    // Effectuer les mariages
    // mariage(pere, mere);
    // mariage(GrandMere1, GrandPere1);
    // mariage(GrandMere2, GrandPere2);

    // Tests de la fonction tailleArbre
    int taille = tailleArbre(enfant);
    
    // Affichage des résultats
    cout << "Taille de l'arbre à partir de l'enfant : " << tailleArbre(enfant) << " (attendu: 7)" << endl;
    cout << "Taille de l'arbre à partir du père     : " << tailleArbre(pere) << " (attendu: 3)" << endl;

    delete GrandPere1;
    delete GrandMere1;
    delete GrandPere2;
    delete GrandMere2;
    delete mere;
    delete pere;
    delete enfant;
}

void testMariagePossible() {
    cout << "-----------------------------------" << endl;
    cout << "testMariagePossible:" << endl;
    cout << endl;

    // Création de deux personnes non apparentées
    personne* p1 = creerPersonne("Smith", "Alice", 1990, 2, EMPTY, EMPTY, EMPTY);
    personne* p2 = creerPersonne("Johnson", "Bob", 1988, 1, EMPTY, EMPTY, EMPTY);

    // Test de la fonction testMariage
    cout << "Test Mariage Possible entre deux personnes non apparentées:" << endl;
    if (testMariage(p1, p2)) {
        cout << "p1 + p2 : Succes (attendu)" << endl;
    } else {
        cout << "p1 + p2 : Echec (faux)" << endl;
    }
    cout << endl;

    // Création de deux personnes apparentées
    personne* parent = creerPersonne("Doe", "Parent", 1960, 1, EMPTY, EMPTY, EMPTY);
    personne* enfant1 = creerPersonne("Doe", "Enfant1", 1990, 2, EMPTY, parent, EMPTY);
    personne* enfant2 = creerPersonne("Doe", "Enfant2", 1992, 1, EMPTY, parent, EMPTY);

    // Test de la fonction testMariage pour des frères et sœurs
    cout << "Test Mariage Possible entre deux frères et sœurs:" << endl;
    if (testMariage(enfant1, enfant2)) {
        cout << "enfant1 + enfant2 : Succes (faux)" << endl;
    } else {
        cout << "enfant1 + enfant2 : Echec (attendu)" << endl;
    }

    delete p1;
    delete p2;
    delete parent;
    delete enfant1;
    delete enfant2;
}