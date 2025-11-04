#include <iostream>
#include <string>
using namespace std;

struct date {
    int jour;
    int mois;
    int annee;
};

struct piece {
    int code;
    string nom;
    date dte;
    double prix;
};

void saisiepiece(piece* p) {
    cout << "le code de la piece : " << endl;
    cin >> p->code;
    cin.ignore(); // vider le buffer avant getline
    cout << "le nom : " << endl;
    getline(cin, p->nom);
    cout << "le prix : " << endl;
    cin >> p->prix;
    cout << "la date (jour,mois,annee) : " << endl;
    cin >> p->dte.jour >> p->dte.mois >> p->dte.annee;
}

piece* creationtab(int* n) {
    cout << "entrer le nombre des pieces : " << endl;
    cin >> *n;
    piece* P = new piece[*n];
    for (int i = 0; i < *n; i++) {
        saisiepiece(&P[i]);
    }
    return P;
}

void affichepiece(int n, piece* P) {
    for (int i = 0; i < n; i++) {
        cout << "piece " << i + 1 << " : " << endl;
        cout << "code : " << P[i].code << endl;
        cout << "nom : " << P[i].nom << endl;
        cout << "prix : " << P[i].prix << endl;
        cout << "date fabrication : " << P[i].dte.jour << "/"
             << P[i].dte.mois << "/" << P[i].dte.annee << endl;
        cout << endl;
    }
}

void ajoutpiece(int& n, piece*& P) {
    piece* nP = new piece[n + 1];
    for (int i = 0; i < n; i++) {
        nP[i] = P[i];
    }
    cout << "saisir les informations de la nouvelle piece : " << endl;
    saisiepiece(&nP[n]);
    delete[] P;   // libérer ancien tableau
    P = nP;       // réaffecter
    n++;
}

void compareprix(int n, piece* P, double prix) {
    for (int i = 0; i < n; i++) {
        if (P[i].prix < prix) {
            cout << "code : " << P[i].code << endl;
            cout << "date  : " << P[i].dte.jour << "/"
                 << P[i].dte.mois << "/" << P[i].dte.annee << endl;
            cout << "nom : " << P[i].nom << endl;
            cout << "prix : " << P[i].prix << endl;
            cout << endl;
        }
    }
}

void supprimer(int& n, piece*& P, string nom) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (P[i].nom == nom) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "piece introuvable !" << endl;
        return;
    }

    piece* newtab = new piece[n - 1];
    for (int i = 0, j = 0; i < n; i++) {
        if (i != index) {  // if, pas while !
            newtab[j++] = P[i];
        }
    }

    delete[] P;
    P = newtab;
    n--;
    cout << "piece supprimee avec succes." << endl;
}

int choix() {
    cout << "--------------------- MENU ---------------------" << endl;
    cout << "1 : creer tableau de pieces" << endl;
    cout << "2 : afficher le tableau de pieces" << endl;
    cout << "3 : ajouter une nouvelle piece" << endl;
    cout << "4 : chercher les pieces moins cheres qu'un prix" << endl;
    cout << "5 : supprimer une piece du tableau" << endl;
    cout << "-1 : arreter l'execution" << endl;
    cout << "Votre choix : ";
    int c;
    cin >> c;
    return c;
}

int main() {
    int n = 0;
    double prix;
    piece* P = nullptr;

    while (true) {
        int x = choix();
        switch (x) {
        case 1:
            if (P) delete[] P; // si tableau déjà existant
            P = creationtab(&n);
            break;
        case 2:
            if (P) affichepiece(n, P);
            else cout << "Tableau vide !" << endl;
            break;
        case 3:
            if (P) ajoutpiece(n, P);
            else cout << "Creer d'abord le tableau." << endl;
            break;
        case 4:
            if (P) {
                cout << "donner le prix : ";
                cin >> prix;
                compareprix(n, P, prix);
            } else {
                cout << "Tableau vide !" << endl;
            }
            break;
        case 5: {
            if (P) {
                string nom;
                cin.ignore(); // éviter problème getline
                cout << "entrer le nom de la piece a supprimer : ";
                getline(cin, nom);
                supprimer(n, P, nom);
            } else {
                cout << "Tableau vide !" << endl;
            }
            break;
        }
        case -1:
            if (P) delete[] P;
            cout << "Fin du programme." << endl;
            return 0;
        default:
            cout << "Choix invalide !" << endl;
        }
    }
}
