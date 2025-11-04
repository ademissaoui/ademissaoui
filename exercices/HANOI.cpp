#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <concepts>
using namespace std;

class ToursHanoi {
private:
    int nombreDisques;
    vector<stack<int>> tours; // 0: A, 1: B, 2: C
    int deplacements;

public:
    ToursHanoi(int n) : nombreDisques(n), deplacements(0) {
        tours.resize(3);
        // Initialiser la tour A avec les disques
        for (int i = n; i >= 1; i--) {
            tours[0].push(i);
        }
    }

    void resoudre() {
        afficherEtat();
        resoudreRecursif(nombreDisques, 0, 2, 1);
        cout << "\n✓ Résolution complète en " << deplacements << " déplacements" << endl;
    }

private:
    void resoudreRecursif(int n, int source, int cible, int auxiliaire) {
        if (n == 1) {
            deplacerDisque(source, cible);
            return;
        }
        
        resoudreRecursif(n - 1, source, auxiliaire, cible);
        deplacerDisque(source, cible);
        resoudreRecursif(n - 1, auxiliaire, cible, source);
    }

    void deplacerDisque(int source, int cible) {
        if (tours[source].empty()) return;
        
        int disque = tours[source].top();
        tours[source].pop();
        tours[cible].push(disque);
        deplacements++;
        
        cout << "\nDéplacement " << deplacements << ": ";
        cout << "Disque " << disque << " de " << char('A' + source) 
             << " vers " << char('A' + cible) << endl;
        
        afficherEtat();
    }

    void afficherEtat() {
        cout << "\nÉtat actuel des tours :" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Tour " << char('A' + i) << ": ";
            afficherTour(tours[i]);
            cout << endl;
        }
        cout << string(30, '-') << endl;
    }

    void afficherTour(stack<int> tour) {
        stack<int> temp;
        while (!tour.empty()) {
            temp.push(tour.top());
            tour.pop();
        }
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
    }
};

int main() {
    int n;
    
    cout << " RESOLUTION DES TOURS DE HANOi" << endl;
    cout << "Entrez le nombre de disques : ";
    cin >> n;
    
    if (n <= 0 || n > 19) {
        cout << "Veuillez entrer un nombre entre 1 et 10." << endl;
        return 1;
    }
    
    ToursHanoi jeu(n);
    jeu.resoudre();
    
    return 0;
}