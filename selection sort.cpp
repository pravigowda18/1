#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	for (i = 0; i < n - 1; i++) {

		min_idx = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
			swap(arr[min_idx], arr[i]);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
		cout << endl;
	}
}

int main()
{
	int n;
	int arr[n];
	cout<<"Enter the number of array elements ";
	cin>>n;
	cout<<"Enter the array elements ";
	for ( int i=0; i<n; i++){
		cin>>arr[i];
	}
	
	cout<<"Original array: ";
	for (int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	selectionSort(arr, n);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}
