#include "GestionnaireComptes.h"

int main() {
    GestionnaireComptes gestionnaire;

    // Ajouter des comptes
    gestionnaire.ajouterCompte("001", "Alice", 1000);
    gestionnaire.ajouterCompte("002", "Bob", 500);

    // Afficher les comptes
    gestionnaire.afficherTousLesComptes();

    // Rechercher un compte et effectuer des transactions
    Compte* compteAlice = gestionnaire.rechercherCompte("001");
    if (compteAlice) {
        compteAlice->depot(200);
        compteAlice->retrait(300);
    }

    // Transférer de l'argent entre les comptes
    Compte* compteBob = gestionnaire.rechercherCompte("002");
    if (compteAlice && compteBob) {
        compteAlice->transfert(*compteBob, 100);
    }

    // Afficher les comptes après les transactions
    gestionnaire.afficherTousLesComptes();

    // Supprimer un compte
    gestionnaire.supprimerCompte("002");

    // Afficher les comptes après la suppression
    gestionnaire.afficherTousLesComptes();

    return 0;
}
