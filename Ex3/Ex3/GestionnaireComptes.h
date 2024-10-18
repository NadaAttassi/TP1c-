#include <iostream>
#include "Compte.h"

class GestionnaireComptes {
private:
    Compte** comptes;    // Tableau dynamique de pointeurs vers des comptes
    int nombreComptes;
    int capacite;

    // Redimensionner le tableau si nécessaire
    void redimensionner();

public:
    // Constructeur
    GestionnaireComptes(int tailleInitiale = 2);

    // Destructeur
    ~GestionnaireComptes();

    // Ajouter un compte
    void ajouterCompte(const std::string& id, const std::string& proprietaire, double soldeInitial);

    // Supprimer un compte
    void supprimerCompte(const std::string& id);

    // Rechercher un compte
    Compte* rechercherCompte(const std::string& id);

    // Afficher tous les comptes
    void afficherTousLesComptes() const;
};