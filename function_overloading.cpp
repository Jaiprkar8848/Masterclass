#include<iostream>
using namespace std;

class Calculator{
    public:
        int add(int a,int b){
            return a+b;
        }
        int add(int a,int b,int c){
            return a+b+c;
        }
};

int main(){
    Calculator c;
    cout<<c.add(1,2)<<endl;
    cout<<c.add(1,2,3);
}