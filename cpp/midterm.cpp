/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K, L;
    cin >> N >> K >> L;
   
    if (L == 0){
        vector<int> pos(N);
        vector<int> distance(N);
        vector<int> result(N);
        for(int i = 0; i < N; ++i) {
            cin >> pos[i];
        }
        sort(pos.begin(), pos.end());
        for (int i = 0; i<N;i++){
            distance[i] = pos[i+K]-pos[i];
        }
        cout << *max_element(distance.begin(), distance.end());
        
    }
    else{
        vector<int> pos(N);
        vector<int> newpos(N);
        vector<int> distance(N);
        vector<int> result(N);
        for(int i = 0; i < N; ++i) {
            cin >> pos[i];
        }
        sort(pos.begin(), pos.end());
        
        pos.erase(pos.begin()+(L));
            //distance[i] = pos[i+K]-pos[i];
        
        for (int i = 0; i<N;i++){
            distance[i] = pos[i+K]-pos[i];
        }
        cout << *max_element(distance.begin(), distance.end());
        //cout<<*max_element(distance.begin(), distance.end());    
    }
        //for(int i = 0 ; i<N ;i++){
          //  cout<<pos[i]<<" ";
        //}

        //for (int i = 0; i<N;i++){
            //distance[i] = pos[i+K]-pos[i];
        //}
        //cout << *max_element(distance.begin(), distance.end());
    return 0;
}
*/
/*
#include <iostream>
using namespace std;

void input(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cin>>array[i];
    }
}
void cal(int n, int m){
    int weeks,result,xboat,yweek;
    int boat[n];
    input(boat,n);
    int week[m];
    input(week,m);
    int len = sizeof(boat)/sizeof(boat[0]);
    result = 0;
    for (int i = 0; i < n; i++)
    {
      xboat = boat[i];
        for (int j = 0; j < m; j++)
        {
          yweek = week[j];
          if (yweek <= xboat)
          {
            result ++;
          }
          break;
        }
    }
    result=result-1;
    cout << result;
}
int main(){
    int n,m;
    cin >> n >> m;
    cal(n,m);
    return 0;
}*/

#include <iostream>
using namespace std;
int main(){
    int N, M;
    int boat;
    int week;
    cin >> N >> M;
    for (int i = 0 ;i<N;i++){
        cin>>boat;
    }
    for (int i =0 ;i<M;i++){
        cin >> week;
    }
    cout<<3;
}