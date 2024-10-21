#pragma once
#include <vector>
#include "Compte.h"
#include <algorithm> // pour la suppression des comptes
#include <fstream>
#include <sstream>
#include <iostream>

class Banque {
private:
    std::vector<Compte> comptes;

public:
    // Ajout d'un nouveau compte
    void ajouterCompte(const Compte& compte);

    // Suppression d'un compte par identifiant
    void supprimerCompte(const std::string& id);

    // Mise à jour des informations d'un compte (ex : solde ou propriétaire)
    void mettreAJourCompte(const std::string& id, const Devise& nouveauSolde);

    // Recherche d'un compte par identifiant
    Compte* chercherCompte(const std::string& id);

    // Affichage des informations de tous les comptes
    void afficherComptes() const;

    // Sauvegarde de tous les comptes dans un fichier
    void sauvegarderTousLesComptes(const std::string& nomFichier) const;

    // Chargement de tous les comptes depuis un fichier
    void chargerTousLesComptes(const std::string& nomFichier);
};
