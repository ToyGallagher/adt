#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSumOfNonSamePair(const vector<int>& values) {
    int maxSum = INT_MIN; // Initialize maxSum with the smallest possible value

    // Iterate through all possible pairs of values
    for (size_t i = 0; i < values.size(); ++i) {
        for (size_t j = i + 1; j < values.size(); ++j) {
            // Calculate the sum of the current pair of values
            int sum = values[i] + values[j];

            // Update maxSum if the current sum is greater, and the indices are different
            if (sum > maxSum && i != j) {
                maxSum = sum;
            }
        }
    }

    return maxSum;
}

int main() {
    vector<int> values = {4,1,10,50,100};

    int result = maxSumOfNonSamePair(values);

    cout << "Maximum sum of two non-same values: " << result << endl;

    return 0;
}

