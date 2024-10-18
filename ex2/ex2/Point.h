#pragma once
#include <iostream>

class Point {
private:
    double x, y;

    // Constructeurs privés
    Point(double x, double y) : x(x), y(y) {}

public:
    // Méthode statique pour créer une instance de Point
    static Point creerPoint(double x, double y) {
        return Point(x, y);
    }

    // Méthodes d'accès
    double getX() const { return x; }
    double getY() const { return y; }

    // Méthode pour translater le point
    void translater(double dx, double dy) {
        x += dx;
        y += dy;
    }

    // Affichage du point
    void afficher() const {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
};
