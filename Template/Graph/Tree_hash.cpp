const u64 mask=mt19937_64(chrono::steady_clock::now().time_since_epoch().count())();

u64 shift(u64 x){
    x^=mask;
    x^=x<<13;
    x^=x>>7;
    x^=x<<17;
    x^=mask;
    return x;
}

int n;
vector<vector<int>> G;
vector<u64> _hash;
set<u64> S;

void dfs(int u,int pa){
    _hash[u]=1;
    for(auto v:G[u]){
        if(v==pa){
            continue;
        }
        dfs(v,u);
        _hash[u]+=shift(_hash[v]);
    }
    S.insert(_hash[u]);
}