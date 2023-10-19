#include <iostream>
using namespace std;
int kthSmallest(int arr[], int n, int k) {
	
	int max_element = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max_element) {
			max_element = arr[i];
		}
	}

	
	int freq[max_element + 1] = {0};
	for (int i = 0; i < n; i++) {
		freq[arr[i]]++;
	}

	
	int count = 0;
	for (int i = 0; i <= max_element; i++) {
		if (freq[i] != 0) {
			count += freq[i];
			if (count >= k) {
				
				return i;
			}
		}
	}
	return -1;
}

int main() {
	int arr[] = {12,3,5,7,19};
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 2;
	cout << "The " << k << "th smallest element is " << kthSmallest(arr, n, k) << endl;

	return 0;
}
