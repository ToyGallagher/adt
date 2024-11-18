#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> woods(n);
    vector<int> prefix_sums(n + 1, 0); // Prefix sums array initialized with 0
    
    // Input woods
    for (int i = 0; i < n; i++) {
        cin >> woods[i];
        prefix_sums[i + 1] = prefix_sums[i] + woods[i]; // Compute prefix sums
    }

    // Store all possible sums of subarrays in a set
    unordered_set<int> possible_sums;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += woods[j];
            possible_sums.insert(sum);
        }
    }

    // Answer queries
    for (int i = 0; i < q; i++) {
        int value;
        cin >> value;
        if (possible_sums.count(value)) {
            cout << "Y";
        } else {
            cout << "N";
        }
    }

    return 0;
}
