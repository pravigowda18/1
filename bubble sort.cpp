#include <iostream> 
using namespace std; 

void bubbleSort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n - 1; i++) 
  
        for (j = 0; j < n - i - 1; j++) 
            if (arr[j] > arr[j + 1]) 
                swap(arr[j], arr[j + 1]); 
} 
  
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 

int main(){
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
	cout<<"\n";
	bubbleSort(arr,n);
	cout<<"Sorted array: ";
	for (int i=0;i<n;i++){
		cout<<arr[i]<<" ";
		
	}
	cout<<"\n";
	return 0;
}
