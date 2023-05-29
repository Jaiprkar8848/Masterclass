#include<iostream>
using namespace std;

class Animal{
    public:
        void eat(){
            cout<<"Animal eats";
        }

};

class cat:public Animal{
    public:
        void eat(){
            cout<<"cat eats";
        }      
};

class dog:public Animal{
    public:
        void eat(){
            cout<<"dog eats";
        }   
};

int main(){
    Animal a1;
    cat a2;
    dog a3;
    a1.eat();
    cout<<endl;
    a2.eat();
    cout<<endl;
    a3.eat();
}