


Question 1:

#include <iostream>

using namespace std;

int dig_sum(int n)
{
    if (n != 0)
        return (n % 10 + dig_sum(n / 10) );

    else return 0;
}

int main()
{
    int n, r;
    cout <<"\nEnter any number: ";
    cin>>n;

    r = dig_sum(n);
    cout << "\nSum of digits is: " << n << " is: " << r;
    return 0;
}




Question 2:

#include <iostream>

using namespace std;

void reverse_string(string st, int r = 0);


void reverse_string(string st, int r) {
    if (r != st.length())
    {
        reverse_string(st, r + 1);
        cout << st[r];
    }
}

int main()
{
    string s;
    cout << "Enter String to be reversed: ";
    cin >> s;
    reverse_string(s);
    return 0;
}


Question 3:
#include <iostream>

using namespace std;

bool Palindrome_check(string st);


bool Palindrome_check(string st)
    {  // bool as it is output only requires true or false
    int first = 0;
    int last;
    last = st.length() - 1;  // -1 to take last value as length and declaration/finding has difference of 1 as it starts from 0

    while (last > first)
        if (st[first] == st[last])
            {
            first++;
            last--;
                }
        else 
            return false;
    return true;
                  }

int main()
{
    string st;
    cout<<"Enter any String to check IF it a Palindrome or NOT: ";
    cin>>st;

    if (!Palindrome_check(st)) 
    {
        cout << "It is *** NOT *** a Palindrome";
    } else {
        cout << "It is a Palindrome";
    }
    return 0;
                 }



