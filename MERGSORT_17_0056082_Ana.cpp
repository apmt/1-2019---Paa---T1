#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void Merge(int *arr, int left, int middle, int right){
	int i = left, j = middle + 1, k = 0;
	int arr_aux[right - left + 1];
	while(i <= middle && j <= right) {
		if(arr[i]<arr[j]) {
			arr_aux[k] = arr[i];
			k++; i++;
		}
		else {
			arr_aux[k] = arr[j];
			k++; j++;
		}
	}
	while(i<=middle) {
		arr_aux[k] = arr[i];
		k++; i++;
	}
	while(j<=right) {
		arr_aux[k] = arr[j];
		k++; j++;
	}
	for(i = left; i <= right; i++)
		arr[i] = arr_aux[i-left];
}

void MERGESORT(int *arr, int left, int right){
	int middle;
	if (left<right) {
		middle = (left+right)/2;
		MERGESORT(arr, left, middle);
		MERGESORT(arr, middle+1, right);
		Merge(arr, left, middle, right);
	}
}

int main() {
	int N, i=0, j=0;
	int arr[100000];
	string line;
	getline(cin, line);
	istringstream arr_aux(line);
	while(arr_aux >> arr[i++]){}
	MERGESORT(arr, 0, i-2);
	while(j<i-2){
		cout<<arr[j++]<<" ";
	}
	cout<<arr[j++]<<"\n";
}