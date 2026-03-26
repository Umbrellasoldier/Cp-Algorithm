#include <bits/stdc++.h>

using namespace std;
using i64=long long;

constexpr i64 INF=numeric_limits<i64>::max()/2;
constexpr int inf=numeric_limits<int>::max()/2;

struct Two_Sat{
    vector<vector<int>> edge;
    vector<bool> vis;
    vector<int> S;
    int cnt,n;

    Two_Sat(){}
    Two_Sat(int _n){
        init(_n);
    }

    void init(int _n){
        n=_n;
        edge.resize(2*n,vector<int>{});
        vis.resize(2*n);
        S.resize(n);
    }

    void addClause(int x,int y){
        edge[x].push_back(y);
    }

    bool satisfiable(){
        auto dfs=[&](auto dfs,int u)->bool{
            if(vis[u^1])
                return false;
            if(vis[u])
                return true;
            vis[u]=true;
            S[cnt++]=u;
            for(auto v:edge[u]){
                if(!dfs(dfs,v))
                    return false;
            }
            return true;
        };

        for(int i=0;i<2*n;i+=2){
            if(!vis[i]&&!vis[i+1]){
                cnt=0;
                if(!dfs(dfs,i)){
                    while(cnt){
                        vis[S[--cnt]]=false;
                    }
                    if(!dfs(dfs,i+1)){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void answer(){
        for(int i=0;i<n;i++){
            if(vis[2*i]){
                cout<<0<<" ";
            }else{
                cout<<1<<" ";
            }
        }
    }
};
