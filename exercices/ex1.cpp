#include <iostream>
#include <string>
using namespace std;

// Définition de la structure Appartement
struct Appartement {
    int numero;
    float surface;
    string ville;
    float prix;
};

// Fonction pour saisir les appartements
Appartement* SaisieAppart(int* n) {
    do {
        cout << "Entrez le nombre d'appartements (2-10): ";
        cin >> *n;
    } while(*n < 2 || *n > 10);

    // Allocation dynamique du tableau d'appartements
    Appartement* T = new Appartement[*n];

    // Saisie des informations
    for (int i = 0; i < *n; i++) {
        cout << "\nAppartement " << i+1 << ":\n";
        cout << "Numero: ";
        cin >> T[i].numero;
        cout << "Surface: ";
        cin >> T[i].surface;
        cin.ignore(); // pour consommer le '\n'
        cout << "Ville: ";
        getline(cin, T[i].ville);
        cout << "Prix: ";
        cin >> T[i].prix;
    }

    return T;
}

// Fonction pour afficher les appartements respectant le budget
void AfficheAppart(int n, Appartement* T, float* budget) {
    do {
        cout << "\nEntrez le budget du client (positif): ";
        cin >> *budget;
    } while(*budget <= 0);

    cout << "\nAppartements correspondant au budget:\n";
    for(int i = 0; i < n; i++) {
        if(T[i].prix <= *budget) {
            cout << "\nAppartement " << i+1 << ":\n";
            cout << "Numero: " << T[i].numero << "\n";
            cout << "Surface: " << T[i].surface << "\n";
            cout << "Ville: " << T[i].ville << "\n";
            cout << "Prix: " << T[i].prix << "\n";
        }
    }
}

int main() {
    int n;
    float budget;
    Appartement* T;

    T = SaisieAppart(&n);
    AfficheAppart(n, T, &budget);

    // Libération de la mémoire dynamique
    delete[] T;

    return 0;
}
