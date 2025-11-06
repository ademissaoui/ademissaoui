#ifndef ARTICLE_H
#define ARTICLE_H
#include <iostream>
#include <cstring>
using namespace std;
class article{
    private:
        int code;
        char designation[30];
        int quantite;
    public:
        article();
        article(int code,const char* designatition, int quantite);
        ~article();
        void set_code(int code);
        int get_code();
        void set_dte(int code);
        int get_qte();
        void set_designation(const char* designation);
        const char* get_designation();
        void afficher();
        void saisir();


};
class produit:public article{
    char marque [30];
    float revient;
    int nb_op;
    char tab[10][30];
    public:
        produit(int code , const char* designation , int quantite ,const char*  marque ,float revient,int nb_op);
        produit();
        ~produit();
        void set_marque(const char* marque);
        const char* get_marque();
        void set_revient(float revient);
        float get_revient();
        void set_nb_op(int nb_op);
        const char* get_nb_op();
        void afficher();
        void saisir();
};



#endif
