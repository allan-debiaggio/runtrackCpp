#include <iostream>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    switch(n)
    {
        case 0 :
            cout << "Nul\n";
        case 1 :

        case 2 : 
            cout << "Petit\n";
            break;
        case 3 :
        case 4 : 
        case 5 :
            cout << "Moyen\n";
        default :
            cout << "Grand\n";
    }

    return 0;
}

/*
Résultats : 
n = 0 : 
Nul
Petit
(Tous les cas sont exécutés jusqu'au break)

n = 1 :
Petit
Le seul cas à exécuter est le cas 2 avec le break

n = 4 :
Moyen
Grand
Tous les cas restants sont exécutés vu qu'il n'y a pas de break

n = 10 : 
Grand
Le seul cas exécuté est "Default"

n = -5 :
Grand
Le seul cas exécuté est "Default"

*/