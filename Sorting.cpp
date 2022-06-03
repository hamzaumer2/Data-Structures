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
		}///inner loop
		// IF no two elements were swapped by inner loop, then break
		if (swapped == false) {
			cout << "\nArray already sorted";
			break;
		}
	}
}/* Function to sort an array using insertion sort*/

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


void merge(int array[], int const left, int const mid, int const right)
{
	int arr1 = mid - left + 1, arr2 = right - mid;

	int* arr_left = new int[arr1], * arr_right = new int[arr2];

	for (int i = 0; i < arr1; i++) {

		arr_left[i] = array[left + i];
	}
	for (int j = 0; j < arr2; j++) {

		arr_right[j] = array[mid + 1 + j];
	}

	int index1 = 0, index2 = 0;
	int new_array = left;
	while (index1 < arr1 && index2 < arr2) {
		if (arr_left[index1] <= arr_right[index2]) {
			array[new_array] = arr_left[index1];
			index1++;
		}
		else {
			array[new_array] = arr_right[index2];
			index2++;
		}
		new_array++;
	}
	while (index1 < arr1) {
		array[new_array] = arr_left[index1];
		index1++;
		new_array++;
	}
	while (index2 < arr2) {
		array[new_array] = arr_right[index2];
		index2++;
		new_array++;
	}
}
void mergeSort(int array[], int begin, int end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
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
main0: {
	int size, elem;
	cout << "\nEnter Size of Array:";
	cin >> size;
	int arr[size];//USING CODEBLOCKS WITH GNU GCC COMPILER. VARIABLE NAME CAN BE USED AS ARRAY SIZE IN THIS.....NOT IN VISUAL STUDIO
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
		<< "\n1. Selection Sort"
		<< "\n2. Bubble Sort"
		<< "\n3. Insertion Sort"
		<< "\n4. Quick Sort"
		<< "\n5. Merge Sort"
		<< "\n6. New Values to sort"
		<< "\n7.EXIT";
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
		cout << "\nSorted array with Merge Sort: \n";
		mergeSort(arr, 0, n - 1);
		printArray(arr, n);
		cout << "\n-------------------------------------------------------------------\n";
		goto main1;
		break;
	}
	case 6:
	{
		system("CLS");
		cout << "\nAdd New values to sort";
		cout << "\n-------------------------------------------------------------------\n";
		goto main0;
		return 0;
	}
	case 7:
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
}
