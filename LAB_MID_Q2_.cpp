#include<iostream>
using namespace std;
class Patient_Class {
public:
    string Name;
    char gender;
    bool covid;
    bool diabetic;
    bool heart;
    int age{};
    int ser;

};

class Node {
private:
    Patient_Class Patient;
    Node* next{};
public:
    Patient_Class getData();
    void setdetail(Patient_Class st);
    Node* getNext();
    void setNext(Node* n);
};

Patient_Class Node::getData() {
    return Patient;
}

void Node::setdetail(Patient_Class st) {
    this->Patient = std::move(st);
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
    void new_Patient(const Patient_Class& Patient);
    void display();
};

LinkedList::LinkedList() {
    head = new Node();
    head->setNext(nullptr);
    current = nullptr;
}

void LinkedList::new_Patient(const Patient_Class& Patient) {
    Node* newNode = new Node();
    newNode->setdetail(Patient);
    size++;
    if (current != nullptr)
    {
        current = head;
        for (int i = 1; i < size; i++)
        {
            if (((current->getNext())->getData().ser) < (Patient.ser))
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
    bool show;
    if (current != nullptr) {
        Patient_Class stud;
        current = head->getNext();
        for (int i = size; i > 0; i--) {
            stud = current->getData();
            cout << "\nName: " << stud.Name;
            cout << "\nGender: " << stud.gender;
            cout << "\ncovid: " << stud.covid;
            cout << "\nDiabetic: " << stud.diabetic;
            cout << "\nHeart Disease: " << stud.heart;
            cout << "\nage: " << stud.age;
            cout << endl;
            cout << "*****************************************";
            cout << endl;
            cout << "*****************************************";

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
    Patient_Class newPatient;
    string Name;
    char gender;
    int age;
    bool covid, diab, heart;
    int choice;
    int male = 0;
    int female = 0;
    int kids = 0;
    int old = 0;
    int covid_pos = 0;
    int heart_pos = 0;
    int sugar_pos = 0;
    int show;
    int listlen = 0;
start:
    {
        cout << "\n1. New Patient"
            << "\n2. Display"
            << "\n3. Delete Last Person"
            << "\n4. Exit\n";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "\nEnter Name: ";
            cin >> Name;
            cout << "\nEnter Gender: ";
            cin >> gender;
            cout << "\nEnter age: ";
            cin >> age;
            cout << "\nCovid?(1 for yes, 0 for no): ";
            cin >> covid;
            cout << "\nDiabetic?(1 for yes, 0 for no): ";
            cin >> diab;
            cout << "\nHeart Patient?(1 for yes, 0 for no): ";
            cin >> heart;
            listlen++;
            newPatient.ser = listlen;
            newPatient.covid = covid;
            newPatient.age = age;
            newPatient.Name = Name;
            newPatient.gender = gender;
            newPatient.covid = covid;
            newPatient.diabetic = diab;
            newPatient.heart = heart;
            List.new_Patient(newPatient);
            if (gender == 'M') { male++; }
            else if (gender == 'F') { female++; }
            if (age < 15) { kids++; }
            if (age > 50) { old++; }
            if (covid == 1) { covid_pos++; }
            if (diab == 1) { sugar_pos++; }
            if (heart == 1) { heart_pos++; }
            goto start;
        }
        case 2: {
            List.display();
            cout << "\nShow Total Data?(1 for yes, 0 for No)";
            cin >> show;
            if (show == 1) {
                cout << "\nTotal Kids: " << kids;
                cout << "\nTotal Elders: " << old;
                cout << "\nTotal Covid Positive: " << covid_pos;
                cout << "\nTotal Diabetic: " << sugar_pos;
                cout << "\nTotal Heart Disease: " << heart_pos;
            }
            goto start;
        }
        case 4: {
            return 0;
        }
        default: {
            cout << "INCORRECT!!! RETRY";
            goto start;
        }
        }
    }
}
