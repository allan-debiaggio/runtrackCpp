#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Aquatique
{
protected:
    double speed;
    string unit;

public:
    Aquatique(double speed = 0.0, string unit = "m/s") : speed(speed), unit(unit) {}

    virtual void nage()
    {
        cout << "Je nage à une vitesse de " << speed << " " << unit << "." << endl;
    }

    void setSpeed(double newSpeed)
    {
        speed = newSpeed;
    }
};

class Terrestre
{
protected:
    double speed;
    string unit;

public:
    Terrestre(double speed = 0.0, string unit = "m/s") : speed(speed), unit(unit) {}

    virtual void marche()
    {
        cout << "Je marche à une vitesse de " << speed << " " << unit << "." << endl;
    }

    void setSpeed(double newSpeed)
    {
        speed = newSpeed;
    }
};

class Pingouin : public Aquatique, public Terrestre
{
private:
    string nom;
    double glideSpeed; // Vitesse de glisse

public:
    static vector<shared_ptr<Pingouin>> pingouins; // Vector statique pour contenir tous les pingouins

    Pingouin(string nom, double swimSpeed, double walkSpeed, double glideSpeed)
        : Aquatique(swimSpeed, "m/s"), Terrestre(walkSpeed, "m/s"), nom(nom), glideSpeed(glideSpeed)
    {
        // Ajouter le pingouin au vecteur lors de l'instanciation
        pingouins.push_back(shared_ptr<Pingouin>(this, [](Pingouin *) {}));
    }

    ~Pingouin()
    {
        // Retirer le pingouin du vecteur lors de la destruction
        pingouins.erase(remove_if(pingouins.begin(), pingouins.end(),
                                  [this](const shared_ptr<Pingouin> &p) { return p.get() == this; }),
                        pingouins.end());
    }

    void sePresenter()
    {
        cout << "Bonjour, je suis un pingouin et je m'appelle " << nom << "." << endl;
    }

    void nage() override
    {
        cout << nom << " nage à une vitesse de " << Aquatique::speed << " " << Aquatique::unit << "." << endl;
    }

    void marche() override
    {
        cout << nom << " marche à une vitesse de " << Terrestre::speed << " " << Terrestre::unit << "." << endl;
    }

    void glisse()
    {
        cout << nom << " glisse à une vitesse de " << glideSpeed << " m/s." << endl;
    }

    // Méthodes pour modifier les vitesses
    void setSwimSpeed(double newSpeed)
    {
        Aquatique::setSpeed(newSpeed);
    }

    void setWalkSpeed(double newSpeed)
    {
        Terrestre::setSpeed(newSpeed);
    }

    void setGlideSpeed(double newSpeed)
    {
        glideSpeed = newSpeed;
    }
};

// Initialisation du vecteur statique
vector<shared_ptr<Pingouin>> Pingouin::pingouins;

int main()
{
    {
        auto p1 = make_shared<Pingouin>("Pingu", 2.5, 1.2, 3.0);
        auto p2 = make_shared<Pingouin>("Pinga", 3.0, 1.5, 4.0);

        p1->sePresenter();
        p1->nage();
        p1->marche();
        p1->glisse();

        p2->sePresenter();
        p2->nage();
        p2->marche();
        p2->glisse();

        cout << "\nNombre de pingouins instanciés : " << Pingouin::pingouins.size() << endl;
    }

    // Après destruction des pingouins
    cout << "\nNombre de pingouins restants : " << Pingouin::pingouins.size() << endl;

    return 0;
}