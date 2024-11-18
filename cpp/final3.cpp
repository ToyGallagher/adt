#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

const int MAX_N = 100010;

int num_vertices, num_edges;
vector<vector<int>> adj;
vector<vector<int>> weights;
vector<vector<int>> edge_status;

vector<pair<int,int>> edge_list;
vector<int> edge_weights;
vector<int> edge_statuses;

set<pair<int,int>> Q;

vector<pair<int,int>> sorted_edges;

void read_input(){
  cin >> num_vertices >> num_edges;
  
  adj.resize(num_vertices);
  weights.resize(num_vertices);
  edge_status.resize(num_vertices);

  for(int i = 0; i < num_edges; i++) {
    int a, b, weight;
    cin >> a >> b >> weight;  a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    
    weights[a].push_back(weight);
    weights[b].push_back(weight);
    
    //edge_status[a].push_back(status);
    //edge_status[b].push_back(status);

    edge_list.push_back(make_pair(a,b));
    edge_weights.push_back(weight);
    //edge_statuses.push_back(status);

    sorted_edges.push_back(make_pair(weight,i));
  }
}

vector<int> set_parent;
vector<int> set_rank;

void init_set(){
  set_parent.resize(num_vertices);
  set_rank.resize(num_vertices);

  for(int i=0; i<num_vertices; i++) {
    set_parent[i] = i;
    set_rank[i] = 1;
  }
}

int set_find(int u){
  if(set_parent[u] == u) return u;
  else return set_find(set_parent[u]);
}

void set_union(int pu, int pv){
  pu = set_find(pu);
  pv = set_find(pv);
  
  if(pu == pv) return;
  
  if(set_rank[pv] > set_rank[pu]) set_parent[pu] = pv;
  else if(set_rank[pu] > set_rank[pv]) set_parent[pv] = pu;
  else{
    set_parent[pv] = pu;
    set_rank[pu]++;
  }
}

int main(){
  int total_weight = 0;
  read_input();
  init_set();
  sort(sorted_edges.begin(), sorted_edges.end());
  for(int i=0; i<num_edges; i++) {
    int e = sorted_edges[i].second;
    int u = edge_list[e].first;
    int v = edge_list[e].second;
    //int status = edge_statuses[e];

    int pu = set_find(u);
    int pv = set_find(v);
    if(pu != pv ) set_union(pu,pv);
  }

  for(int i=0; i<num_edges; i++) {
    int e = sorted_edges[i].second;
    int u = edge_list[e].first;
    int v = edge_list[e].second;
    int weight = edge_weights[e];
    //int status = edge_statuses[e];

    int pu = set_find(u);
    int pv = set_find(v);
    if(pu != pv ) {
      total_weight += weight;
      set_union(pu,pv);
    }
  }
  
  cout << total_weight << endl;
  return 0;
}