#include <iostream>
using namespace std;

int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main(void)
{
    int vals, size, val_to_find;
    cout << "Enter Size of Array: ";
    cin >> size;
    
    int arr[] = { 2, 3, 4, 10, 40 };
    cout << "\nEnter Val to find: ";
    cin >> val_to_find;

    int n = sizeof(arr) / sizeof(arr[0]);


    int result = search(arr, n, val_to_find);
    (result == -1)
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result;
    return 0;
}



