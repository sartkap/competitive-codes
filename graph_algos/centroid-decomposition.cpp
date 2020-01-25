const int inf = 1e9;
const int maxn = 1e5 + 10;
vi v[maxn];
int sz[maxn];
int par[maxn];
set<int> g[maxn];
int nodes = 0;
int ans[maxn];
void dfs(int u,int p){
    sz[u] = 1;
    nodes++;
    for(auto x:g[u]){
        if(x == p)continue;
        dfs(x,u);
        sz[u] += sz[x]; 
    }
}
int cen(int u,int p){
    for(auto x:g[u]){
        if(x == p)continue;
        if(sz[x] > nodes/2) return cen(x,u);
    }
    return u;
}
void decom(int root,int p){
    nodes = 0;
    dfs(root,root);
    int centroid = cen(root,root);
    par[centroid] = p;
    for(auto x:g[centroid]){
        g[x].erase(centroid);
        decom(x,centroid);
    }
    g[centroid].clear();
}
// all info needed stored in par array in the end
