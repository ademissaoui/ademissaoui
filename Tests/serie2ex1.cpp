#include <iostream>
using namespace std;

class Vecteur {
private:
    int n;          // dimension du vecteur
    int* t;         // tableau dynamique qui contient les composantes

public:
    // ---------- Constructeurs ----------
    // Constructeur par défaut
    Vecteur() {
        n = 0;
        t = nullptr;
    }

    // Constructeur avec dimension donnée
    Vecteur(int dim) {
        n = dim;
        t = new int[n];
        for (int i = 0; i < n; i++) {
            t[i] = 0;   // initialisation à 0
        }
    }
    // ---------- Destructeur ----------
    ~Vecteur() {
        delete[] t;
    }

    // ---------- Fonctions membres ----------
    void init() {
        cout << "Donner les " << n << " composantes du vecteur : ";
        for (int i = 0; i < n; i++) {
            cin >> t[i];
        }
    }

    void view(){
        cout << "[ ";
        for (int i = 0; i < n; i++) {
            cout << t[i] << " ";
        }
        cout << "]" << endl;
    }
    int produit (Vecteur v){
        int res = 0;
        if (v.n!= n)
        {
            cout << "impossible de faire le produit" << endl;
        }else{
            for (int i = 0; i < n; i++)
            {
                res = res + (v.t[i]*t[i]);
            }
        }
        return res ;
    
        }
        void coincide(Vecteur *v){
            int i;
            for ( i = 0; i < n; i++)
            {
                if (t[i] != v->t[i])
                {
                    cout << "les vecteurs ne coincide pas" << endl;
                    break;  
                }
        }
        if (i == n-1)
        {
            cout << "les vecteurs coincide" << endl;
        }
    }

};
int main (){
    Vecteur * v3 ;
    Vecteur v4 = Vecteur(5);
    v4.init();
    v4.view();
    v3 = &v4;
    Vecteur v1 = Vecteur(3);
    Vecteur v2 = Vecteur(3);
    v1.init();
    v2.init();
    v1.view();
    v2.view();
    cout << v1.produit(v2) << endl;
    v2.coincide(v3);

}