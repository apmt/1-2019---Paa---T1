#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;

int find(int *arr, int N, int left, int right){
	int middle = (left + right) / 2;
	if(right < left)
		return -1;
	if(N == arr[middle]) {
		while(N == arr[middle]) {
			middle--;
		}
			return middle+1;
	}
	if(N < arr[middle]) {
		find(arr, N, left, middle-1);
	}
	else {
		find(arr, N, middle+1, right);
	}
}

int main() {
	int N, Q, i = 0, pos;
	string line;
	int arr[500000];
	cin >> N >> Q;
	getline(cin, line);
	getline(cin, line);
	istringstream arr_aux(line);
	while(arr_aux >> arr[i++]){}
	while(Q--) {
		scanf("%d", &N);
		pos = find(arr, N, 0, i-2);
		printf("%d\n", pos);
	}
}