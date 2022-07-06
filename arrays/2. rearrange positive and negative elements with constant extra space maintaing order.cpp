#include <stdio.h>

// Function to Rearrange positive and negative
// numbers in a array
// Insertion sort like algorithm 
void RearrangePosNeg(int arr[], int n)
{
	int key, j;
	for (int i = 1; i < n; i++) {
		key = arr[i];
		if (key > 0)
			continue;

		j = i - 1;
		while (j >= 0 && arr[j] > 0) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

/* Driver program to test above functions */
int main()
{
	int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	RearrangePosNeg(arr, n);
	printArray(arr, n);

	return 0;
}





// solution 2: using merge sort. Time complexity: O(n log n). 

// Auxiliary Space: O(n1 + n2 + log n), log n, as implicit stack is used due to recursive call

// The problem with this approach is we are using auxiliary array for merging but we’re not allowed to use any data structure to solve this problem. We can do merging in-place without using any data-structure. 

#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0; 
	k = l; 

	// Note the order of appearance of elements should
	// be maintained - we copy elements of left subarray
	// first followed by that of right subarray

	// copy negative elements of left subarray
	while (i < n1 && L[i] < 0)
		arr[k++] = L[i++];

	// copy negative elements of right subarray
	while (j < n2 && R[j] < 0)
		arr[k++] = R[j++];

	// copy positive elements of left subarray
	while (i < n1)
		arr[k++] = L[i++];

	// copy positive elements of right subarray
	while (j < n2)
		arr[k++] = R[j++];
}

void RearrangePosNeg(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		RearrangePosNeg(arr, l, m);
		RearrangePosNeg(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int main()
{
	int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	RearrangePosNeg(arr, 0, arr_size - 1);

	printArray(arr, arr_size);

	return 0;
}



// solution 3: optimised version of merge sort without extra space
#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int l, int r)
{
	if (l < r) {
		swap(arr[l], arr[r]);
		reverse(arr, ++l, --r);
	}
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
	int i = l; // Initial index of 1st subarray
	int j = m + 1; // Initial index of IInd

	while (i <= m && arr[i] < 0)
		i++;

	// arr[i..m] is positive

	while (j <= r && arr[j] < 0)
		j++;

	// arr[j..r] is positive

	// reverse positive part of
	// left sub-array (arr[i..m])
	reverse(arr, i, m);

	// reverse negative part of
	// right sub-array (arr[m+1..j-1])
	reverse(arr, m + 1, j - 1);

	// reverse arr[i..j-1]
	reverse(arr, i, j - 1);
}

// Function to Rearrange positive and negative
// numbers in a array
void RearrangePosNeg(int arr[], int l, int r)
{
	if (l < r) {
		// Same as (l+r)/2, but avoids overflow for
		// large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		RearrangePosNeg(arr, l, m);
		RearrangePosNeg(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

/* Driver code */
int main()
{
	int arr[] = { -12, 11, -13, -5, 6, -7, 5, -3, -6 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	RearrangePosNeg(arr, 0, arr_size - 1);

	printArray(arr, arr_size);

	return 0;
}
// Time complexity of above solution is O(n log n), O(Log n) space for recursive calls, and no additional data structure.

// Auxiliary Space: O(log n), as implicit stack is used due to recursive call