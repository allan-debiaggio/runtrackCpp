#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>

class Joueur {
    int x;
    int y;
public:
    Joueur(int x_init = 0, int y_init = 0);
    void afficher() const;
    void deplacer(int dx, int dy);
};

#endif // JOUEUR_HPP
