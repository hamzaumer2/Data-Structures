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