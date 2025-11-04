#include<iostream>
#include<math.h>
using namespace std;
void saisie (double & a , double &b , double & c){
   cout << "entrer les trois coefficients a,b,c : "<< endl;
   cin>> a;
   cin >> b;
   cin>>c;
}
void calculer(double a ,double b, double c){
   double d = (b*b)-4*a*c;
   double x1 = (-b-sqrt(d))/2*a;
   double x2 = (-b+sqrt(d))/2*a;
   cout << "les solution dans R sont : "<< "x1 = "<< x1 << ","<< "x2 = " << x2 << endl;
}
int main(){
   double a,b,c;
   cout << "resolutin equation 2nd degree dans R"<< endl;
   saisie(a,b,c);
   calculer(a,b,c);
   return 0;
}