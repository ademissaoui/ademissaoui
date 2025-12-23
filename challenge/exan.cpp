#include<iostream>
using namespace std;

template<typename t>

class node{
    private:
            t donnee;
            node* suivant;
    public:
        node(const t& d , nod* n = nullptr){
            node = n;
            donnee=d;
        } 
};
template <typename t>
class liste{
    private:
        node<t>* first;
    public:
        liste(){
            first = nullptr;
        }
        ~liste(){
            
                supprimerpremier();

        }
        void supprimerpremier(){
            if (first == nullptr){
                return
        }if(first->next == nullptr){
            delete first
            first = nullptr;
        }
        node<t>* nouv = first;
        while (first != nullptr){
            nouv=first.
            
        }
    }
};

