#include<iostream>
#include<cstring>
using namespace std;
class composant{
    protected:
        int id;
        char* libelle;
        float prix;
    public:
        composant(){
            id =0;
            prix =0;
            libelle = nullptr;
        }
        composant(int d , float p , char* lib){
            id = d;
            prix = p;
            libelle = new char[strlen(lib)+1];
            strcpy(libelle,lib);
        }
        composant(const composant &c){
            id = c.id;
            prix = c.prix;
            libelle = new char[strlen(c.libelle)+1];
        }
        ~composant(){
            delete[] libelle;
        }
        float get_prix(){
            return prix;
        }
        operator char*() const{
            char* temp = new char[strlen(libelle)+1];
            strcpy(temp,libelle);
            return temp;
        }
        void view(){
            cout<< "id : " << id << endl;
            cout<< "prix : "<<prix<<endl;
            cout<<"libelle : " << libelle<<endl;
        }
        composant &operator++(){
            prix++;
            return *this;
        }
        composant &operator--(){
            prix--;
            return *this;
        }
        composant &operator+(const composant &autre){
            prix+=autre.prix;
            return *this;
        }
};
class comp_add :public composant{
    private:
        float cout_add;
    public:
        comp_add(){
            prix = 0;
            cout_add = 0;
            libelle = nullptr;
            id = 0;
        }
        comp_add(float add):composant(id,prix,libelle){
            cout_add = add;
        }
        float get_prix(){
            return prix+cout_add;
        }

};
int main(){
    composant a(12,300,"pc");
    /*a.view();
    ++a;
    ++a;
    a.view();
    --a;
    --a;
    --a;
    a.view();*/
    composant b(12,34,"desktop");
    composant c = a+b;
    //c.view();
    composant* ptr;
    ptr = &a;
    ptr->view();
    ptr=&c;
    ptr->view();
}
