// an array of integers where each element has a difference of at most k with its neighbor. Given a key x, we need to find the index value of x if multiple-element exist to return the first occurrence of the key.
// Examples: 
 

// Input : arr[] = {4, 5, 6, 7, 6}
//            k = 1
//            x = 6
// Output : 2
// The first index of 6 is 2.

// Input : arr[] = {20, 40, 50, 70, 70, 60}  
//           k = 20
//           x = 60
// Output : 5
// The index of 60 is 5

This problem is extension of problem Search an element in an array where difference between adjacent elements is 1
sol.
 The idea is to start comparing from the leftmost element and find the difference between current array element and x. Let this difference be ‘diff’. From the given property of array, we always know that x must be at-least ‘diff’ away, so instead of searching one by one, we jump ‘diff’. 
 int search(int arr[], int n, int x)
{
    int i = 0;
    while (i < n) {
        if (arr[i] == x)
            return i;
        i = i + abs(arr[i] - x);
    }
 
    cout << "number is not present!";
    return -1;
}

// using the same logic as above
 fact that the difference between all adjacent elements is at most k. The idea is to start comparing from the leftmost element and find the difference between the current array element and x. Let this difference be ‘diff’. From the given property of the array, we always know that x must be at least ‘diff/k’ away, so instead of searching one by one, we jump ‘diff/k’. 
 int search(int arr[], int n, int x, int k)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == x)
            return i;
 
        // Jump the difference between current
        // array element and x divided by k
        // We use max here to make sure that i
        // moves at-least one step ahead.
        i = i + max(1, abs(arr[i]-x)/k);
    }
 
    cout << "number is not present!";
    return -1;
}
 