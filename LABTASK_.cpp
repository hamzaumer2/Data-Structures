#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;//NOT INCLUDING NAMESPASE STD
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::  NODE CLASS
class node {
    int data;
    node* nextNode;
public:
    node();
    int getData() const;
    void setData(int input);
    node* getNextNode();
    void setNextNode(node* input);
};
node::node() {
    data = 0;
    nextNode = nullptr;
}
int node::getData() const {
    return data;
}
void node::setData(int input) {
    data = input;
}
node* node::getNextNode() {
    return nextNode;
}
void node::setNextNode(node* input) {
    nextNode = input;
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  LINKEDLIST CLASS
class linkedList {
    node* head;
    node* current;
    node* previous;
    node* temp;
    int size;
    string name;
public:
    explicit linkedList(string name = "");
    void insertAtStart(int input);
    void displayEven();
    void displayOdd();

};

linkedList::linkedList(string name) {
    head = nullptr;
    current = nullptr;
    previous = nullptr;
    temp = nullptr;
    size = 0;
}
void linkedList::insertAtStart(int input) {
    node* nextNode = new node;
    nextNode->setData(input);
    nextNode->setNextNode(nullptr);
    if (head == nullptr) {
        head = nextNode;
    }
    else {
        nextNode->setNextNode(head);
        head = nextNode;
    }
    size++;
}

void linkedList::displayEven() {
    if (head == nullptr) {
        cout << "\n No elements in list." << endl;
        system("pause");
    }
    else {
        current = head;
        while (current->getNextNode() != nullptr)
        {
            if (current->getData() % 2 == 0) {
                cout << current->getData() << " ";
            }
            current = current->getNextNode();
        }
        if (current->getData() % 2 == 0) {
            cout << endl;
            cout << "  " << current->getData();
        }
    }
}
void linkedList::displayOdd() {
    if (head == nullptr) {
        cout << "\n No elements in list." << endl;
        system("pause");
    }
    else {
        current = head;
        while (current->getNextNode() != nullptr)
        {
            if (current->getData() % 2 != 0) {
                cout << current->getData() << " ";
            }
            current = current->getNextNode();
        }
        if (current->getData() % 2 != 0) {
            cout << endl;
            cout << " " << current->getData();
        }
    }
}

int main() {
    int choice1, choice2, location, data{};
    linkedList* list = nullptr;
    list = new linkedList("1");
    cout << "\nEnter How many vals you want to input: ";
    cin >> choice1;
    for (int i = 0; i < choice1; i++) {
        cout << "\nEnter Value "<< (i+1) << ":  ";
        cin >> data;
        list->insertAtStart(data);
    }
    cout << "\nEven List Is: ";
    list->displayEven();
    cout << "\nOdd List Is: ";
    list->displayOdd();
    return 0;
}




/////QUESTION 2:

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

struct Node
{
    int data;
    struct Node* link;
};

struct Node* top;
void push(int data)
{
    struct Node* temp;
    temp = new Node();
    if (!temp)
    {
        cout << "\nOverflow";
        exit(1);
    }
    temp->data = data;
    temp->link = top;
    top = temp;
}

int isEmpty()
{
    return top == NULL;
}

int peek()
{

    if (!isEmpty())
        return top->data;
    else
        exit(1);
}

void pop()
{
    struct Node* temp;

    if (top == NULL)
    {
        cout << "\nUnderflow";
        exit(1);
    }
    else
    {
        temp = top;

        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}

void display()
{
    struct Node* temp;

    if (top == NULL)
    {
        cout << "\nUnderflow";
        exit(1);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {

            cout << temp->data << "-> ";

            temp = temp->link;
        }
    }
}



int main()
{
    int length, value, i = 0;
    int cond;
    cout << "Enter Length for stack: ";
    cin >> length;
    for (int i = 0; i < length; i++) {
        cout << "Enter Value " << i + 1 << ": ";
        cin >> value;
        push(value);
    }

loop1: {
    cout << "\nStack is: ";
    display();
    cout << "\n1. Enter New Val"
        << "\n2. Delete Latest Val"
        << "\n3. Display Top Element"
        << "\n4. Exit";
    cout << endl;
    cin >> cond;
    switch (cond) {
    case 1: {
        cout << "\nEnter Value " << i + 1 << ": ";
        cin >> value;
        push(value);
        cout << "\nDone!";
        cout << endl;
        system("PAUSE");
        goto loop1;
    }
    case 2: {
        pop();
        cout << "\nDone!";
        cout << endl;
        system("PAUSE");
        goto loop1;
    }
    case 3: {
        peek();
        cout << "\nDone!";
        cout << endl;
        system("PAUSE");
        goto loop1;
    }
    case 4: {
        cout << "\nProgram Exitted!!";
        return 0;
    }
    default: {
        cout << "\nIncorrect Try again!!!";
        goto loop1;
    }
    }
    }

return 0;
}
