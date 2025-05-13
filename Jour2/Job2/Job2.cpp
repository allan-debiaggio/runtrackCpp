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
    Pingouin(string nom, double swimSpeed, double walkSpeed, double glideSpeed)
        : Aquatique(swimSpeed, "m/s"), Terrestre(walkSpeed, "m/s"), nom(nom), glideSpeed(glideSpeed) {}

    Pingouin(const Pingouin &other)
        : Aquatique(other.Aquatique::speed, "m/s"),
          Terrestre(other.Terrestre::speed, "m/s"),
          nom(other.nom),
          glideSpeed(other.glideSpeed) {}

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

int main()
{
    Pingouin p1("Pingu", 2.5, 1.2, 3.0);

    p1.sePresenter();
    p1.nage();
    p1.marche();
    p1.glisse();

    // Utilisation du constructeur de copie
    Pingouin p2 = p1;
    p2.setSwimSpeed(3.0);
    p2.setWalkSpeed(1.5);
    p2.setGlideSpeed(4.0);

    cout << "\nCopie de Pingu : " << endl;
    p2.sePresenter();
    p2.nage();
    p2.marche();
    p2.glisse();

    return 0;
}