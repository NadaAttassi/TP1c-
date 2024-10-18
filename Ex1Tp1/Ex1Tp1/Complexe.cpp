#include "Complexe.h"

#include <iostream>
#include <cmath>  
Complexe::Complexe()
{
	this->Re = 0;
	this->Img = 0;
}
Complexe::Complexe(double a, double b):Re(a), Img(b)
{
}

void Complexe::afficher() const
{
	std::cout << "partie reele :" << this->Re << "partie imaginaire:" << this->Img << "\n";

}

double Complexe::module() const
{
	return sqrt(pow(this->Re, 2) + pow(this->Img, 2));
}

Complexe Complexe::conjugué() const
{
		return Complexe(this->Re, -this->Img); 

}

Complexe Complexe::operator+(const Complexe& z)
{
	return Complexe(this->Re + z.Re, this->Img + z.Img);
}

Complexe& Complexe::operator+(const double r)
{
	Complexe* z2 = new Complexe;
	z2->Re = this->Re + r;
	return *z2;
}

Complexe& Complexe::operator-(const Complexe& z)
{
	Complexe* z1 = new Complexe;
	z1->Re = this->Re - z.Re;
	z1->Img = this->Img - z.Img;
	return *z1;

}

Complexe& Complexe::operator-(const double a)
{
	Complexe* z1 = new Complexe;
	z1->Re = this->Re - a;
	return *z1;
}

Complexe& Complexe::operator*(const Complexe& z)
{
	Complexe* z1 = new Complexe;
	z1->Re = this->Re * z.Re;
	z1->Img = this->Img * z.Img;
	return *z1;
}

Complexe& Complexe::operator*(const double z)
{
	Complexe* z1 = new Complexe;
	z1->Re = this->Re * z;
	return *z1;
}

bool Complexe::operator==(const Complexe& z) const
{
	return this->Re == z.Re && this->Img == z.Img;
}

Complexe& Complexe::operator/(const double z)
{
	if (z == 0) {
		throw std::invalid_argument("Division by zero");
	}

	Complexe* z1 = new Complexe;
	z1->Re = this->Re / z;
	z1->Img = this->Img / z;
	return *z1;
}

Complexe Complexe::operator/(const Complexe& z) const
{
	if (z.Re == 0 && z.Img == 0) {
		throw std::invalid_argument("Division by zero");
	}

	double denominateur = z.Re * z.Re + z.Img * z.Img;

	
	double re_part = (this->Re * z.Re + this->Img * z.Img) / denominateur;
	double img_part = (this->Img * z.Re - this->Re * z.Img) / denominateur;

	
	return Complexe(re_part, img_part);
}


