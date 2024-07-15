#include<iostream>
using namespace std;

int a = 45;// this variable is globle varible

int main(){
    int a = 5, b = 34;
    //this variables are local variables
    cout<<"Value of a is : "<<a<<endl;
    //we can access value of globle variable by using Scop Resolution Operator (::)
    cout<<"Value of globle variable a is : "<<::a<<endl;

    //****************** Reference Variable *********************
    int x = 32;
    int &y = x; //variable y is reference of variable x
    cout<<"\nx : "<<x<<endl<<"y : "<<y<<endl;
}