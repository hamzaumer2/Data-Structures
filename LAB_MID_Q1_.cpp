#include<iostream>
using namespace std;
class Student_Class {
public:
    string first_name;
    string last_name;
    int id;
    int marks{};
};

class Node {
private:
    Student_Class student;
    Node* next{};
public:
    Student_Class getData();
    void setdetail(Student_Class st);
    Node* getNext();
    void setNext(Node* n);
};

Student_Class Node::getData() {
    return student;
}

void Node::setdetail(Student_Class st) {
    this->student = std::move(st);
}

Node* Node::getNext() {
    return next;
}

void Node::setNext(Node* n) {
    this->next = n;
}

class LinkedList {
private:
    int size = 0;
    Node* head;
    Node* current;
public:
    LinkedList();
    void new_student(const Student_Class& student);
    void display();
};

LinkedList::LinkedList() {
    head = new Node();
    head->setNext(nullptr);
    current = nullptr;
}

void LinkedList::new_student(const Student_Class& student) {
    Node* newNode = new Node();
    newNode->setdetail(student);
    size++;
    if (current != nullptr)
    {
        current = head;
        for (int i = 1; i < size; i++)
        {
            if (((current->getNext())->getData().marks) < (student.marks))
            {
                break;
            }
            else
            {
                current = current->getNext();
            }
        }
        if ((current->getNext()) == nullptr)
        {
            newNode->setNext(nullptr);
            current->setNext(newNode);
        }
        else
        {
            newNode->setNext(current->getNext());
            current->setNext(newNode);
            current = newNode;
        }
    }
    else
    {
        newNode->setNext(nullptr);
        head->setNext(newNode);
        current = newNode;
    }
}

void LinkedList::display() {
    if (current != nullptr) {
        Student_Class stud;
        current = head->getNext();
        for (int i = size; i > 0; i--) {
            stud = current->getData();
            cout << "\nFirst Name: " << stud.first_name;
            cout << "\nLast Name: " << stud.last_name;
            cout << "\nID: " << stud.id;
            cout << "\nMarks: " << stud.marks;
            cout << endl;
            cout << "*****************************************";
            cout << endl;
            if (current->getNext() == nullptr) {
                cout << "\nNo Data Available!!!";
                break;
            }
            current = current->getNext();
        }
        cout << endl;
    }
}

int main() {
    LinkedList List;
    Student_Class newStudent;
    string firstname, lastname;
    int marks, id;
    int choice;
start:
    {
        cout << "\n1. New Student"
            << "\n2. Display Students by Marks"
            << "\n3. Exit\n";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "\nEnter First name: ";
            cin >> firstname;
            cout << "\nEnter Last name: ";
            cin >> lastname;
            cout << "\nEnter  ID: ";
            cin >> id;
            cout << "\nEnter Marks: ";
            cin >> marks;
            newStudent.id = id;
            newStudent.marks = marks;
            newStudent.first_name = firstname;
            newStudent.last_name = lastname;
            List.new_student(newStudent);
            goto start;
        }
        case 2: {
            List.display();
            goto start;
        }
        case 3: {
            return 0;
        }
        default: {
            cout << "INCORRECT!!! RETRY";
            goto start;
        }
        }
    }
}
