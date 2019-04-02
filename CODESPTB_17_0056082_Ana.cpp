#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int Merge(int *arr, int left, int middle, int right, int contador){
	int i = left, j = middle + 1, k = 0;
	int arr_aux[right - left + 1];
	int aux = 0;
	while(i <= middle && j <= right) {
		if(arr[i]<=arr[j]) {
			arr_aux[k] = arr[i];
			k++; i++;
		}
		else {
			arr_aux[k] = arr[j];
			k++; j++;
			contador += middle - i + 1;
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
	return contador;
}

int MERGESORT(int *arr, int left, int right, int contador){
	int middle;
	if (left<right) {
		middle = (left+right)/2;
		contador = MERGESORT(arr, left, middle, contador);
		contador = MERGESORT(arr, middle+1, right, contador);
		contador = Merge(arr, left, middle, right, contador);
		return contador;
	}
	return contador;
}

int main() {
	int i=0;
	int arr[100000];
	string line;
	int T, N;
	char buf;
	cin >> T;
	int contador;
	while(T--) {
		cin >> N;
		i = 0;
		getline(cin, line);
		getline(cin, line);
		istringstream arr_aux(line);
		while(arr_aux >> arr[i++]){}
		contador = MERGESORT(arr, 0, i-2, 0);
		cout<<contador<<"\n";
	}
}