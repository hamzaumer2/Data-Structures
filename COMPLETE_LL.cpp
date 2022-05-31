#include <iostream>
#include <string>
#include "Link_assignment.h"

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
    void insertAtMiddle(int loc, int data);
    void insertAtEnd(int input);
    void deleteAtStart();
    void deleteAtMiddle(int loc);
    void deleteAtEnd();
    void display();
    void displayEven();
    void displayOdd();
    void displayReverse();
    void displayAscending();
    void displayDescending();
    void findbyVal(int);
    void listLength();
    void updateVal(int, int);
    void swapbyValues(int, int);
    void swapbyLocation(int, int);
    void copybyVal(int, int);
    void operator=(const linkedList* obj);
};
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  FUNCTION DECLARATION OF LINKEDLIST
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
void linkedList::insertAtMiddle(int loc, int data) {
    node* newNode = new node;
    newNode->setData(data);
    if (head == nullptr && loc == 1) {
        head = newNode;
        newNode->setNextNode(nullptr);
        size++;
    }
    else if (loc <= size) {
        if (loc == 1) {
            newNode->setNextNode(head);
            head = newNode;
        }
        else if (loc < size) {
            current = head;
            previous = head;
            for (int i = 0; i < loc; i++) {
                previous = current;
                current = current->getNextNode();
            }
            newNode->setNextNode(current);
            previous->setNextNode(newNode);
        }
        else {
            this->insertAtEnd(data);
        }
        size++;
    }
    else {
        cout << "\n List is smaller than given location." << endl;
    }
}
void linkedList::insertAtEnd(int input) {
    node* nextNode = new node;
    nextNode->setData(input);
    nextNode->setNextNode(nullptr);
    if (head == nullptr) {
        head = nextNode;
    }
    else {
        current = head;
        while (current->getNextNode() != nullptr)
        {
            current = current->getNextNode();
        }
        current->setNextNode(nextNode);
    }
    size++;
}
void linkedList::deleteAtStart() {
    if (head == nullptr) {
        cout << "\n List is empty.";
        system("pause");
    }
    else {
        current = head;
        head = head->getNextNode();
        delete current;
        size--;
    }
}
void linkedList::deleteAtMiddle(int loc) {
    if (head == nullptr) {
        cout << "\n List is empty." << endl;
        system("pause");
    }
    else if (loc <= size) {
        if (loc == 1) {
            current = head->getNextNode();
            delete head;
            head = current;
            size--;
        }
        else if (loc < size) {
            current = head;
            previous = head;
            for (int i = 1; i < loc; i++) {
                previous = current;
                current = current->getNextNode();
            }
            previous->setNextNode(current->getNextNode());
            size--;
        }
        else {
            this->deleteAtEnd();
        }
    }
    else {
        cout << "\n List is smaller than given location." << endl;
    }
}
void linkedList::deleteAtEnd() {
    if (head == nullptr) {
        cout << "\n List is empty.";
        system("pause");
    }
    else {
        current = head;
        node* previous = nullptr;
        while (current->getNextNode() != nullptr)
        {
            previous = current;
            current = current->getNextNode();
        }
        delete current;
        previous->setNextNode(nullptr);

        size--;
    }
}
void linkedList::display() {
    if (head == nullptr) {
        cout << "\n No elements in list." << endl;
        system("pause");
    }
    else {
        current = head;
        while (current->getNextNode() != nullptr)
        {
            cout << current->getData();
            current = current->getNextNode();
            cout << " ";

        }
        cout << " " << current->getData();
    }
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
void linkedList::displayAscending() {
    int* arr = new int[size];
    int j = 0;
    int temp;
    if (head == nullptr)
    {
        cout << "Empty List";
    }
    else
    {
        arr = new int[size];
        current = head;
        while (current->getNextNode() != nullptr)
        {
            arr[j] = current->getData();
            j++;
            current = current->getNextNode();
        }
        arr[j] = current->getData();

        for (int j = 0; j < size; j++)
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[j] < arr[i])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        for (int k = 0; k < size; k++) {
            cout << arr[k] << ", ";
        }
    }
    delete[] arr;
}
void linkedList::displayDescending() {
    int* arr = new int[size];
    int j = 0;
    int temp;
    if (head == nullptr)
    {
        cout << "List Empty";
    }
    else
    {
        arr = new int[size];
        current = head;
        while (current->getNextNode() != nullptr)
        {
            arr[j] = current->getData();
            j++;
            current = current->getNextNode();
        }
        arr[j] = current->getData();
        for (int j = 0; j < size; j++)
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i] < arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }

            }
        }
        for (int k = 0; k < size; k++) {
            cout << arr[k] << ", ";
        }
    }
    delete[] arr;
}
void linkedList::displayReverse() {
    if (head == nullptr) {
        cout << "\n No elements in list." << endl;
        system("pause");
    }
    else {
        current = head;
        int* arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = current->getData();
            current = current->getNextNode();
        }
        for (int i = size - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        delete[] arr;
    }
}
void linkedList::findbyVal(int val) {
    if (head == NULL) {
        cout << "list is empty" << endl;
    }
    else
    {
        current = head;
        int count = 0;
        for (int i = 0; i < size; i++) {
            count++;
            if (current->getData() == val) {
                cout << "Number value is at location " << count << " location: " << endl;
                cout << "\n" << current->getData();
                current = current->getNextNode();
            }
            else
            {
                current = current->getNextNode();
            }
        }
    }
}
void linkedList::listLength() {
    int length = 1;
    if (head == nullptr) {
        cout << "\n No elements in list." << endl;
        system("pause");
    }
    else {
        current = head;
        while (current->getNextNode() != nullptr)
        {
            length++;
            current = current->getNextNode();

        }
    }
    cout << "\nList Length is: " << length;
}

