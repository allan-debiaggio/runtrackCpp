#include "Joueur.hpp"
#include <iostream>

Joueur::Joueur(int x_init, int y_init) : x(x_init), y(y_init) {}

void Joueur::afficher() const {
    std::cout << "Position du joueur : (" << x << ", " << y << ")" << std::endl;
}

void Joueur::deplacer(int dx, int dy) {
    x += dx;
    y += dy;
}

int main() {
    Joueur joueur(0, 0);
    joueur.afficher();
    joueur.deplacer(2, 3);
    joueur.afficher();
    joueur.deplacer(-1, 4);
    joueur.afficher();
    return 0;
}
