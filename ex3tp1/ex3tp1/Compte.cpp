#include "Compte.h"
#include <iostream>
//int Compte::identifiant = 0;


Compte::Compte() :  identifiant(""), proprietaire(""), solde(0.0, "MAD") 
{
}

Compte::Compte(std::string id, std::string p, double s, std :: string n): identifiant(id),proprietaire(p),solde(s,n)
{
}

void Compte::depot( const Devise& montant)
{ 
	std::string nameDevise = montant.getNom();
	if (this->solde.getNom() == nameDevise) {
	this->solde.setSolde(this->solde.getSolde() + montant.getSolde());
	transactions.emplace_back("Depot",montant.getSolde(), montant.getNom());
	}else {
		Devise nvSolde;
		std::cout << "Il faut faire un changement de devise puisque votre devise est en : " << this->solde.getNom() << " mais la devise a deposer est en "<< montant.getNom() << std::endl;
		if (this->solde.getNom() == "EUR") {
			nvSolde=montant.toEuro();
		}
		else if (this->solde.getNom() == "MAD") {
			nvSolde = montant.toEuro();
		}
		else {
			nvSolde = montant.toDollar();
		}
		this->solde.setSolde(this->solde.getSolde() + nvSolde.getSolde());
		transactions.emplace_back("Depot", montant.getSolde(), montant.getNom());
	}

	
}

void Compte::retrait(const Devise& montant)
{
	std::string nameDevise = montant.getNom();
	if (this->solde.getNom() == nameDevise) {
		if (this->solde.getSolde() > montant.getSolde()) {
			this->solde.setSolde(this->solde.getSolde() - montant.getSolde());
			transactions.emplace_back("Retrait", montant.getSolde(), montant.getNom());
		}else {
			std::cout << "votre solde est insufisant" << std::endl;
		}	
	}
	else {
		Devise nvSolde;
		std::cout << "Il faut faire un changement de devise puisque votre devise est en : " << this->solde.getNom() << " mais la devise a deposer est en " << montant.getNom() << std::endl;
		if (this->solde.getNom() == "EUR") {
			nvSolde = montant.toEuro();
		}
		else if (this->solde.getNom() == "MAD") {
			nvSolde = montant.toEuro();
		}
		else {
			nvSolde = montant.toDollar();
		}
		if (this->solde.getSolde() > nvSolde.getSolde()) {
			this->solde.setSolde(this->solde.getSolde() - nvSolde.getSolde());
			transactions.emplace_back("Retrait", montant.getSolde(), montant.getNom());
		}
		else {
			std::cout << "votre solde est insufisant" << std::endl;
		}
	}

}

void Compte::transfert(Compte& c, const Devise& montant)
{
	this->retrait(montant);
	c.depot(montant);
	transactions.emplace_back("Transfert",  montant.getSolde(), montant.getNom());
}

std::string Compte::getId() const
{
	return this->identifiant;
}

std::string Compte::getProp()const
{
	return this->proprietaire;
}

void Compte::afficherTransactions() const {
	std::cout << "+++++Transaction de comte d'ID : " << this->identifiant << std::endl;
	for (const auto& transaction : transactions) {
		 transaction.afficher();
	}
}

void Compte::sauvegarder(const std::string& nomFichier) const {
	std::ofstream fichier(nomFichier, std::ios::out);
	if (fichier.is_open()) {
		fichier << this->identifiant << "," << this->proprietaire << "," << solde.getSolde() << "," << solde.getNom() << "\n";

		for (const auto& transaction : transactions) {
			fichier << transaction.toString() << "\n";  // Utilisez `toString` au lieu de `afficher`
		}
		fichier.close();
	}
	else {
		std::cerr << "Erreur lors de l'ouverture du fichier pour la sauvegarde." << std::endl;
	}
}



void Compte::charger(const std::string& nomFichier) {
	std::ifstream fichier(nomFichier);
	if (fichier.is_open()) {
		std::string ligne;
		if (std::getline(fichier, ligne)) {
			std::stringstream ss(ligne);
			std::string soldeStr;
			std::getline(ss, this->identifiant, ','); // Lecture de l'identifiant
			std::getline(ss, this->proprietaire, ','); // Lecture du propriétaire
			std::getline(ss, soldeStr, ','); // Lecture du solde
			std::string deviseStr;
			std::getline(ss, deviseStr); // Lecture de la devise

			// Assurez-vous que setSolde et setNom existent dans Devise
			this->solde.setSolde(std::stod(soldeStr)); // Conversion de la chaîne en double
			this->solde.setNom(deviseStr);
		}
		fichier.close();
	}
	else {
		std::cerr << "Erreur lors de l'ouverture du fichier pour le chargement." << std::endl;
	}
}

void Compte::setSolde(const Devise& nouveauSolde) {
	this->solde = nouveauSolde;  
}

CompteEpargne::CompteEpargne(std::string id, std::string p, double s, std::string n, double in):Compte(id, p, s, n), interet(in)
{
}

void CompteEpargne::appliquerInteret()
{
	double montant;
	montant=this->getSoldeCompte().getSolde()* (this->interet / 100);
	this->depot(Devise(montant, this->getSoldeCompte().getNom()));
}

void CompteEpargne::afficher()
{
	std::cout << "Compte Epargne:" << std::endl;
	std::cout << "Identifiant: " << getId() << std::endl;
	std::cout << "Proprietaire: " << getProp() << std::endl;
	std::cout << "Solde: " << getSoldeCompte().getSolde() << " " << getSoldeCompte().getNom() << std::endl;
	std::cout << "Taux d'interet: " << interet  << "%" << std::endl; // Affichage en pourcentage

}

CompteCourant::CompteCourant(std::string id, std::string p, double s, std::string n, double dA): Compte(id,p,s,n),decouvertAutorise(dA)
{
}

void CompteCourant::retrait(const Devise& d)
{
	if (d.getSolde() <= (this->getSoldeCompte().getSolde() + this->decouvertAutorise)) {
		Compte::retrait(d);
	}
	else {
		std::cout << "Retrait impossible : solde insuffisant meme avec decouvert" << std::endl;

	}
}

void CompteCourant::afficher()
{
	std::cout << "Compte Courant:" << std::endl;
	std::cout << "Identifiant: " << getId() << std::endl;
	std::cout << "Proprietaire: " << getProp() << std::endl;
	std::cout << "Solde: " << getSoldeCompte().getSolde() << " " << getSoldeCompte().getNom() << std::endl;
	std::cout << "Decouvert autorise: " << decouvertAutorise << " " << getSoldeCompte().getNom() << std::endl;

}
