
// C++ program for implementation of selection sort
#include <iostream>
using namespace std;

void swap(int* xpoint, int* ypoint)
{
    int temp = *xpoint;
    *xpoint = *ypoint;
    *ypoint = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}


void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // IF no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }
}


/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;


        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int pivot(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = pivot(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int size, elem;
    cout << "\nEnter Size of Array:";
    cin >> size;
    int arr[size];//USING CODEBLOCKS WITH GNU GCC COMPILER. VARIABLE NAME CAN BE USED AS ARRAY SIZE IN THIS..... NOT IN VISUAL STUDIO
    for (int i = 0; i < size; i++) {
        cout << "\nEnter Element Number " << i + 1 << ": ";
        cin >> elem;
        arr[i] = elem;
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    int choice;
    cout << "\n---------------WELCOME TO SORTING ALGORITHM-------------------------\n";
main1: {

    cout << "\nPLEASE ENTER YOUR CHOICE: \n"
        << "\n1.Selection Sort"
        << "\n2.Bubble Sort"
        << "\n3.Insertion SORT"
        << "\n4.Quick Sort"
        << "\n5.EXIT";
    cin >> choice;
    switch (choice) {

    case 1:
    {
        selectionSort(arr, n);
        cout << "\nSorted array with Selection Sort: \n";
        printArray(arr, n);

        cout << "\n-------------------------------------------------------------------\n";
        goto main1;
        break;
    }
    case 2:
    {
        bubbleSort(arr, n);
        cout << "\nSorted array with Bubble Sort: \n";
        printArray(arr, n);

        cout << "\n-------------------------------------------------------------------\n";
        goto main1;
        break;
    }
    case 3:
    {
        insertionSort(arr, n);
        cout << "\nSorted array with Insertion Sort: \n";
        printArray(arr, n);

        cout << "\n-------------------------------------------------------------------\n";
        goto main1;
        break;
    }
    case 4:
    {
        quickSort(arr, 0, n - 1);
        cout << "\nSorted array with Quick Sort: \n";
        printArray(arr, n);

        cout << "\n-------------------------------------------------------------------\n";
        goto main1;
        break;
    }
    case 5:
    {
        cout << "\nPROGRAM TERMINATED";

        cout << "\n-------------------------------------------------------------------\n";
        return 0;
    }

    default: {
        cout << "\nINVALID CHOICE.";

        cout << "\n-------------------------------------------------------------------\n";
        break;
    }

    }

    return 0;
    }
}

