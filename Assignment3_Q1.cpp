#include <iostream>
using namespace std;

class node {
    int data;
    node* left; 
    node* right;
public:
    node() {
        data = 0;
        left = NULL;
        right = NULL;
    }
    void setdata(int input) {
        data = input;
    }
    void setLeft(node* input) {
        left = input;
    }
    void setRight(node* input) {
        right = input;
    }
    int getData() {
        return data;
    }
    node* getLeft() {
        return left;
    }
    node* getRight() {
        return right;
    }
};

class tree {
    node* root;
    node* current;
    node* previous;
    int size;
public:
    tree() {
        root = NULL;
        current = NULL;
        previous = NULL;
        size = 0;
    }

    void insert(int input) {
        node* newNode = new node;
        newNode->setdata(input);
        newNode->setLeft(NULL);
        newNode->setLeft(NULL);
        if (root == NULL) {
            root = newNode;
        }
        else {
            current = root;
            previous = root;
            while (current != NULL) {
                previous = current;
                if (current->getData() > input) current = current->getLeft();
                else current = current->getRight();
            }
            if (previous->getData() > input) previous->setLeft(newNode);
            else previous->setRight(newNode);
        }
        size++;
    }

    void deletion(int v) {
        current = root;
        previous = root;
        node* newcur = NULL;

        while ((current != NULL) && (v != current->getData()))
        {

            previous = current;
            if (current->getData() > v)
            {
                current = current->getLeft();
            }
            else
            {
                current = current->getRight();
            }

        }

        if (current == NULL){
            cout << "value not found";
        }

        if (current->getRight() == NULL || current->getLeft() == NULL) {
            if (current->getLeft() == NULL){
                newcur = current->getRight();
            }

            else{
                newcur = current->getLeft();
            }

            if (previous == NULL)
            {
                root = newcur;
            }

            if (current == previous->getRight())
            {
                previous->setRight(newcur);
            }

            else
            {
                previous->setLeft(newcur);
            }
            delete current;
        }

        else
        {
            node* prv = NULL;
            node* temp = NULL;

            temp = current->getRight();
            while (temp->getLeft() != NULL)
            {
                prv = temp;
                temp = temp->getLeft();
            }

            if (prv != NULL)
            {
                prv->setLeft(temp->getRight());
            }
            else
            {
                current->setRight(temp->getRight());
            }

            current->setdata(temp->getData());
        }
    }

    void Inorder(node* root) {
        if (root != NULL) {
            Inorder(root->getLeft());
            cout << root->getData() << ", ";
            Inorder(root->getRight());
        }
    }
    int Summation(node* root) {
        if (root != NULL) {
            int sum = root->getData() + Summation(root->getLeft()) + Summation(root->getRight());
            return sum;
        }
        else return 0;
    }
    void Display() {
        cout << "\nNumber of Elements:  " << this->size;
        cout << "\nSummation of Tree:  " << Summation(root);
        cout << "\nElements in Inorder are:  ";
        Inorder(root);
    }
    bool isExists(int input) {
        current = root;
        previous = root;
        while (current != NULL && current->getData() != input) {
            if (input < current->getData()) current = current->getLeft();
            else current = current->getRight();
        }
        if (current == NULL) return false;
        else return true;

    }
};



int main() {
    tree even, odd;
    int ch, v, nov = 0;
    bool cont = false;
    while (true) {
        cout << "\n1. Insert Menu"
            << "\n2. Delete Menu"
            << "\n3. Display Menu"
            << "\n4. Exit\n";
        cin >> ch;
        if (ch == 7) {
            return 0;
            break;
        }
        if (cont == false && ch != 1) {
            cout << "Enter Value First!!!";
        }
        else {
            switch (ch) {
            case 1: {
                cout << "Enter Number: ";
                cin >> v;
                if (v % 2 == 0) even.insert(v);
                else odd.insert(v);
                nov++;
                cont = true;
                break;
            }
            case 2: {
                for (int i = 0; i < nov; i++) {
                    if (i % 9 == 0) {
                        if (i % 2 == 0) {
                            if (even.isExists(i)) even.deletion(i);
                        }
                        else {
                            if (odd.isExists(i)) odd.deletion(i);
                        }
                    }
                }
                break;
            }
            case 3: {
                cout << "1. Even\n2. Odd: ";
                cin >> v;
                if (v == 1)  even.Display();
                else if (v == 2) odd.Display();
                else cout << "\nEnter correct value!!!";
                break;
            }
            case 4: {
                return 0;
            }
            }
        }
    }
    return 0;
}