void linkedList::updateVal(int val, int loc) {
    if (head == nullptr) {
        cout << "\n No elements in list." << endl;
    }
    else {
        current = head;
        for (int i = 1; i < loc; i++) {
            current = current->getNextNode();
        }
        current->setData(val);
        cout << "Value Updates Sucessfully!!!";
    }
}
void linkedList::swapbyValues(int v1, int v2)
{
    if (head == nullptr) {
        cout << "\n No elements in list." << endl;
    }
    else {

        current = head;
        while (current->getNextNode())
        {

            if (current->getData() == v1)
                current->setData(v2);
            else if (current->getData() == v2)
                current->setData(v1);
            current = current->getNextNode();
        }
        if (current->getData() == v1)
            current->setData(v2);
        else if (current->getData() == v2)
            current->setData(v1);
    }
}
void linkedList::swapbyLocation(int n1, int n2)
{
    if ((n1 <= 0 || n1 > size) || (n2 <= 0 || n2 > size))
        cout << "you entered invalid locations ";
    if (head == nullptr) {
        cout << "\n No elements in list." << endl;
    }
    else
    {
        int t1, t2;
        current = head;
        for (int i = 1; i < n1; i++)
        {
            current = current->getNextNode();
        }
        t1 = current->getData();
        current = head;
        for (int i = 1; i < n2; i++)
        {
            current = current->getNextNode();
        }
        t2 = current->getData();

        current = head;

        for (int i = 1; i < n1; i++)
        {
            current = current->getNextNode();
        }
        current->setData(t2);
        current = head;
        for (int i = 1; i < n2; i++)
        {
            current = current->getNextNode();
        }
        current->setData(t1);

    }

}
void linkedList::copybyVal(int l1, int l2)
{
    int temp;
    if ((l1 <= 0 || l1 > size) || (l2 <= 0 || l2 > size))
        cout << "you entered invalid locations ";
    else
    {
        current = head;
        for (int i = 1; i < l1; i++)
            current = current->getNextNode();
        temp = current->getData();

        current = head;
        for (int i = 1; i < l2; i++)
            current = current->getNextNode();
        current->setData(temp);
    }
}
void linkedList::operator=(const linkedList* obj)
{
    if (obj->head == NULL)
    {

    }
    else
    {


        int temp;
        current = obj->head;
        while (obj->current->getNextNode() != NULL)
        {
            temp = obj->current->getData();
            insertAtEnd(temp);
            current = obj->current->getNextNode();
        }
        temp = obj->current->getData();
        insertAtEnd(temp);
    }
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  MAIN MODULE
int main() {
    int choice1, choice2, location, data{};
    linkedList* list = nullptr;
    int create = 0;
    string list_name;
    cout << "\n\t\t\tBSCS-F-20\tHamza Umer Farooq\t200789";
    cout << "\n\n\t\t\t\t\t***** ASSIGNMENT *****";
start: {
    cout << "\n\n\t\t\t\t\t    ***** LIST *****";
    cout << "\n\n\t\t\t\t\t1.Create List"
        << "\n\t\t\t\t\t2. Insertion Menu"
        << "\n\t\t\t\t\t3. Deletion Menu"
        << "\n\t\t\t\t\t4. Display Menu"
        << "\n\t\t\t\t\t5. Swapping Menu"
        << "\n\t\t\t\t\t6. Copying Menu"
        << "\n\t\t\t\t\t7. Update Values"
        << "\n\t\t\t\t\t8. Find Values"
        << "\n\t\t\t\t\t9. Length of List"
        << "\n\t\t\t\t\t10. Delete Entire List"
        << "\n\t\t\t\t\t11. Exit"
        << "\n\nEnter Your Choice: ";
    cin >> choice1;

    if (choice1 == 11) {
        system("CLS");
        cout << "\n\t***** Exit Menu Selected *****";
        cout << "\n\t***** Exitting the Program *****";
        cout << endl;
        cout << endl;
        return 0;
    }

    if (create != 1 && choice1 != 1) {
        system("CLS");
        cout << "\n\t\t\t\t     ***** Create a list first *****";
        cout << endl;
        goto start;
    }


    switch (choice1) {
    case 1:
        system("CLS");

        if (create == 1) {
            cout << "\n\t***** List already created!!! *****";
            goto start;
        }

        cout << "\n\t***** Creation Menu Selected ***** ";
        cout << "\n\n\tEnter List Name:";
        cin >> list_name;
        cout << "\n\tList Created Sucessfully";
        create = 1;
        list = new linkedList(list_name);
        goto start;

    case 2:
    loop2: {
        system("CLS");
        cout << "\n\tList name: " << list_name << "\n\tList Values: ";
        list->display();
        cout << "\n\t***** Insertion Menu Selected *****";
        cout << "\n\t\t\t\t\t1. Insert at Start"
            << "\n\t\t\t\t\t2. Insert at End"
            << "\n\t\t\t\t\t3. Insert at Specific Location"
            << "\n\t\t\t\t\t4. Main Menu"
            << "\n\t\t\t\t\t5. Exit"
            << "\n\nEnter Your Choice: ";
        cin >> choice2;

        switch (choice2) {
        case 1:
            cout << "\n\t***** Insert at Start Selected *****";
            cout << "\nEnter Value: ";
            cin >> data;
            list->insertAtStart(data);
            // FUNCTION INSERT AT START; NUMBER 1; 1a//////////////////////////////////////////////////////////////////////////////////////////////////////////
            cout << endl;
            goto loop2;
        case 2:
            cout << "\n\t***** Insert at End Selected *****";
            cout << "\nEnter Value: ";
            cin >> data;
            list->insertAtEnd(data); // FUNCTION INSERT AT END; NUMBER 2; 1b///////////////////////////////////////////////////////////////////////////////////
            cout << endl;
            goto loop2;
        case 3:
            cout << "\n\t***** Insert at Specific Location Selected *****";
            cout << "\nEnter Value: ";
            cin >> data;
            cout << "Enter location: ";
            cin >> location;
            list->insertAtMiddle(location, data); // FUNCTION INSERT AT SPECIFIES; NUMBER 3; 1c //////////////////////////////////////////////////////////////
            cout << endl;
            goto loop2;
        case 4:
            system("CLS");
            cout << "\n\t***** Main Menu *****";
            goto start;
        case 5:
            system("CLS");
            cout << "\n\t***** Exit Menu Selected *****";
            cout << "\n\t***** Exitting the Program *****";
            return 0;
        default:
            system("CLS");
            cout << "\n\t***** Incorrect option selected... Try Again *****";
            goto loop2;

        }
    }

    case 3:
    loop3: {
        system("CLS");
        cout << "\n\tList name: " << list_name << "\n\tList Values: ";
        list->display();
        cout << "\n\t***** Deletion Menu Selected *****";
        cout << "\n\n\t\t\t\t\t1. Delete at Start"
            << "\n\t\t\t\t\t2. Delete at End"
            << "\n\t\t\t\t\t3. Delete at Specific Location"
            << "\n\t\t\t\t\t4. Main Menu"
            << "\n\t\t\t\t\t5. Exit"
            << "\n\nEnter Your Choice: ";
        cin >> choice2;
        switch (choice2) {
        case 1:
            cout << "\n\t***** Delete at Start Selected *****";
            list->deleteAtStart(); // FUNCTION DELETE AT START; NUMBER 4; 2a////////////////////////////////////////////////////////////////////
            cout << endl;
            goto loop3;
        case 2:
            cout << "\n\t***** Delete at End Selected *****";
            list->deleteAtEnd(); // FUNCTION DELETE AT END; NUMBER 5; 2b//////////////////////////////////////////////////////////////////////
            cout << endl;
            goto loop3;
        case 3:
            cout << "\n\t***** Delete at Specific Location Selected *****";
            cout << "\nEnter location: ";
            cin >> location;
            list->deleteAtMiddle(location);
            // FUNCTION DELETE AT LOCATION; NUMBER 6; 2c/////////////////////////////////////////////////////////////////////////////////////
            cout << endl;
            goto loop3;
        case 4:
            system("CLS");
            cout << "\n\t***** Main Menu Selected *****";
            goto start;
        case 5:
            system("CLS");
            cout << "\n\t***** Exit Menu Selected *****";
            cout << "\n\t***** Exitting the Program *****";
            return 0;
        default:
            system("CLS");
            cout << "\n\t***** Incorrect option selected... Try Again *****";
            goto loop3;
        }
    }
    case 4:
    loop4: {
        system("CLS");
        cout << "\n\tList name: " << list_name;
        cout << "List Values: ";
        list->display();
        cout << "\n\t***** Display Menu Selected *****";
        cout << "\n\t\t\t\t\t1. Display Entire List"
            << "\n\t\t\t\t\t2. Display Even Values"
            << "\n\t\t\t\t\t3. Display Odd Values"
            << "\n\t\t\t\t\t4. Display in Ascending Order"
            << "\n\t\t\t\t\t5. Display in Descending Order"
            << "\n\t\t\t\t\t6. Display in Reverse Order"
            << "\n\t\t\t\t\t7. Main Menu"
            << "\n\t\t\t\t\t8. Exit"
            << "\n\nEnter Your Choice: ";
        cin >> choice2;
        switch (choice2) {
        case 1:
            system("CLS");
            cout << "\n\t***** Display Entire List Selected *****\n";
            list->display(); // FUNCTION DISPLAY ENTIRE LIST; NUMBER 7; 3a////////////////////////////////////////////////////////////////////////////////////////
            cout << endl;
            system("pause");
            goto loop4;
        case 2:
            system("CLS");
            cout << "\n\t***** Display Even Selected *****\n";
            list->displayEven(); // FUNCTION DISPLAY EVEN LIST; NUMBER 8; 3b////////////////////////////////////////////////////////////////////////////////////////
            cout << endl;
            system("pause");
            goto loop4;
        case 3:
            system("CLS");
            cout << "\n\t***** Display in Odd Selected *****\n";
            list->displayOdd(); // FUNCTION DISPLAY ODD LIST; NUMBER 9; 3c////////////////////////////////////////////////////////////////////////////////////////////
            cout << endl;
            system("pause");
            goto loop4;
        case 4:
            system("CLS");
            cout << "\n\t***** Display in Ascending Order Selected *****";
            cout << endl;
            list->displayAscending();
            // FUNCTION DISPLAY Ascending LIST; NUMBER 10; 3d////////////////////////////////////////////////////////////////////////////////////////////////////////////
            cout << endl;
            system("pause");
            goto loop4;
        case 5:
            system("CLS");
            cout << "\n\t***** Display in Descening Order Selected *****";
            cout << endl;
            list->displayDescending();
            // FUNCTION DISPLAY Descending LIST; NUMBER 11; 3e////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            cout << endl;
            system("pause");
            goto loop4;
        case 6:
            system("CLS");
            cout << "\n\t***** Display In Reverse Order Selected *****";
            cout << endl;
            list->displayReverse(); // FUNCTION DISPLAY Reverse LIST; NUMBER 12; 3f//////////////////////////////////////////////////////////////////////////////////////////
            cout << endl;
            system("pause");
            goto loop4;
        case 7:
            system("CLS");
            cout << "\n\t***** Main Menu Selected *****";
            goto start;
        case 8:
            system("CLS");
            cout << "\n\t***** Exit Menu Selected *****";
            cout << "\n\t***** Exitting the Program *****";
            return 0;
        default:
            system("CLS");
            cout << "\n\t***** Incorrect option selected... Try Again *****";
            goto loop4;
        }
    }
    case 5:
    loop5: {
        system("CLS");
        cout << "\n\tList name: " << list_name;
        cout << "List Values: ";
        list->display();
        cout << "\n\t***** Swapping Menu Selected *****"
            << "\n\t\t\t\t\t1. Swap by Location"
            << "\n\t\t\t\t\t2. Swap by Value"
            << "\n\t\t\t\t\t3. Main Menu"
            << "\n\t\t\t\t\t4. Exit"
            << "\n\nEnter Your Choice: ";
        cin >> choice2;
        switch (choice2) {
        case 1:
            int n1, n2;
            system("CLS");
            cout << "\n\t***** Swap by Location Selected *****";
            cout << "\n\t***** Swap by Value Selected *****";
            cout << "\nEnter First Value: ";
            cin >> n1;
            cout << "Enter Second Value: ";
            cin >> n2;
            list->swapbyLocation(n1, n2);
            // FUNCTION SWAP by Location; NUMBER 13; 4a//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            system("pause");
            goto loop5;
        case 2:
            int v1, v2;
            system("CLS");
            cout << "\n\t***** Swap by Value Selected *****";
            cout << "\nEnter First Value: ";
            cin >> v1;
            cout << "Enter Second Value: ";
            cin >> v2;
            list->swapbyValues(v1, v2);
            // FUNCTION SWAP by Value; NUMBER 14; 4b////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            cout << endl;
            system("pause");
            goto loop5;
        case 3:
            system("CLS");
            cout << "\n\t***** Main Menu Selected *****";
            goto start;
        case 4:
            system("CLS");
            cout << "\n\t***** Exit Menu Selected *****";
            cout << "\n\t***** Exitting the Program *****";
            return 0;
        default:
            system("CLS");
            cout << "\n\t***** Incorrect option selected... Try Again *****";
            goto loop5;
        }
    }
    case 6:
    loop6: {
        system("CLS");
        cout << "\n\tList name: " << list_name << "\nList Values: ";
        list->display();
        cout << "\n\t***** Copying Menu Selected *****"
            << "\n\t\t\t\t\t1. Copy Values from one location to another location"
            << "\n\t\t\t\t\t2. Copy Values into another list"
            << "\n\t\t\t\t\t3. Main Menu"
            << "\n\t\t\t\t\t4. Exit"
            << "\n\nEnter Your Choice: ";
        cin >> choice2;
        switch (choice2) {
        case 1:
            int loc1, loc2;
            system("CLS");
            cout << "\n\t***** Copy values from one location to other Selected *****";
            cout << "\nEnter first value";
            cin >> loc1;
            cout << "\nEnter second value(TARGET): ";
            cin >> loc2;
            list->copybyVal(loc1, loc2);
            // FUNCTION Copy Location; NUMBER 15; 5a///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            cout << endl;
            system("pause");
            goto loop6;
        case 2:
            system("CLS");
            linkedList* nl;
            int s_name;
            cout << "\n\t***** Copy from another list Selected *****";
            nl = new linkedList();
            cout << "\nEnter the name of the list : ";
            cin >> s_name;
            *(nl) = *(list);
            cout << " " << endl;
            cout << "\nCopied into new list sucessfully";
            nl->display();
            //FUNCTION Copy from other list; NUMBER 16; 5b////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            cout << endl;
            system("pause");
            goto loop6;
        case 3:
            system("CLS");
            cout << "\n\t***** Main Menu Selected *****";
            goto start;
        case 4:
            system("CLS");
            cout << "\n\t***** Exit Menu Selected *****";
            cout << "\n\t***** Exitting the Program *****";
            return 0;
        default:
            system("CLS");
            cout << "\n\t***** Incorrect option selected... Try Again *****";
            goto loop6;
        }
    }
    case 7:
        system("CLS");
        int val, loc;
        cout << "\n\tList name: " << list_name;
        cout << "\n\t***** Value Update Menu Selected *****";
        cout << "\nEnter New Value: ";
        cin >> val;
        cout << "\nEnter Location: ";
        cin >> loc;
        list->updateVal(val, loc);
        // FUNCTION Update Value; NUMBER 17; 6a////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        cout << endl;
        system("pause");
        goto start;

    case 8:
        system("CLS");
        int value;
        cout << "\n\tList name: " << list_name;
        cout << "\n\t***** Value Find Menu Selected *****";
        cout << "\nEnter Value to FInd: ";
        cin >> value;
        list->findbyVal(value);
        // FUNCTION Find Value; NUMBER 18; 7a////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        cout << endl;
        system("pause");
        goto start;

    case 9:
        system("CLS");
        cout << "\n\tList name: " << list_name;
        cout << "\n\t***** Length of List Menu Selected *****";
        list->listLength();
        // FUNCTION List Length; NUMBER 19; 8a/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        cout << endl;
        system("pause");
        goto start;

    case 10:
        system("CLS");
        cout << "\n\tList name: " << list_name;
        cout << "\n\t***** Complete List Deletion Menu Selected ***** ";
        cout << "\nList deleted Successfully!!!";
        list->linkedList::linkedList(list_name);
        list = nullptr;
        // FUNCTION Complete List Deletion; NUMBER 20; 9a////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        create = 0;
        list_name = "";
        cout << endl;
        system("pause");
        goto start;

    default:
        system("CLS");
        cout << "\n\t***** Incorrect option selected... Try Again *****";
        goto start;
    }
    return 0;
    }
}
