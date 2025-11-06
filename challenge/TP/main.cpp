#include "article.h"
int main(){
    liste_produit lp;
    produit p1(101,"Laptop",50,"Dell",800.5,2);
    produit p2(102,"Smartphone",100,"Samsung",500.0,3);
    lp.ajouter_produit(p1);
    lp.ajouter_produit(p2);
    cout<<"Liste des produits:"<<endl;
    lp.afficher_produits();
    return 0;
}
