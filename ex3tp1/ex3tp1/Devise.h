#pragma once
#include <string>
class Devise
{  
private:
	double solde;
	std::string nom;
public:
	Devise();
	Devise(double, std::string);
	Devise toEuro() const;
	Devise toDollar() const;
	Devise toDirham() const;
	void setSolde(double);
	void setNom(std::string);
	double getSolde()const;
	std::string getNom()const;
};
class MAD :public Devise {
public:
	MAD(double);
};

class USD :public Devise {
public:
	USD(double);
};

class EUR :public Devise {
public:
	EUR(double);
};
