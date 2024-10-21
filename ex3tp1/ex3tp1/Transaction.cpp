#include "Transaction.h"

Transaction::Transaction(std::string t, double s, std::string u):type(t),montant(s,u)
{
	
}

void Transaction::afficher() const
{
		std::cout << this->type << " de " << this->montant.getSolde() << " " << this->montant.getNom() << std::endl;
}

std::string Transaction::toString() const
{
	return this->type + " " + std::to_string(this->montant.getSolde()) + " " + this->montant.getNom();
}


