






LAB TASKS


Question 1:

#include<iostream>
using namespace std;

int main()
{
    int arr[5];
    int *a = arr;
    cout << "\nEnter five numbers:";
    cin >> *a >> *(a+1) >> *(a+2) >> *(a+3) >> *(a+4);	//5 numbers entered with pointer increasing value of array
    cout << "\nYour numbers are:";
    for (int x = 0 ; x<5 ; x++)
        cout << arr[x]<< ", ";					// displaying array in added form
    return 0;
}




Question 2:

#include<iostream>
using namespace std;

int main()
{
    int arr[5];
    int *a = arr;
    cout << "\nEnter five numbers:";
    cin >> *a >> *(a+1) >> *(a+2) >> *(a+3) >> *(a+4);
    cout << "\nYour numbers are:";
    for (int x = 4 ; x>=0 ; x--)
        cout << arr[x]<< ", ";					// displaying array in reverse order from that was added
    return 0;
}
Output:








Question 3:


#include<iostream>
using namespace std;

class Item {
    string name;
    int price, qty{};
public:
    explicit Item(string name = "", int price = 0);

    void setName(string name), setPrice(int price), setQty(int qty);

    string getName();

    int getPrice() const, getQty() const;

    void printData();
};

Item::Item(string name, int price) {
    this->name = std::move(name), this->price = price;
}

void Item::setName(string name) {
    this->name = std::move(name);
}

void Item::setPrice(int price) {
    this->price = price;
}

void Item::setQty(int qty) {
    this->qty = qty;
}

string Item::getName() {
    return this->name;
}

int Item::getPrice() const {
    return this->price;
}

int Item::getQty() const {
    return this->qty;
}

void Item::printData() {
    cout << "\nItem Name: " << this->name;
    cout << "\nItem Price: " << this->price;
    cout << "\nQuantity of Listed Item: " << this->qty;
}


class Inventory {
    int size;
    Item *items;
public:
    explicit Inventory(int size = 0);
    ~Inventory();
    void addToInventory(Item newItem);
    void viewInventory();
};

Inventory::Inventory(int size) {
    this->size = size;
    items = new Item[this->size];
}

Inventory::~Inventory() {
    delete[] items;
}


void Inventory::addToInventory(Item newItem) {
    Item *inv = this->items;
    this->size++;
    this->items = new Item[size];

    for (int i = 0; i < size - 1; i++) {
        this->items[i] = inv[i];
    }

    items[size - 1] = std::move(newItem);
    delete[] inv;
}

void Inventory::viewInventory() {
    cout << "\nTotal Items in Inventory are: " << this->size;
    cout << "\nInventory Items are as printed: ";
    for (int i = 0; i < size; i++) {
        cout << "\n__________________________";
        this->items[i].printData();
    }
    cout << "\n__________________________";
}

int main() {
    Inventory Inv;
    Item ite;
    string name;
    int choice, price, qty;

    do {
        cout << "\n1. Add item";
        cout << "\n2. View Inventory";
        cout << "\n3. Exit";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter Name of Item: ";
                cin >> name;
                cout << "\nEnter Price of Item: ";
                cin >> price;
                cout << "\nEnter Quantity of Item: ";
                cin >> qty;

                ite.setName(name);
                ite.setPrice(price);
                ite.setQty(qty);
                Inv.addToInventory(ite);
                break;

            case 2:
                Inv.viewInventory();
                break;

            case 3:
                break;
            default:
                cout<<"\nInvalid Value Selected!!!\nExiting by default!!...";
                break;

        }
    } while (choice > 0 && choice < 3);

    return 0;
}



