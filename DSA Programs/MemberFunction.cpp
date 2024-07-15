#include<iostream>
using namespace std;

class Cart{
    private:
        char productname[50];
        int quantity, productprice, cartprice, discount;
        //above variables called data member
    public:
        void displaydata();
        void getdetails(){ //this is a inside member function
            cout<<"Enter Product name : ";
            cin>>productname;
            cout<<"Enter Product price : ";
            cin>>productprice;
            cout<<"Enter Product quantity : ";
            cin>>quantity;
        }
        //above function are called member function
};

void Cart::displaydata(){ //this is outside member function
    cout<<"\n\nProduct name : "<<productname<<endl;
    cout<<"Product price : "<<productprice<<endl;
    cout<<"Product quantity : "<<quantity<<endl;
    cout<<"Total Price : "<<productprice*quantity<<endl;
}

int main(){
    Cart p1;
    p1.getdetails();
    p1.displaydata();

    return 0;
}