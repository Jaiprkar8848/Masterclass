#include<iostream>
using namespace std;

class Car{
    public:
        string brand;
        Car(string brand){
            this->brand=brand;
        }

};
class Person{
    private:
        Car *car; // Person has a car
    public:
        string name; 
        Person(string name,Car *car){
            this->name=name;
            this->car=car;
        }
        void display(){
            cout<<name<<" has a car of brand "<<car->brand;
        }
};


int main(){
    Car c("BMW");
    Person p("Jp",&c);
    p.display();
}