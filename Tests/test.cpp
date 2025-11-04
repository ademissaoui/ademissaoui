#include <iostream>
#include <string>
using namespace std;
class abstractemployee{    
    virtual void askforpromotion()=0;
};
class employee:abstractemployee
{
private:
    string company ;
    int age ;
protected:
    string name;
public:
    void setname(string nn){
        name = nn;
    }
    string getname(){
        return name;
    }
    void setcompany(string company){
        company = company;
    }
    string getcompany(){
        return company;
    }
    void setage(int age){
        age = age;
    }
    int getage(){
        return age;
    }
    employee(string n, string c,int a){
       name = n;
       company = c;
       age = a;
       }
       ~employee(){
        cout << "destructor envoked" << endl;
}
void introduce (){
    cout << "my name is  " <<name << endl;
    cout << "company : "<< company<<endl;
    cout << "my age is " << age << endl;
}
void askforpromotion(){
    if (age>30)
    {
        cout << name << "  got promoted" << endl;
    }else{
        cout << "sorry no promotion for you" << endl;
    }
    
}
virtual void work(){
    cout << name << "is cheking email launching tasks ..." << endl;
}
};
class developer :public employee{
public:
    string fvrtproglang;
    developer(string n, string c,int a ,string language):employee(n,c,a){
        fvrtproglang = language;
    }
    void fixbug(){
        cout << name << "fixed bug using " << fvrtproglang << endl;
    }
    void work(){
        cout << name << " s writing code " << endl ;
    }

};
class teacher : public employee {
public:    
    string subject;
    void preparelesson(){
        cout << name << "is preparing  " <<  subject  <<  "  lesson" <<endl;
    }
    teacher(string name ,string company,int age,string sub):employee(name,company,age){
        subject = sub;
    }
    void work(){
        cout << name << " is teatching " << subject << endl;
    }
};
int main(){
    employee employe1 = employee("adem","amazon",20) ;
    employee employe2 = employee("sara","google",35);
    /*employe1.introduce();
    employe2.introduce();
    employe1.askforpromotion();
    employe2.askforpromotion();*/ 
    developer d = developer("adem "," amazon" , 25, "C++");
   /* d.fixbug();
    d.askforpromotion();*/
    teacher t = teacher("fatma","cool school",40,"math");
    //t.preparelesson();
    //t.askforpromotion();
    employee* e1 = &d;
    employee* e2 = &t;

    e1->work();
    e2->work();

}