#pragma once
#include <iostream> 
#include <string>
#include "Devise.h"
class Transaction
{
private:
	std::string type;
	Devise montant;
public:

	Transaction(std::string t, double s, std::string u);
	void afficher() const;
	std::string toString() const;
};

