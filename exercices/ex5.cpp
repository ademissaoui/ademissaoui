#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;

struct DATA_DOCUMENT
{
    char auteur [30];
    int annee;
    int nbpage;
};
struct DATA_NOUED
{
    long id;
    int type;
    char titre [50];
    DATA_DOCUMENT* doc;
};
struct arbre
{
    arbre* frere;
    arbre* fils ;
    DATA_NOUED data;
};
typedef arbre* arbr;
arbr seek_noeud(arbr racine , long id){
    if (racine->data.id== id)
    {
        return racine;
    }
    arbr found = seek_noeud(racine->fils,id);
    if (found)
    {
        return found;
    }
    return seek_noeud(racine->frere,id);
}
void insert (arbre* racine, long id_pere , DATA_NOUED d,DATA_DOCUMENT* dox){
    arbr newnode = new arbre;
    newnode->data.doc=dox;
    newnode->data = d;
    newnode->fils=nullptr;
    newnode->frere=nullptr;
    arbre* per = seek_noeud(racine,id_pere);
    if (!per)
    {
        cout << "pere introuvable!!" << endl;
        delete newnode;
    }
    
    arbre* temp = per->fils;
    while (temp->frere != nullptr)
    {
        temp = temp->frere;
    }
    temp->frere= newnode;
}
void save_annee(arbr racine, int annee , int nb_pg, char* name_file){
    if (!racine)
    {
        return;
    }
    
    ofstream file (name_file,ios::out);
    if (racine->data.type == 2 && racine->data.doc != nullptr)
    {
        if (racine->data.doc->annee== annee && racine->data.doc->nbpage< nb_pg)
    {
        file << racine->data.titre << racine->data.doc->auteur << racine->data.doc->nbpage;
    }
    }
    file.close();
    save_annee(racine->fils,annee,nb_pg,name_file);
    save_annee(racine->frere,annee,nb_pg,name_file);
}
bool get_chem_rec(arbr racine, long id , string &ch ){
    if(!racine){
        return false;
    }
    if (racine->data.id == id)
    {
        ch = ch + to_string(racine->data.id);
        return true;
    }
    if (get_chem_rec(racine->fils, id , ch))
    {
        ch = to_string(racine->data.id) + "/" + ch;
        return true;
    }
    
    if (get_chem_rec(racine->frere,id,ch))
    {
        return true;
    }
    return false;
}
void get_chem(arbr racine , long id , char*ch){
    string chh = " ";
    if (get_chem_rec(racine,id,chh))
    {
        strcpy(ch,chh.c_str());
    }else
    {
        cout << "chemin introuvable" << endl;
    }
}
int main() {
}
