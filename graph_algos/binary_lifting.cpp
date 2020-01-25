void dfs1(int u,int p){
    timer++;
    tin[u] = timer;
    up[u][0] = p;
    repa(i,1,maxlog){
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for(auto x:v[u]){
        if(x == p)continue;
        d[x] = d[u] + 1;
        dfs1(x,u);
    }
    timer++;
    tout[u] = timer;
}
bool check(int u,int v){
    if(tin[u] <= tin[v] && tout[v] <= tout[u]){
        return true;
    }
    return false;
}
int lca(int u,int v){
    int u1 = u;
    if(check(u,v)){
        return abs(d[v]-d[u]);
    }
    else if(check(v,u)){
        return abs(d[v]-d[u]);
    }
    repr(i,maxlog){
        if(!check(up[u][i],v)){
            u = up[u][i];
        }
    }
    //return up[u][0];
    // uncomment the line above to find the node which is the lca
    // and lower one to to find distance between the two nodes whose
    // lca was to be found
    //return abs(d[up[u][0]] - d[u1]) + abs(d[up[u][0]] - d[v]);
}
