
// Function to find majority element in O(1) space
int findMajority(int arr[], int n)
{
	int i, maj = -1, freq = 0;
	// Finding majority maj
	for (i = 0; i < n; i++) {
		if (freq == 0) {
			maj = arr[i];
			freq = 1;
		}
		else {
			if (arr[i] == maj)
				freq++;
			else
				freq--;
		}
	}
	int count = 0;
	// Checking if majority candidate occurs more than n/2
	// times
	for (i = 0; i < n; i++) {
		if (arr[i] == maj)
			count++;
	}

	if (count > n / 2)
		return maj;
	return -1; // no majority candidate exists
}
// explanation:
//  if the curr element is equal to majority element we inc the freq, 
//  else we dec the freq. Decreasing the freq means we're decreasing the
//  winning probability of the current major element and if freq 
//  becomes 0 => freq of majority element = freq of minority which means 
//  the current major element cannot be our ans and hence we update the 
//  majority element with the current new element 