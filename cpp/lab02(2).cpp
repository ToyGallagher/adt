#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX_SIZE = 100000;

int main() {
    int t, s, b[MAX_SIZE];

    while (cin >> t && t != 0) {
        vector<int> v;
        int f = 0;

        while (true) {
            for (int i = 0; i < t; i++) {
                cin >> b[i];
                if (b[i] == 0) {
                    f = 1;
                    break;
                }
            }

            for (int i = 1; i <= t; i++) {
                v.push_back(i);
            }

            if (f == 1) {
                f = 0;
                cout << "\n";
                break;
            }

            stack<int> st;
            int c = 0;
            s = v.size();

            for (int i = 0; i < t; i++) {
                for (int j = 0; j < s; j++) {
                    if (b[i] == v[j]) {
                        v[j] = -1;
                        c++;
                        break;
                    } else if (b[i] != v[j]) {
                        if (st.empty() || st.top() != b[i]) {
                            if (v[j] != -1) {
                                st.push(v[j]);
                                v[j] = -1;
                                c++;
                            }
                        } else if (st.top() == b[i]) {
                            st.pop();
                            break;
                        }
                    } else {
                        c++;
                    }
                }

                if (c > t) {
                    break;
                }
            }

            v.clear();

            if (!st.empty()) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }
        }
    }

    return 0;
}