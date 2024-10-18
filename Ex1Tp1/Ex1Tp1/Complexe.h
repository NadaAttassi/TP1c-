#pragma once
class Complexe

{
private:
	double Re;
	double Img;
public:
	Complexe();
	Complexe (double, double);
	void afficher()const;
	double module()const;
	Complexe conjugué()const;
	Complexe operator + (const Complexe& b);
	Complexe& operator+(const double r);

	Complexe& operator-(const Complexe& z);
	Complexe& operator-(const double z);

	Complexe& operator*(const Complexe& z);
	Complexe& operator*(const double z);
	bool operator==(const Complexe&) const;

	Complexe& operator/(const double z);
	Complexe operator/(const Complexe& z) const;

};

