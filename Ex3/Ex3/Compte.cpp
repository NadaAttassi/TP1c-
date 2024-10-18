#include "Compte.h"

Compte::Compte(const std::string& id, const std::string& prop, double soldeInitial) : identifiant(id), proprietaire(prop), solde(soldeInitial) {}
std::string Compte::getIdentifiant() const
{
    return identifiant;
}

std::string Compte::getProprietaire() const
{
    return proprietaire;
}

double Compte::getSolde() const
{
    return solde;
}

void Compte::afficherInfos() const
{
    std::cout << "Identifiant: " << identifiant << ", Propriétaire: " << proprietaire
        << ", Solde: " << solde << std::endl;
}

void Compte::depot(double montant)
{
    if (montant > 0) {
        solde += montant;
        std::cout << "Depot de " << montant << " effectue. Nouveau solde: " << solde << std::endl;
    }
    else {
        std::cout << "Montant de depot invalide." << std::endl;
    }
}

void Compte::retrait(double montant)
{
    if (montant > 0 && montant <= solde) {
        solde -= montant;
        std::cout << "Retrait de " << montant << " effectué. Nouveau solde: " << solde << std::endl;
    }
    else if (montant > solde) {
        std::cout << "Fonds insuffisants pour ce retrait." << std::endl;
    }
    else {
        std::cout << "Montant de retrait invalide." << std::endl;
    }
}

void Compte::transfert(Compte& destinataire, double montant)
{
    if (montant > 0 && montant <= solde) {
        solde -= montant;
        destinataire.depot(montant);
        std::cout << "Transfert de " << montant << " vers " << destinataire.getProprietaire()
            << " effectué. Nouveau solde: " << solde << std::endl;
    }
    else {
        std::cout << "Transfert invalide. Vérifiez le montant ou les fonds disponibles." << std::endl;
    }
}

