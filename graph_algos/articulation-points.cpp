#include <bits/stdc++.h>
using namespace std;

const ll mod = 1e9 + 7;
const int maxn = 1e5 + 5;
void pre(){

}

int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;
vector<int> cutPoints;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                cutPoints.push_back(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        cutPoints.push_back(v);
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
}

void solve() {
   
}

int main(){
    ios::sync_with_stdio(0);    
    cin.tie(0); cout.tie(0);

    int TC = 1;
    // cin >> TC;
    pre();
    while(TC--){    
        solve();
        cout << "\n";
    }
    return 0;
}

