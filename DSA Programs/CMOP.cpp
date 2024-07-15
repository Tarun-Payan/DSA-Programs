#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    //Constant Variable
    const int a = 45;// Variable a is constant variable , so now we cannot change it
    // a = 34;//this will throw an error
    cout<<"Value of a is : "<<a<<endl;

    //Manipulator in C++
    //endl is a manipulator , it break a line
    //setw is a second manipulator, it set output, it is help us to right jultify our line,word, variable value, etc

    int x = 5, y = 43, z = 5342;
    cout<<"Value of x without setw is : "<<x<<endl;
    cout<<"Value of y without setw is : "<<y<<endl;
    cout<<"Value of z without setw is : "<<z<<endl;

    cout<<"Value of x with setw is : "<<setw(4)<<x<<endl;
    cout<<"Value of y with setw is : "<<setw(4)<<y<<endl;
    cout<<"Value of z with setw is : "<<setw(4)<<z<<endl;
}