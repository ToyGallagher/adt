//searchsum
/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    const int MAX_N=100010;
    cin>>n>>m;
    int tmp = 0;
    vector<int> price,time;
    for (int i = 0; i < n; i++)
    {   
        int k;
        cin>>k;
        price.push_back(k+tmp);
        tmp += k;
    }
    for (int i = 0; i < m; i++)
    {   
        int j;
        cin>>j;
        time.push_back(j);
    }

    for (int i = 0; i < m; i++)
    {
        vector<int>::iterator upper1;
        upper1 = upper_bound(price.begin(), price.end(), time[i]);
        cout <<(upper1 - price.begin())<<endl;
    }
    
    return 0;

*/
/*
#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 10010;
int n,m;
vector <int> adj[MAX_N];
void read_input(){
    cin>>n>>m;
    for(int i =0 ;i<m;i++){
        int u,v;
        cin>>u>>v;u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
}*/
/*
#include <iostream>
using namespace std;
int main(){
    int n,k;
    int price[100001];
    int money[100001];
    int result[100000];
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>price[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin>>money[i];
    }
    for(int i = 0 ;i<k;i++){
        for(int j = 0 ; j<n;j++){
            if(money[i]>price[j]){
                result[i]+=1;
                int tod = money[i]-price[j];
                if(tod<price[j+1]){
                    break;
                }
            }
            if(money[i]<price[j]){
                result[i] = 0;
            }
        }
    
    }    
    for(int i = 0 ;i<k;i++){
        cout<<result[i]<<endl;
}
}
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    const int MAX_N=100010;
    cin>>n>>m;
    int tmp = 0;
    vector<int> price,time;
    for (int i = 0; i < n; i++)
    {   
        int k;
        cin>>k;
        price.push_back(k+tmp);
        tmp += k;
    }
    for (int i = 0; i < m; i++)
    {   
        int j;
        cin>>j;
        time.push_back(j);
    }

    for (int i = 0; i < m; i++)
    {
        vector<int>::iterator upper1;
        upper1 = upper_bound(price.begin(), price.end(), time[i]);
        cout <<(upper1 - price.begin())<<endl;
    }
    
    return 0;
}
*/

//productaccount
/*
#include <iostream>
using namespace std;
int main(){
    int n,choice;
    int product[200] = {0};
    int godung[200] = {0};
    int m;
    int x;
    int result[20];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>choice;
        if(choice == 1){
            cin>>m;
            cin>>product[m];
        }
        if(choice ==2){
            cin>>m;
            cout<<product[m]<<endl;
            //result[i] = product[m];
        }
        else if(choice == 3){
            cin>>m;
            cin>>x;
            if(x<product[m]){
                cout<<x<<endl;
                //result[i] = x;
                product[m] = product[m]-x;
            }
            else{
                cout<<product[m]<<endl;
                //result[i] = product[m];
            }
            

        }
    }
    //for(int i=0;i<6;i++){
        //cout<<result[i]<<endl;
    //}
}
*/
//ข้อ web cachใช้map
/*
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int	main(void)
{
	size_t	n, m, num;
	cin >> n >> m;

	set<size_t>		myset;
	vector<size_t>	res;

	while (n--)
	{
		cin >> num;
		myset.insert(num);
	}


	while (m--)
	{
		cin >> num;

		if (num > *--myset.end())
			res.push_back(*--myset.end());
		else if (num < *myset.begin())
			res.push_back(*myset.begin());
		else if (num == *myset.find(num))
			res.push_back(num);
		else
		{
			auto it1 = myset.upper_bound(num);
			auto it2 = it1;
            it1--;

			if (*it2 - num >= num - *it1)
				res.push_back(*it1);
			else
				res.push_back(*it2);
		}
	}

	for (int i = 0 ; i<res.size();i++)
		cout << res[i] << "\n";

	return (0);
}*/

/*
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int no_like, no_status, max_status = 0, max_like = 0; 
    cin >> no_like;

    map<int, int> status_count;
    vector<int> result;

    for (int i = 0; i < no_like; i++)
    {
        cin >> no_status;

        status_count[no_status]++;
        if (max_like <= status_count[no_status])
        {
            max_like = status_count[no_status];
            max_status = no_status;
        }

        result.push_back(max_status);
    }

    for (int val : result)
        cout << val << "\n";
    return 0;
}*/

//concount

#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> &visited, vector<vector<int>> &graph, int num)
{
	visited[num]++;
	for (int i = 0; i < graph[num].size(); i++)
		if (!visited[graph[num][i]])
			dfs(visited, graph, graph[num][i]);
}
 
int	main(void)
{
	int	n, m, a, b, res = 0;
	cin >> n >> m;

	vector<int>			visited(n, 0);
	vector<vector<int>>	graph(n);
	
	while (m--)
	{
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}

	for (int i = 0; i < n; i++)
		if (!visited[i])
		{
			res++;
			dfs(visited, graph, i);
		}

	cout << res;
	return (0);
}


/*
#include<bits/stdc++.h>
using namespace std;

void solve(int node,int edges){
	
	vector<int> indegree(node+1);
	queue<int> Q;
	vector<int> graph[node+1];
	
	for(int i = 1; i <= edges ; i++){
		int u , v;
        cin>>u>>v;
		graph[u].emplace_back(v);
		indegree[v] ++;
		
	}
	for(int i= 1; i <= node ; i++)
		if(indegree[i]==0)
			Q.push(i);
	
	while(!Q.empty()){
		
		int top = Q.front();
		Q.pop();
        cout<<top<<" ";
		
		for(auto x : graph[top]){
			indegree[x] --;
			if(indegree[x]==0)
				Q.push(x);
		}
		
	}
	cout << endl;
}


int main(){
	int n, m;
	while (cin >> n >> m && (n || m))
		solve(n,m);
	return 0;
}*/