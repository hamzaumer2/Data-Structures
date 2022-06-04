#include <bits/stdc++.h>
using namespace std;

struct QNode {
    int data;
    QNode* next;
    QNode(int d)
    {
        data = d;
        next = NULL;
    }
};

struct Queue {
    QNode* front, * rear;
    Queue()
    {
        front = rear = NULL;
    }

    void enQueue(int x)
    {

        QNode* temp = new QNode(x);
        if (rear == NULL) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void deQueue()
    {

        if (front == NULL)
            return;

        QNode* temp = front;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete (temp);
    }
};

int main()
{

    Queue q;
    int val;
    cout << "1) Enqueue" << endl;
    cout << "2) Dequeue" << endl;
    cout << "3) Display Front and Rear" << endl;
    cout << "4) Exit" << endl;
    do {
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch) {
        case 1: {
            cout << "Enter val to enqueue: ";
            cin >> val;
            q.enQueue(val);
        }
        case 2: {
            q.deQueue();
        }
        case 3: {
            cout << "Queue Front : " << (q.front)->data << endl;
            cout << "Queue Rear : " << (q.rear)->data;
        }
        case 4: {
            return 0;

            }
        }
    }
}