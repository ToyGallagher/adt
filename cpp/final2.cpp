/*#include <iostream>
#include <vector>
using namespace std;
int main(){
    long long n,x,y,z ;
    vector<long> setx;
    vector<long> sety;
    vector<long> setz;
    cin >> n ;
    for(int i = 0 ; i<n ;i++){
        cin >> x >> y >> z;
        setx.push_back(x);
        sety.push_back(y);
        setz.push_back(z);
    }
}*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxSatisfaction(int N, vector<vector<int>>& courses) {
    vector<vector<long long>> dp(N + 1, vector<long long>(3, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < 3; ++j) {
            long long prevSatisfaction = dp[i - 1][j];

            long long currSatisfaction = courses[i - 1][j];

            dp[i][j] = max(dp[i][j], prevSatisfaction + currSatisfaction);

            if (j < 2) {
                dp[i][j + 1] = max(dp[i][j + 1], prevSatisfaction + currSatisfaction);
            }

            if (j == 0) {
                dp[i][j + 2] = max(dp[i][j + 2], prevSatisfaction + currSatisfaction);
            }
        }
    }

    long long maxSatisfaction = *max_element(dp[N].begin(), dp[N].end());
    return maxSatisfaction;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> courses(N, vector<int>(3));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> courses[i][j];
        }
    }
    long long result = maxSatisfaction(N, courses);
    cout << result << endl;
    return 0;
}
