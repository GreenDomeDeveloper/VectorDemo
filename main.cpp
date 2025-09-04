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
int findItemIndex(const vector<Item>& cart, const string& name);
bool removeAt(vector<Item>& cart, size_t index);
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
        } else if (choice == 3){
            string key;
            cout<<"Search name: ";
            clearLine();
            getline(cin,key);
            int index = findItemIndex(cart,key);
            if (index >=0){
                cout<<key<<" found at index "<<index<<endl;
            } else {
                cout<<key<<" not found"<<endl;
            }
        } else if (choice == 4) {
            if (cart.empty()){
                cout<<"Cart is empty"<<endl;
                continue;
            }
            size_t index;
            cout<<"Index to remove (0.."<<cart.size()-1<<"): ";
            if (!(cin>>index)){
                clearLine();
                cout<<"Invalid index"<<endl;
                continue;
            }
            if (removeAt(cart,index)){
                cout<<"Removed. Size="<<cart.size()<<endl;
            } else {
                cout<<"Invalid index"<<endl;
            }
        } else if (choice ==5){
            size_t index;
            string name;
            double price;
            cout<<"Insert index (0.."<<cart.size()<<"): ";
            if (!(cin>>index)){
                clearLine();
                cout<<"Invalid index."<<endl;
                continue;
            }
            cout<<"Enter item name: ";
            clearLine();
            getline(cin,name);
            cout<<"Enter item price: ";
            if (!(cin>>price)){
                clearLine();
                cout<<"Invalid price."<<endl;
                continue;
            }
            insertAt(cart,index,{name,price});
            cout<<"Inserted. Size="<<cart.size()<<endl;
        }
    }
    cout<<"Thank you for using our program!"<<endl;
    return 0;

}

void printMenu(){
    cout<<"Cafe Vector Lab"<<endl;
    cout<<"1) Add item"<<endl;
    cout<<"2) Print cart"<<endl;
    cout<<"3) Find item by name"<<endl;
    cout<<"4) Remove item by index"<<endl;
    cout<<"5) Insert item at index"<<endl;
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

int findItemIndex(const vector<Item> &cart, const string &name)
{
    for (size_t i=0; i<cart.size(); i++){
        if (cart.at(i).name == name){
            return i;
        }
    }
    return -1;
}

bool removeAt(vector<Item>&cart, size_t index){
    if (index >= cart.size()){
        return false;
    }
    cart.erase(cart.begin()+index); //Pass an iterator
    return true;
}

void insertAt(vector<Item> &cart, size_t index, const Item &it)
{
    if (index > cart.size()){
        cout<<"Index too large. Appending instead."<<endl;
        cart.push_back(it);
        return;
    }

    cart.push_back(it);

    for (size_t i=cart.size()-1; i>index; i--){
        cart.at(i) = cart.at(i-1);
    }

    cart.at(index)=it;
    
}
