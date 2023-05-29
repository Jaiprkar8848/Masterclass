#include<iostream>
using namespace std;
class Person{
    private:
        string name;
        int age;

    public:
        //channels to acces private member
        //setter
        void set_data(string Name,int Age){
            name=Name;
            age=Age;
        }
        //getter
        void get_data(){
            cout<<"Name:"<<name<<endl;
            cout<<"Age:"<<age<<endl;
        }
};

int main(){
    //Object of person class
    Person p;
    p.set_data("Jp",18);
    p.get_data();
}