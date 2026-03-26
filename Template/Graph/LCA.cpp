vector<int> depth(n);
const int log_n=17;
vector<vector<int>> pa(n,vector<int>(log_n,-1));
auto dfs=[&](auto dfs,int u,int fa,int d)->void{
    depth[u]=d;
    pa[u][0]=fa;
    for(int i=1;i<log_n;i++){
        int p=pa[u][i-1];
        if(p!=-1)
            pa[u][i]=pa[p][i-1];
    }
    for(auto v:G[u]){
        if(v==fa){
            continue;
        }
        dfs(dfs,v,u,d+1);
    }

};
dfs(dfs,0,-1,0);

auto lca=[&](int u,int v)->int{
    if(depth[u]<depth[v])
        swap(u,v);
    for(int i=log_n-1;i>=0;i--){
        int p=pa[u][i];
        if(p!=-1&&depth[p]>=depth[v])
            u=p;
    }
    if(u==v)
        return u;
    for(int i=log_n-1;i>=0;i--){
        int pu=pa[u][i];
        int pv=pa[v][i];
        if(pu!=-1&&pv!=-1&&pu!=pv){
            u=pu;
            v=pv;
        }
    }
    return pa[u][0];
};