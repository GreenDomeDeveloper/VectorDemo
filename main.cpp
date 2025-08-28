#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Item {
    string name; // auto null
    double price = 0.0;
};

void clearLine(){
    cin.clear();
    char ch;
    while (cin.get(ch) && ch!='\n') { /* eats the buffer */ }
}

void printMenu();
void printCart(const vector<Item>& cart);
double total(const vector<Item>& cart);
void capacityDemo();
void insertAt(vector<Item>& cart, size_t index, const Item& it);

int main(){
    vector<Item> cart;
    cout<<"Welcome to the cafe!"<<endl;

    int choice = -1;

    while (choice!=6){
        printMenu();
        cout<<"Choice: ";
        if (!(cin>>choice)){
            clearLine();
            cout<<"Please enter a number."<<endl;
            continue;
        }

        if (choice == 1){
            // add item to vector
            string name;
            double price;
            cout<<"Enter item name: ";
            clearLine();
            getline(cin,name);
            cout<<"Enter item price: ";
            if (!(cin>>price)){
                clearLine();
                cout<<"Invalid price. Try again."<<endl;
                continue;
            }
            cart.push_back({name,price});
            cout<<"Added. size ="<<cart.size()<<" capacity="<<cart.capacity()<<endl;
        } else if (choice == 2){
            printCart(cart);
            cout<<"Total: $"<<total(cart)<<endl;
        }
    }
    cout<<"Thank you for using our program!"<<endl;
    return 0;

}

void printMenu(){
    cout<<"Cafe Vector Lab"<<endl;
    cout<<"1) Add item"<<endl;
    cout<<"2) Print cart"<<endl;
    cout<<"6) Quit"<<endl;
}

void printCart(const vector<Item>& cart){
    if (cart.empty()) {
        cout<<"Your cart is empty"<<endl;
        return;
    }

    for (size_t i=0; i < cart.size(); i++){
        cout<<i<<") "<<cart.at(i).name<<" - $"<<cart.at(i).price<<endl;
    }
}

double total(const vector<Item>& cart){
    double sum = 0.0;
     
    for (size_t i=0; i<cart.size(); i++){
        sum += cart.at(i).price;
    }

    return sum;
}




