#include<iostream>
using namespace std;
int main(){
    int a = 4, b, c;
    cout<<"Operator:"<<endl;
    cout<<"a++ : "<<a++<<endl;
    cout<<"++a : "<<++a<<endl;
    b = a++;
    c = ++a;
    cout<<"b : "<<b + 3<<" c : "<<c<<endl;
    return 0;
}