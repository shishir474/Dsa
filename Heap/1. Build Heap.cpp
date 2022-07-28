
TC: O(N);
SC: (O(logn)); ->recursive call stack space

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

void buildHeap(vector<int>& arr){

   int n=arr.size();
   for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

    // print arr
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector<int> arr= {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    buildHeap(arr);
}