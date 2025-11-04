#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
    map<string,string> dictionary;
    dictionary.insert(pair<string,string>("apple","pomme"));
    dictionary.insert(pair<string,string>("strawberry","fraise"));
    dictionary["strawberry"]= "die herber";
    for (auto pair : dictionary)
    {
        cout << pair.first << " - " << pair.second << endl;
    }
    cout << dictionary.size();
    dictionary.clear();

    
}