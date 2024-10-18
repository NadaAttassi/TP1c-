// Ex1Tp1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "Complexe.h"

int main()
{
    // Création de deux nombres complexes
    Complexe z1(3, 4);
    Complexe z2(1, 2);

    // Affichage des nombres complexes
    z1.afficher();
    z2.afficher();

    // Addition des deux nombres complexes
    Complexe somme = z1 + z2;
    somme.afficher();

    // Soustraction
    Complexe difference = z1 - z2;
    difference.afficher();

    // Multiplication
    Complexe produit = z1 * z2;
    produit.afficher();

    // Division
    
        Complexe division = z1 / z2;
        division.afficher();


    // Module
    std::cout << "Module de z1: " << z1.module() << "\n";

    // Conjugué
    Complexe conj = z1.conjugué();
    conj.afficher();

    return 0;
}
