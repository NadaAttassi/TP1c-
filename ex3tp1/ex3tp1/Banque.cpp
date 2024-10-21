#include "Banque.h"

// Ajout d'un nouveau compte
void Banque::ajouterCompte(const Compte& compte) {
    comptes.push_back(compte);
    std::cout << "Compte ajout� avec succ�s : " << compte.getId() << std::endl;
}

// Suppression d'un compte par identifiant
void Banque::supprimerCompte(const std::string& id) {
    auto it = std::remove_if(comptes.begin(), comptes.end(), [&](const Compte& c) {
        return c.getId() == id;
        });

    if (it != comptes.end()) {
        comptes.erase(it, comptes.end());
        std::cout << "Compte supprim� avec succ�s : " << id << std::endl;
    }
    else {
        std::cerr << "Erreur : Compte non trouv� pour suppression : " << id << std::endl;
    }
}

// Mise � jour des informations d'un compte (ex : solde ou propri�taire)
void Banque::mettreAJourCompte(const std::string& id, const Devise& nouveauSolde) {
    for (auto& compte : comptes) {
        if (compte.getId() == id) {
            compte.depot(nouveauSolde); // Mettre � jour le solde (ou ajouter plus d'options pour d'autres informations)
            std::cout << "Compte mis � jour : " << id << std::endl;
            return;
        }
    }
    std::cerr << "Erreur : Compte non trouv� pour mise � jour : " << id << std::endl;
}

// Recherche d'un compte par identifiant
Compte* Banque::chercherCompte(const std::string& id) {
    for (auto& compte : comptes) {
        if (compte.getId() == id) {
            return &compte; // Retourne un pointeur vers le compte trouv�
        }
    }
    std::cerr << "Erreur : Compte non trouv� : " << id << std::endl;
    return nullptr; // Retourne nullptr si le compte n'est pas trouv�
}

// Affichage des informations de tous les comptes
void Banque::afficherComptes() const {
    for (const auto& compte : comptes) {
        std::cout << "Identifiant : " << compte.getId() << ", Propri�taire : " << compte.getProp()
            << ", Solde : " << compte.getSoldeCompte().getSolde() << " " << compte.getSoldeCompte().getNom() << std::endl;
    }
}

// Sauvegarde de tous les comptes dans un fichier
void Banque::sauvegarderTousLesComptes(const std::string& nomFichier) const {
    std::ofstream fichier(nomFichier);
    if (fichier.is_open()) {
        for (const auto& compte : comptes) {
            compte.sauvegarder(nomFichier); // Appelle la m�thode de sauvegarde de chaque compte
        }
        fichier.close();
        std::cout << "Tous les comptes ont �t� sauvegard�s." << std::endl;
    }
    else {
        std::cerr << "Erreur lors de l'ouverture du fichier pour sauvegarder les comptes." << std::endl;
    }
}

// Chargement de tous les comptes depuis un fichier
void Banque::chargerTousLesComptes(const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    if (fichier.is_open()) {
        std::string ligne;
        while (std::getline(fichier, ligne)) {
            Compte compte;
            std::stringstream ss(ligne);
            compte.charger(ss.str()); // Appelle la m�thode de chargement du compte
            comptes.push_back(compte);
        }
        fichier.close();
        std::cout << "Tous les comptes ont �t� charg�s." << std::endl;
    }
    else {
        std::cerr << "Erreur lors de l'ouverture du fichier pour charger les comptes." << std::endl;
    }
}
