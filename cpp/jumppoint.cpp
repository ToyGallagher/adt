/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define structure for intervals
struct Interval {
    int start;
    int end;
};

// Comparator function for sorting intervals based on end times
bool compareIntervals(const Interval& a, const Interval& b) {
    return a.end < b.end;
}

// Function to count non-overlapping intervals
int countNonOverlappingIntervals(vector<Interval>& intervals) {
    if (intervals.empty()) return 0;

    // Sort intervals based on end times
    sort(intervals.begin(), intervals.end(), compareIntervals);

    int count = 1; // Initialize count with 1 for the first interval
    int prevEnd = intervals[0].end; // Initialize previous end time

    // Iterate through sorted intervals and count non-overlapping intervals
    for (int i = 1; i < intervals.size(); ++i) {
        // If the current interval does not overlap with the previous one, increment count
        if (intervals[i].start >= prevEnd) {
            count++;
            prevEnd = intervals[i].end; // Update previous end time
        }
    }

    return count;
}

int main() {
    int n;
    
    cin >> n;

    // Input intervals
    vector<Interval> intervals(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].start >> intervals[i].end;
    }

    // Count non-overlapping intervals
    int count = countNonOverlappingIntervals(intervals);

    // Output the result
    cout << count << endl;

    return 0;
}*/

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;*/

#include <iostream>
using namespace std;

int main() {
    // Declare a 2D array with 3 rows and 4 columns
    int arr[3][4];

    // Initialize the elements of the array
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            arr[i][j] = i * 4 + j; // Example initialization
        }
    }

    // Access and print the elements of the array
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}