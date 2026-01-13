#include "type_def.h"
#include "utils.h"
#include <iostream>

#define EMPTY nullptr

void testAfficherPersonne();
void testMariage();
void testAncetre ();

int main() {
    testAfficherPersonne();
    testMariage();
    testAncetre ();
    return 0;
}

// Tests

void testAfficherPersonne() {
    cout << "-----------------------------------" << endl;
    cout << "Test Afficher Personne:" << endl;
    cout << endl;

    personne* p = creerPersonne("Doe", "John", 1980, 1, EMPTY, EMPTY, EMPTY);

    afficherPersonne(p);

    delete p;
}

void testMariage() {
    cout << "-----------------------------------" << endl;
    cout << "Test Mariage:" << endl;
    cout << endl;

    personne* p1 = creerPersonne("Smith", "Jane", 1992, 2, EMPTY, EMPTY, EMPTY);
    personne* p2 = creerPersonne("Brown", "Mike", 1990, 1, EMPTY, EMPTY, EMPTY);

    mariage(p1, p2);

    afficherPersonne(p1);
    afficherPersonne(p2);

    delete p1;
    delete p2;
}

void testAncetre (){
    cout << "-----------------------------------" << endl;
    cout << "Test Ancetre:" << endl;
    cout << endl;

    personne* grandPere1 = creerPersonne("Grand", "Pere 1", 1950, 1, EMPTY, EMPTY, EMPTY);
    personne* grandPere2 = creerPersonne("Grand", "Pere 2", 1950, 1, EMPTY, EMPTY, EMPTY);
    personne* grandMere1 = creerPersonne("Grand", "Mere 1", 1950, 2, EMPTY, EMPTY, EMPTY);
    personne* grandMere2 = creerPersonne("Grand", "Mere 2", 1950, 2, EMPTY, EMPTY, EMPTY);
    personne* pere = creerPersonne("Super", "Papa", 1975, 2, EMPTY, grandPere1, grandMere1);
    personne* mere = creerPersonne("Super", "Maman", 1975, 2, EMPTY, grandPere2, grandMere2);
    personne* enfant = creerPersonne("Petit", "Enfant", 2000, 1, EMPTY, pere, EMPTY);

    bool res = verifierAncetres(enfant, grandPere1);

    if (res) {
        cout << "Test Ancetre: Succes" << endl;
    } else {
        cout << "Test Ancetre: Echec" << endl;
    }

    delete grandPere1;
    delete grandPere2;
    delete grandMere1;
    delete grandMere2;
    delete pere;
    delete mere;
    delete enfant;
}