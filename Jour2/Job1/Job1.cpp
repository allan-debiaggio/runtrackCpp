#include <iostream>
#include <string>

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
};

class Pingouin : public Aquatique, public Terrestre
{
private:
    string nom;

public:
    Pingouin(string nom, double swimSpeed, double walkSpeed)
        : Aquatique(swimSpeed, "m/s"), Terrestre(walkSpeed, "m/s"), nom(nom) {}

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
};

int main()
{
    Pingouin p("Pingu", 2.5, 1.2);

    p.sePresenter();
    p.nage();
    p.marche();

    return 0;
}

