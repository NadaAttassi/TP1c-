#include "GestionnaireComptes.h"

void GestionnaireComptes::redimensionner()
{
    int nouvelleCapacite = capacite * 2;
    Compte** nouveauxComptes = new Compte * [nouvelleCapacite];

    for (int i = 0; i < nombreComptes; i++) {
        nouveauxComptes[i] = comptes[i];
    }

    delete[] comptes;
    comptes = nouveauxComptes;
    capacite = nouvelleCapacite;
}

GestionnaireComptes::GestionnaireComptes(int tailleInitiale)
{
    capacite = tailleInitiale;
    comptes = new Compte * [capacite];
    nombreComptes = 0;
}

GestionnaireComptes::~GestionnaireComptes()
{
    for (int i = 0; i < nombreComptes; i++) {
        delete comptes[i];
    }
    delete[] comptes;
}

void GestionnaireComptes::ajouterCompte(const std::string& id, const std::string& proprietaire, double soldeInitial)
{
    if (nombreComptes == capacite) {
        redimensionner();
    }
    comptes[nombreComptes] = new Compte(id, proprietaire, soldeInitial);
    nombreComptes++;
    std::cout << "Compte ajouté avec succès: " << id << std::endl;
}

void GestionnaireComptes::supprimerCompte(const std::string& id)
{
    for (int i = 0; i < nombreComptes; i++) {
        if (comptes[i]->getIdentifiant() == id) {
            delete comptes[i];
            comptes[i] = comptes[nombreComptes - 1];
            nombreComptes--;
            std::cout << "Compte supprimé: " << id << std::endl;
            return;
        }
    }
    std::cout << "Compte non trouvé." << std::endl;
}

Compte* GestionnaireComptes::rechercherCompte(const std::string& id)
{
    for (int i = 0; i < nombreComptes; i++) {
        if (comptes[i]->getIdentifiant() == id) {
            return comptes[i];
        }
    }
    std::cout << "Compte non trouvé." << std::endl;
    return nullptr;
}

void GestionnaireComptes::afficherTousLesComptes() const
{
    for (int i = 0; i < nombreComptes; i++) {
        comptes[i]->afficherInfos();
    }
}

