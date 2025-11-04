#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct adresse {
    int num_rue;
    string rue;
    int code_postal;
    string ville;
};

struct Enseignant {
    int id;
    string nom;
    string prenom;
    int age;
    string grade;   // P, MC ou MA
    adresse adress1;
};

void saisitab(Enseignant T[], int taille) {
    for (int i = 0; i < taille; i++) {
        cout << "\n--- Enseignant " << i+1 << " ---\n";

        T[i].id = i + 1;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // vider buffer

        cout << "Entrer le nom : ";
        getline(cin, T[i].nom);

        cout << "Entrer le prénom : ";
        getline(cin, T[i].prenom);

        cout << "Entrer le grade (P / MC / MA) : ";
        getline(cin, T[i].grade);

        cout << "Entrer l'âge : ";
        cin >> T[i].age;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Entrer la rue : ";
        getline(cin, T[i].adress1.rue);

        cout << "Entrer le numéro de rue : ";
        cin >> T[i].adress1.num_rue;

        cout << "Entrer le code postal : ";
        cin >> T[i].adress1.code_postal;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Entrer la ville : ";
        getline(cin, T[i].adress1.ville);
    }
}

void NbEnsGrade(Enseignant T[], int n) {
    int nbP = 0, nbMC = 0, nbMA = 0;

    for (int i = 0; i < n; i++) {
        if (T[i].grade == "P")
            nbP++;
        else if (T[i].grade == "MC")
            nbMC++;
        else if (T[i].grade == "MA")
            nbMA++;
    }

    cout << "\nRésumé par grade :\n";
    cout << "Professeurs (P) : " << nbP << endl;
    cout << "Maîtres de Conférences (MC) : " << nbMC << endl;
    cout << "Maîtres Assistants (MA) : " << nbMA << endl;
}

int main() {
    Enseignant T[50];
    int n;

    cout << "Entrer le nombre d'enseignants (max 50) : ";
    cin >> n;

    saisitab(T, n);
    NbEnsGrade(T, n);

    return 0;
}
