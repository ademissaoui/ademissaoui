#include "article.h"
article::article(){
    code = 0;
    quantite = 0;
    strcpy(designation,"");}
article::article(int code ,const char * designation ,int quantite){
    this->code = code;
    this->quantite=quantite;
    strcpy(this->designation,designation);

}
void article::set_code(int code){
    this->code = code;
}
int article::get_code(){
    return code;
}
void article::set_designation(const char* designation){
    strcpy(this->designation,designation);
}
const char* article::get_designation(){
    return designation;
}
void article::afficher(){
    cout<<"code"<<code<<endl;
    cout<<"designation"<<designation;
    cout<<"quantite"<<quantite;
}
void article::saisir(){
    cout<<"entrer le code:";
    cin>>code;
    cout<<"entrer la designation:";
    cin>>designation;
    cout<<"entrer la quantite:";
    cin>>quantite;
}
produit::produit():article(){
    strcpy(this->marque,"");
    revient = 0;
    nb_op = 0;
}
produit::produit(int code ,const char* designation ,int quantite,const char* marque , float revient, int nb_op) : article(code ,designation,quantite){
    strcpy(this->marque,marque);
    this->revient = revient;
    this->nb_op = nb_op;
}
void produit:: set_marque(const char * marque){
    strcpy(this->marque,marque);
}
const char* produit:: get_marque(){
    return marque;
}
void produit::set_revient(float revient){
    this->revient=revient;
}
float produit::get_revient(){
    return revient;
}
void produit::set_nb_op(int nb_op){
    this->nb_op=nb_op;
}
void produit::afficher(){
    article::afficher();
    cout<< "Marque"<<marque<<endl;
    cout<<"revient"<<revient<<endl;
    cout<<"nb_op"<<nb_op<<endl;
    for(int i=0;i<nb_op;i++){
        cout<<"operation "<<i+1<<":"<<tab[i]<<endl;
    }
}
void produit::saisir(){
    article::saisir();
    cout<<"saisir la marque"<<endl;
    cin>>marque;
    cout<<"saisir le revient"<<endl;
    cin>>revient;
    cout<<"saisir le nombre d'opertion"<<endl;
    cin>>nb_op;
    cout<<"saisir le nombre d'operation"<<endl;
    for(int i=0;i<nb_op;i++){
        cout<<"saisir l'operation "<<i+1<<":"<<endl;
        cin>>tab[i];
    }
};
void liste_produit::ajouter_produit(const produit& p){
    node* new_node = new node;
    new_node->data = p;
    new_node->next = head;
    head = new_node;
}
void liste_produit::afficher_produits(){
    node* current = head;
    while(current != nullptr){
        current->data.afficher();
        cout<< "---------------------"<<endl;
        current = current->next;
    }
}












