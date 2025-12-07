#include <iostream>
using namespace std;
template <typename t>
class stack
{
private:
    int dim;
    int n;
    t *v ;
public:
    stack(int dim, int n ){
        this->dim = dim;
        try{
            if(n<=dim){
                this->n=n;
            }else{
                throw "erreur de saisie";
            }
        }
        catch(const char*msg){
            cout << msg << endl
            return *msg;
        }
        t* v = new t[n];
    }
    ~stack(){
        delete [] v;
    }
    void inserer(t v){
        if(n<=dim-1){
            v[n++]=v;
        }else{
            cout << "le table est plein ";
        }

    }
    void enlever(){
        if(stack.est_vide()){
            cout << "empty stack !!" << endl;
        }else{
            n--;
            delete v[n];
        }

    }
    bool est_vide(){
        if (n==0){
            return true;
        }else{
            return false;
        }
    }

};