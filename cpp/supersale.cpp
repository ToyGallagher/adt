#include <iostream>
#include <cstring>
using namespace std;

#define MAX_ITEMS 1005
#define MAX_WEIGHT 105

int dp[MAX_ITEMS][MAX_WEIGHT], prices[MAX_ITEMS], weights[MAX_ITEMS];

int maxObjectValue(int currentItemIndex, int remainingWeight, int itemCount) {
    if (currentItemIndex >= itemCount) return 0;
    if (dp[currentItemIndex][remainingWeight] != -1) return dp[currentItemIndex][remainingWeight];

    int valueWithoutCurrentItem = maxObjectValue(currentItemIndex + 1, remainingWeight, itemCount);
    int valueWithCurrentItem = 0;
    if (weights[currentItemIndex] <= remainingWeight)
        valueWithCurrentItem = prices[currentItemIndex] + maxObjectValue(currentItemIndex + 1, remainingWeight - weights[currentItemIndex], itemCount);

    return dp[currentItemIndex][remainingWeight] = max(valueWithoutCurrentItem, valueWithCurrentItem);
}

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int itemCount, maxWeightPerPerson;
        cin >> itemCount;
        for (int i = 0; i < itemCount; i++)
            cin >> prices[i] >> weights[i];

        int familyMembers, totalMaxValue = 0;
        cin >> familyMembers;
        while (familyMembers--) {
            cin >> maxWeightPerPerson;
            memset(dp, -1, sizeof(dp));
            totalMaxValue += maxObjectValue(0, maxWeightPerPerson, itemCount);
        }
        cout << totalMaxValue << endl;
    }
    return 0;
}
