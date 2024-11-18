//เพนกวิน
/*
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int angle[n] , intersection = 0;
    for(int i = 0 ; i<n ; i++){
        cin >> angle[i];
    }
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<i ; j++){
            if (angle[i]>angle[j])
            {
                intersection += 1;
            }
            
        }
    }
    cout << intersection ;
}
*/

//เเซงรอบ
/*
#include <iostream>
using namespace std;
int main(){
    int n,k;
    int time[n];
    int timetwo[n];
    cin>>n>>k;
    for (int i = 0; i < n; i++){
        cin>>time[i];
        time[i] = timetwo[i];
    }
    for (int i = 0; i < n; i++){
       timetwo[i] = time[i]*2;
    }
    for(int i = 0 ; i<k-1;i++){
        for(int j = 0 ; j<n ; j++){
            
            if(timetwo[0]<time[j]){
                timetwo[j] = 0;
            }
        }
        for (int i = 0; i < n; i++){
            timetwo[i] = time[i]*2;
            }
    }    
    for(int i = 0 ; i<n ; i++){
        cout<<timetwo[i]<<endl;
    }
    
}
*/
/*
//ของขวัญเเละขโมย
#include <iostream>
using namespace std;
int main(){
    int n,k,t,res=0;
    cin>>n>>k>>t;
    
    int j = 1;
    while (true)
    {
        
        j+=k;
        res++;
        if(j>n){
            j%=n;
        }
        if(j==t){
            res++;
            break;
           
        }
        if(j==1){
            break;
        }
        

    }
    cout<<res;
}*/

//ข้อท้าย
/*
#include <iostream>
#include <string>

using namespace std;

int main() {
    string navigate;

    cin >> navigate;

    int x = 0, y = 0;

    for (char navigate : navigate) {
        switch (navigate) {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            case 'Z':
                x = 0;
                y = 0;
                break;
            default:
                break;
        }
    }

    cout << x << " " << y << endl;

    return 0;
}*/
/*
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
}*/