#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sticks(n);

    for (int i = 0; i < n; ++i) {
        cin >> sticks[i];
    }

    // Step 1: Sort the array to find the median
    sort(sticks.begin(), sticks.end());

    // Step 2: Find the median element
    int median = sticks[n / 2];

    // Step 3: Calculate the total cost to make all elements equal to the median
    long long total_cost = 0;
    for (int i = 0; i < n; ++i) {
        total_cost += abs(sticks[i] - median);
    }

    // Output the minimum total cost
    cout << total_cost << endl;

    return 0;
}


// Optimal Target Length:

// To minimize the sum of absolute differences, the best target length is not always the mean (average). Instead, the median of the array is the optimal choice.

// Why the Median is Optimal?

// Minimizing the Sum of Absolute Differences:
// If you choose any target length to the left or right of the median, the total cost will increase.
// The median ensures that half the elements are less than or equal to the target, and half are greater than or equal to it, leading to the smallest total distance moved.

// Key Takeaways:
// The median minimizes the sum of absolute differences.
// If n is odd, the median is the middle element. If n is even, both middle elements yield the same cost.
// This is a classic problem of minimizing absolute differences, and the solution lies in using median as the target length.