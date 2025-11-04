#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using namespace std;
struct piece
{
    long id ;
    char designation [31];
    char modele[11];
    int position;
    double prix;
    piece* suivant;
};
typedef piece* list;
list load_piece(){
    piece *p;
    ifstream fichier ("piece.txt");
    if (!fichier)
    {
        cout << "impossibke d'ouvrir le fichier " << endl ;
    }
    list first = nullptr, last= nullptr;

    while (true)
    {
        p = new piece;
        fichier >> p->id  >> p->designation >> p->modele >> p->position >> p->prix ;
        if (fichier.eof())
        {
            delete p;
            break;
        }
        p->suivant = nullptr;
        if (first== nullptr)
        {
            first = p;
        }else{
            last->suivant = p ;
        }
        last = p;
    }
    return first;
}
void save_model(list first , char* modele , char* name_file){
    ofstream file (name_file);
    while (first!= nullptr)
    {
        if (strcmp(modele,first->modele)==0)
        {
            file << first->designation << first->id << first->modele << first->position << first->prix ;
        }
        first = first->suivant;
    }
    file.close();    
}
list seek_piece(list first, long id){
    if (first->id==id)
    {
        return first;
    }
    return seek_piece(first->suivant,id);
}

    

    










int main(){

}