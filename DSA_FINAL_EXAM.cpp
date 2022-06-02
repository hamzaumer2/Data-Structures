//HAMZA UMER FAROOQ - 200789
//QUESTION 1 OF DSA FINAL LAB EXAM


#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;

struct Stack_underflow :exception {};

class Stack {                                                                               //  STACK CLASS________________________________________________________________ 
public:
    Stack() = default;
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;
    ~Stack();

    void push(int value);
    void pop();
    void display() const;
    bool empty() const { return top == nullptr; }
private:
    struct Node {                                                                           //  NODE STRUCTURE_____________________________________________________________
        int data;
        Node* prev;
        Node* next;
    };
    Node* top = nullptr;
};

Stack::~Stack()
{
    while (!empty()) {
        pop();
    }
}

void Stack::push(int value)                                                              //  PUSH__________________________
{
    top = new Node{ value, top, nullptr };
    if (auto old = top->prev) {
        old->next = top;
    }
}

void Stack::pop()                                                                       //  POP LATEST_____________________
{
    if (empty()) {
        throw Stack_underflow{};
    }
    delete exchange(top, top->prev);
}

void Stack::display() const                                                             //  DISPLAY LATEST_________________ 
{
    for (auto it = top; it; it = it->prev) {
        cout << it->data ;
        break;
    }
    cout << '\n';
}

class Queue                                                                             //  QUEUE CLASS_________________________________________________________________
{
    int* arr;                                                                         // STORE ELEMENTS 
    int capacity;                                                                    // SIZE OF QUEUE
    int front;                                                                      // FRONT OF QUEUE
    int rear;                                                                      // REAR OF QUEUE
    int count;                                                                    // CURRENT SIZE OF QUEUE

public:
    Queue(int size = 200);                                                     // CONSTRUCTOR
    ~Queue();                                                                 // DESTRUCTOR
    int dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};


Queue::Queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}


Queue::~Queue() {
    delete[] arr;
}


int Queue::dequeue()
{

    if (isEmpty())
    {
    }

    int x = arr[front];


    front = (front + 1) % capacity;
    count--;

    return x;
}


void Queue::enqueue(int item)
{

    if (isFull())
    {
    }



    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}


int Queue::peek()
{
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}


int Queue::size() {                                                                 // RETURN SIZE OF QUEUE________________________________________________________________________
    return count;
}
bool Queue::isEmpty() {
    return (size() == 0);
}


bool Queue::isFull() {
    return (size() == capacity);
}

int main() {                                                                        //  MAIN CLASS___________________________________________________________________________________
    Stack stack;
    Queue qu;
    int players, sides;
    string name[200];
    int total = 0;
    bool looping = true;
    char cond;
    while (looping) {
        cout << "\nEnter Number of Players:   ";
        cin >> players;
        for (int k = 0; k < players; k++) {
            cout << "Enter Name of Player Number  " << k + 1 << " : ";
            cin >> name[k];
        }

        cout << "\nEnter Number of Sides:   ";
        cin >> sides;
        for (int i = 1 ; i < sides+1 ; i++) {
            Sleep(5);
            int result = 1 + (rand() % sides);                                                          //  TAKING RANDOM NUMBERS
            qu.enqueue(result);                                                                        //   PUTTING RANDOM NUMBER INTO QUEUE
        }
        for (int i = 0; i < players; i++)
        {
            cout << "Player Name: " << name[i];
            total = 0;
            for (int j = 0; j < 3; j++) {

                srand((unsigned)time(0));
                cout << "\nRolling Dice......\n";
                Sleep(1);
                printf("Your dice has been rolled! You got: \n ");
                Sleep(5);
                int result = qu.dequeue();

                printf("%d \n", result);
                total += result;
            }
            stack.push(total);

        }
        cout << "\n_______________________SUMMARY_____________________________";
        for (int l = players - 1; l >= 0; l--) {

            cout << "\nTotal Score of Player " << l + 1 << " Named " << name[l] << " is :  "; stack.display();
            stack.pop();
        }
        system("PAUSE");
        return 0;
    }
}