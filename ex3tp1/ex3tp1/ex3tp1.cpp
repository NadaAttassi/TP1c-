#include <iostream>
#include "Banque.h"
#include "Devise.h" // Assurez-vous que Devise est correctement défini
#include "Compte.h"

int main() {
    Banque maBanque;

    // Création de quelques comptes
    CompteEpargne compteEpargne("1234", "Alice", 1000.0, "EUR", 1.5);
    CompteCourant compteCourant("5678", "Bob", 500.0, "EUR", 200.0);

    // Ajout des comptes à la banque
    maBanque.ajouterCompte(compteEpargne);
    maBanque.ajouterCompte(compteCourant);

    // Affichage des comptes
    std::cout << "Liste des comptes :\n";
    maBanque.afficherComptes();

    // Mise à jour du solde d'un compte
    Devise nouveauSolde(500.0, "EUR"); // Exemple de nouvelle devise
    maBanque.mettreAJourCompte("1234", nouveauSolde); // Mettre à jour le compte d'Alice

    // Affichage des comptes après mise à jour
    std::cout << "\nListe des comptes après mise à jour :\n";
    maBanque.afficherComptes();

    // Sauvegarde des comptes dans un fichier
    maBanque.sauvegarderTousLesComptes("comptes.txt");

    // Chargement des comptes depuis un fichier (par exemple)
    Banque autreBanque;
    autreBanque.chargerTousLesComptes("comptes.txt");

    // Affichage des comptes chargés
    std::cout << "\nComptes chargés depuis le fichier :\n";
    autreBanque.afficherComptes();

    return 0;
}
