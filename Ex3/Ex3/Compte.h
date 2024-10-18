#include <iostream>
#include <string>

class Compte {
private:
    std::string identifiant;
    std::string proprietaire;
    double solde;

public:
    // Constructeur
    Compte(const std::string& id, const std::string& prop, double soldeInitial);

    // Obtenir l'identifiant du compte
    std::string getIdentifiant() const;

    // Obtenir le propriétaire du compte
    std::string getProprietaire() const;


    // Obtenir le solde du compte
    double getSolde() const;

    // Afficher les informations du compte
    void afficherInfos() const;

    // Dépôt d'argent sur le compte
    void depot(double montant);

    // Retrait d'argent du compte
    void retrait(double montant);
    // Transfert d'argent vers un autre compte
    void transfert(Compte& destinataire, double montant);
};
