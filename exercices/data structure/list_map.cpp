#include<iostream>
#include<map>
#include<string>
#include<list>
using namespace std;
int main(){
    map<string,list<string>> pokedex;
    list<string> pikatchuattacks {"thunder shock","tail whip","quick attack"};
    list<string> charmenderattacks {"flame thrower","scary face"};
    list<string> chikoritaattacks {"razor leaf","poison powder"};
    pokedex.insert(pair<string,list<string>>("pikatchu",pikatchuattacks));
    pokedex.insert(pair<string,list<string>>("charmender",charmenderattacks));
    pokedex.insert(pair<string,list<string>>("chikori",chikoritaattacks));
   for (auto pair : pokedex)
   {
        cout << pair.first << " - ";
        for (auto attack : pair.second)
        {
            cout << attack << endl;
        }
        
   }
   
}