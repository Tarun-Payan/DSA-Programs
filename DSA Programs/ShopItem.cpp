#include<iostream>
using namespace std;

class Shop{
    string itemName[100];
    int itemPrice[100];
    int counter;

    public:
        void initcounter(void) {counter = 0;}
        void getDetails(void);
        void displayDetails(void);
};

void Shop :: getDetails(){
    cout<<"Enter item name :";
    cin>>itemName[counter];
    cout<<"Enter item price :";
    cin>>itemPrice[counter];

    counter++;
}

void Shop :: displayDetails(){
    int i = 0;
    cout<<"\n\n";
    for(; i < counter; i++){
        cout<<"Price of "<<itemName[i]<<" is : "<<itemPrice[i]<<endl;
    }
}

int main(){
    Shop dukan;
    dukan.initcounter();
    dukan.getDetails();
    dukan.getDetails();
    dukan.getDetails();
    dukan.displayDetails();

    return 0;
}