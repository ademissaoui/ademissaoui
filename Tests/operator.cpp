#include <iostream>
using namespace std;
class Time{
    int h,m,s;
    friend ostream& operator<<(ostream&, const Time&);
public:
    Time(int hour,int minute,int second){
        h=hour;
        m=minute;
        s=second;
    }
    Time(){
        h=0;
        m=0;
        s=0;
    }
    Time operator+(const Time &other){
        return Time(h+other.h,m+other.m,s+other.s);
    }
    Time operator=(const Time &other){
        h=other.h;
        m=other.m;
        s=other.s;
        return *this;
    }
    void display(){
        cout<<"Time is:"<<h<<":"<<m<<":"<<s<<endl;
    }
    void sum(Time t1,Time t2){
        h=t1.h+t2.h;
        m=t1.m+t2.m;
        s=t1.s+t2.s;
    }

};

ostream& operator<<(ostream& os, const Time& t){
    os<<t.h<<":"<<t.m<<":"<<t.s;
    return os;
}

int main(){
    Time A(2,3,5);
    cout<<A<<endl;
    Time B(1,2,3);
    cout<<B<<endl;
    Time C;
    C.sum(A,B);
    cout<<C<<endl;
    Time D=A+B;
    cout<<D<<endl;
    Time E;
    E=A;
    cout<<E<<endl;

    return 0;
}