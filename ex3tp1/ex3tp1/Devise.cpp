#include "Devise.h"
#include <iostream>
Devise::Devise() :solde(0),nom("MAD")
{
}
Devise::Devise(double s, std::string n):solde(s),nom(n)
{
}

Devise Devise::toEuro() const
{
	double Msolde=0.0;
	if (nom == "MAD") {
		Msolde = solde * 0.27;
	}
	else if (nom == "USD") {
		Msolde = solde * 0.91;
	}
	else if (nom == "EUR") {
		Msolde = solde;
		std::cout << "Votre devise est déja en EURO"<< std::endl;
	}
	else {
		std::cout << "Le nom de devise est INCONU" << std::endl;

	}
	return Devise(Msolde, "EUR");
}

Devise Devise::toDollar() const
{
	double Msolde = 0.0;
	if (nom == "MAD") {
		Msolde = solde * 0.27;
	}
	else if (nom == "EUR") {
		Msolde = solde * 1.1;
	}
	else if (nom == "USD") {
		Msolde = solde;
		std::cout << "Votre devise est déja en EURO" << std::endl;
	}
	else {
		std::cout << "Le nom de devise est INCONU" << std::endl;

	}
	return Devise(Msolde, "USD");
}

Devise Devise::toDirham() const
{
	double Msolde=0.0;
	if (nom == "EUR") {
		Msolde = solde * 3.7;
	}
	else if (nom == "USD") {
		Msolde = solde * 3.7;
	}
	else if (nom == "MAD") {
		Msolde = solde;
		std::cout << "Votre devise est déja en DIRHAM" << std::endl;
	}
	else {
		std::cout << "Le nom de devise est INCONU" << std::endl;

	}
	return Devise( Msolde, "MAD");
}

void Devise::setSolde(double montant)
{
	solde = montant;
}

void Devise::setNom(std::string n) 
{
	nom = n;
}

double Devise::getSolde()const
{
	return solde;
}

std::string Devise::getNom()const
{
	return nom;
}

MAD::MAD(double s)
{
	setSolde(s);
	setNom("MAD");

}

USD::USD(double s)
{
	setSolde(s);
	setNom("USD");
}

EUR::EUR(double s)
{
	setSolde(s);
	setNom("EUR");
}
