#include <bits/stdc++.h>
using namespace std;

bool flag = 0;
void PrintSubsetSum(int i, int n, vector<int> arr, int targetSum, vector<int>& subset){
	if (targetSum == 0) {
	flag = 1;
	cout << "[ ";
	for (int i = 0; i < subset.size(); i++) {
		cout << subset[i] << " ";
		}
	cout << "]" << endl;
	return;
	}
	
	if (i == n)
		return;
	if (arr[i] <= targetSum) 
	{
		subset.push_back(arr[i]);
		PrintSubsetSum(i + 1, n, arr, targetSum - arr[i],subset);
		subset.pop_back();
	}
	PrintSubsetSum(i + 1, n, arr, targetSum, subset);
}

int main(){
	int n, data, sum;
	vector<int> arr, subArr;
	cout << "Enter number of elements : ";
	cin >> n;
	cout << "Enter " << n << " elements" << endl;
	for(int i = 0; i < n; i++)
	{
		cin >> data;

		arr.push_back(data); 
	}
	cout << "Enter a sum :";
	cin >> sum;
	cout << "Subset:" << endl;
	PrintSubsetSum(0, n, arr, sum, subArr);
	if(!flag)
		cout << "Subset not found" << endl;
}
