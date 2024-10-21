#pragma once
#include <string>
#include "Devise.h"
#include <vector>
#include "Transaction.h"
#include <fstream>>
#include <sstream>
#include <iostream>
class Compte
{
private:
	std::string identifiant;
	std::string proprietaire;
	Devise solde;
	std::vector<Transaction> transactions;
public:
	Compte();
	Compte(std::string,std::string, double,std::string);
	void depot(const Devise& solde);
	void retrait(const Devise& solde);
	void transfert(Compte&, const Devise& solde);
	std::string getId() const;
	std::string getProp() const;
	Devise getSoldeCompte() const { return this->solde; }
	void afficherTransactions()const;
	void sauvegarder(const std::string& nomFichier) const;
	void  charger(const std::string& nomFichier) ;
	void setSolde(const Devise& nouveauSolde);

};

class CompteEpargne : public Compte {
private:
	double interet;
public:
	CompteEpargne(std::string id, std::string p, double s, std::string n, double in);
	void appliquerInteret();
	void afficher();
};

class CompteCourant : public Compte {
private:
	double decouvertAutorise;
public:
	CompteCourant(std::string id, std::string p, double s, std::string n, double dA);
	void retrait (const Devise&);
	void afficher();
};
