// #pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>

using namespace std;
using i64=long long;
using u32=unsigned;
using u64=unsigned long long;

using i128=__int128;
using u128=unsigned __int128;

// constexpr int inf=numeric_limits<int>::max()/2;
// constexpr i64 INF=numeric_limits<i64>::max()/2;



void solve(){
    int n;
    cin>>n;
    vector<int> c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }

    vector<vector<int>> adj(n,vector<int>{});
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> siz(n),heavy(n,-1),L(n),R(n),dfn(n);
    int time=-1;
    auto dfs0=[&](auto dfs0,int u,int fa)->void{
        L[u]=++time;
        dfn[time]=u;
        siz[u]=1;
        for(auto v:adj[u]){
            if(v==fa){
                continue;
            }
            dfs0(dfs0,v,u);
            siz[u]+=siz[v];
            if(heavy[u]==-1||siz[heavy[u]]<siz[v]){
                heavy[u]=v;
            }
        }
        R[u]=time;
    };

    dfs0(dfs0,0,-1);

    vector<int> cnt(n+1);
    vector<i64> ans(n);
    map<int,i64,greater<int>> s;
    auto add=[&](int x)->void{
        if(cnt[x]!=0){
            s[cnt[x]]-=x;
            if(s[cnt[x]]==0){
                s.erase(cnt[x]);
            }
        }
        cnt[x]++;
        s[cnt[x]]+=x;
    };

    auto del=[&](int x)->void{
        s[cnt[x]]-=x;
        if(s[cnt[x]]==0){
            s.erase(cnt[x]);
        }
        cnt[x]--;
        if(cnt[x]!=0){
            s[cnt[x]]+=x;
        }
    };

    auto dfs1=[&](auto dfs1,int u,int fa,bool keep)->void{
        for(auto v:adj[u]){
            if(v==fa||v==heavy[u]){
                continue;
            }
            dfs1(dfs1,v,u,false);
        }
        if(heavy[u]!=-1){
            dfs1(dfs1,heavy[u],u,true);
        }
        for(auto v:adj[u]){
            if(v==fa||v==heavy[u]){
                continue;
            }
            for(int i=L[v];i<=R[v];i++){
                add(c[dfn[i]]);
            }
        }
        add(c[u]);
        ans[u]=s.begin()->second;
        if(!keep){
            for(int i=L[u];i<=R[u];i++){
                del(c[dfn[i]]);
            }
        }
    };

    dfs1(dfs1,0,-1,false);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" \n"[i==n-1];
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test=1;
    // cin>>test;
    while(test--){
        solve();
    }
 
    return 0;
}