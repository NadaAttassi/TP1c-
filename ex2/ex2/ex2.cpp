#include <iostream>
#include "Point.h"
#include "Cercle.h"

int main() {
    // Création de points
    Point p1 = Point::creerPoint(0, 0);
    Point p2 = Point::creerPoint(3, 4);

    // Création de cercles
    Cercle c1(5.0, p1);
    Cercle c2(5.0, p2);

    // Affichage des cercles
    c1.afficher();
    c2.afficher();

    // Modification du rayon du premier cercle
    c1.setRayon(10.0);
    c1.afficher();

    // Translation du centre du premier cercle
    c1.translaterCentre(2.0, 2.0);
    c1.afficher();

    // Calcul de la surface et du périmètre
    std::cout << "Surface du cercle c1: " << c1.surface() << std::endl;
    std::cout << "Périmètre du cercle c1: " << c1.perimetre() << std::endl;

    // Vérification de l'égalité entre deux cercles
    if (c1 == c2) {
        std::cout << "Les cercles c1 et c2 sont égaux" << std::endl;
    }
    else {
        std::cout << "Les cercles c1 et c2 sont différents" << std::endl;
    }

    // Vérification si un point appartient au cercle
    if (c1.contientPoint(p2)) {
        std::cout << "Le point p2 appartient au cercle c1" << std::endl;
    }
    else {
        std::cout << "Le point p2 n'appartient pas au cercle c1" << std::endl;
    }

    return 0;
}
