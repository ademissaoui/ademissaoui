#include <iostream>
using namespace std;
class ensemble{
    private:
        int n;
        int * t;
    public:
        void definir(){
            cout << "donner la taille du tableau  : " << endl;
            cin >> n;
            t = new int[n];
        }    
        void remplir(){
            for (int i = 0; i < n; i++)
            {
                cout << "donner l'element  : " << i+1 << endl;
                cin >> t[i];
            }
        }

        int intersection(ensemble t1){
            int count = 0;
            for (int i = 0; i < t1.n; i++)
            {
                if (t1.t[i] == t[i])
                {
                        count++;
                }
                    
                }
                return count;
        }
        void view(){
            cout << "{";
            for (int i = 0; i < n; i++)
            {
                
                cout << t[i] << " ," ;
                
            }

            cout << "}" << endl;
        }
};
int main(){
    ensemble s1;
    ensemble s2;
    s1.definir();
    s2.definir();
    s1.remplir();
    s2.remplir();
    s1.view();
    s2.view();
    int res = s1.intersection(s2);
    cout << res ;
}