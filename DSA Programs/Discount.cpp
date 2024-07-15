#include<iostream>
using namespace std;

class Discount{
    char productName[50];
    char category[50];
    int price, total_price;

    public:
        void getdata(void);
        void calculatData(int ds);
        void displayData(int ds);
};

void Discount :: getdata(void){
    cout<<"Enter product name : ";
    cin>>productName;
    cout<<"Enter category : ";
    cin>>category;
    cout<<"Enter price : ";
    cin>>price;
}

void Discount :: calculatData(int ds){
    int dprice = (price * ds)/100;
    total_price = price - dprice;
}

void Discount :: displayData(int ds){
    cout<<"\nProduct name : "<<productName<<endl;
    cout<<"Price : "<<price<<endl;
    cout<<"Discount : "<<ds<<"%"<<endl;
    cout<<"Now price : "<<total_price<<endl;
}

int main(){
    int discount = 10;
    Discount product;

    product.getdata();
    product.calculatData(discount);
    product.displayData(discount);

    return 0;
}