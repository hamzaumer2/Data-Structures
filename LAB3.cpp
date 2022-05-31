Question 1:

#include <iostream>
using namespace std;

struct Student{
    float marks[10];
};
int main(){
    float sum = 0, average, max, min;
    Student st[10];
    for (int i=0; i<10; i++){
        cond:
        cout << "\nEnter Marks of Student "<<(i+1)<<": ";
        cin >> st[i].marks[i];
        if (st[i].marks[i] > 100|| st[i].marks[i] < 0){
            cout << "\nMarks Entered are NOT IN RANGE (0-100)... TRY AGAIN!!!...";
            goto cond;
        }

    }
    for (int i=0; i<10; i++){
        sum+=st[i].marks[i];
    }
    average =sum / 10;
    max = st[0].marks[0];
    min = st[0].marks[0];
    cout << "\nAverage Numbers of Class are: "<<average;
    for(int i=0; i<10; i++)
    {
        if(st[i].marks[i] > max)
            max = st[i].marks[i];

        if(st[i].marks[i] < min)
            min = st[i].marks[i];
    }

    cout << "\nThe Maximum Marks of class are: " << max;
    cout << "\nThe Minimum Marks of class are: " << min;
    return 0;
}













Question 2:

#include <iostream>
using namespace std;

class Library{
    int Sno = 0, i = 0, serial{}, pub_date[20]{};
    string bookname[20], author[20], aisle[20];
public:
    string Add_Book();
    string search_book();
    string update();
    string remove();
    string display();
};

string Library::Add_Book() {
    Sno++;
    cout << "\nSerial ID: " << Sno;
    cout << "\nEnter Book details!!";
    cout << "\nEnter Book Name (No spacing): ";
    cin >> bookname[i];
    cout << "\nEnter Book Author (No spacing): ";
    cin >> author[i];
    cout << "\nEnter Book Publish date (No spacing. Format DDMMYYYY): ";
    cin >> pub_date[i];
    cout << "\nEnter Book Aisle (ROW-COLUMN): ";
    cin >> aisle[i];
    i++;
    return {};
}

string Library::search_book() {
    c1:{
    cout << "\nEnter Serial ID of Book To Search: ";
    cin>>serial;
    serial --;}
    if (serial > i-1){cout<< "BOOK DOESNT EXIST TRY AGAIN!!!";
    goto c1;}
    cout << "\nBook Name: " <<  bookname[serial];
    cout << "\nBook Author: " << author[serial];
    cout << "\nBook Publish Date (DDMMYY): " << pub_date[serial];
    cout << "\nBook Aisle: " << aisle[serial];
    return {};
}

string Library::update() {
    c2:{
    cout << "\nEnter Serial ID of Book To Update: ";
    cin>>serial;
    serial --;}
    if (serial > i-1){cout<< "BOOK DOESNT EXIST TRY AGAIN!!!";
        goto c2;}
    cout << "\nEnter Book Name (No spacing): ";
    cin >> bookname[serial];
    cout << "\nEnter Book Author (No spacing): ";
    cin >> author[serial];
    cout << "\nEnter Book Publish date (No spacing. Format DDMMYYYY): ";
    cin >> pub_date[serial];
    cout << "\nEnter Book Aisle (ROW-COLUMN): ";
    cin >> aisle[serial];
    cout << "Book Update Successful";
    return {};
}

string Library::remove() {
    c3:{
    cout << "\nEnter Serial ID of Book To Update: ";
    cin>>serial;
    serial --;}
    if (serial > i-1){cout<< "BOOK DOESNT EXIST TRY AGAIN!!!";
        goto c3;}
    bookname[serial] = "";
    author[serial] = "";
    pub_date[serial] = 0;
    aisle[serial] = "";
    cout << "\nBook Removed Successfully";
    return {};
}

string Library::display() {
    serial = 0;
    while (serial<=i+1){
    cout << "\n**************************";
    cout << "\nSerial Number: " << serial+1;
    cout << "\nBook Name: " <<  bookname[serial];
    cout << "\nBook Author: " << author[serial];
    cout << "\nBook Publish Date (DDMMYY): " << pub_date[serial];
    cout << "\nBook Aisle: " << aisle[serial];
    serial++;
    }
    return {};
}


int main(){
    Library lib;
    int cond;
    string pass;
    char cont;
    string pass_auth = "1234";
    try1:{
    cout << "\nADMINISTRATOR LIBRARY MANAGEMENT SYSTEM";
    cout << "\nEnter Password: ";
    cin>> pass;
}
    if (pass != pass_auth){cout << "INCORRECT PASSWORD!!!";
        goto try1;
    }

    else if (pass == pass_auth) {
        cout << "\nWELCOME!!!";
        func1:
        {
            cout << "\nEnter the required function: ";
            cout << "\n1. Add Book";
            cout << "\n2. Search Book by ID";
            cout << "\n3. Update Book";
            cout << "\n4. Delete Book";
            cout << "\n5. Display All Books";
            cin>>cond;
            if (cond == 1) lib.Add_Book();
            else if (cond == 2) lib.search_book();
            else if (cond == 3) lib.update();
            else if (cond == 4) lib.remove();
            else if (cond == 5) lib.display();
            cond2:
            {cout << "\nContinue?(Y/N)";
                cin>> cont;
                if (cont =='y'|| cond == 'Y') goto func1;
                else if (cont == 'n' || cond == 'N') return 0;
                else {cout << "\nINVALID OPTION SELECTED TRY AGAIN!!!";
                    goto cond2;}
            }
        }
    }
}





























Question 3:

#include <iostream>
#include <fstream>
using namespace std;
struct Complaint{
    string name[3], message[3];
};
int main(){
    Complaint comp[3];
    string name;
    for (int i=0; i < 3; i++){
        int number;
        cout << "\nComplaint Number: "<< (i+1) ;

        cout << "\nEnter your Name: ";
        cin >> comp[i].name[i];
        cond:

        cout << "\nSelect One of following: ";
        cout << "\n1. Electricity Bills";
        cout << "\n2. Water Bills";
        cout << "\n3. Maintenance Requests";

        cin >> number;

        if (number <= 0 || number > 3){
            cout << "\nInvalid Menu Number Entered!!!";
            goto cond;
        }
        else{
            switch(number){
                case 1 : {
                    cout << "\nEnter the issue faced regarding electricity bill: ";
                    cin >> comp[i].message[i];
                    break;
                }
                case 2: {
                    cout << "\nEnter the issue faced regarding water bill: ";
                    cin >> comp[i].message[i];
                    break;
                }
                case 3: {
                    cout << "\nEnter the issue faced regarding maintenance: ";
                    cin >> comp[i].message[i];
                    break;
                }
            }
        }
    }
    for (int i=0; i < 3; i++){
        ofstream data("complaint.txt",ios::app);
        data << "\nComplaint: "<<(i+1);
        data << "\nName:"<< comp[i].name[i];
        data << "\nComplaint: "<<comp[i].message[i];
    }
}








