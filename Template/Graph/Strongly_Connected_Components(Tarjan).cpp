// #pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>

using namespace std;
using i64=long long;
using u64=unsigned long long;

constexpr i64 INF=numeric_limits<i64>::max()/2;
constexpr int inf=numeric_limits<int>::max()/2;

struct Strongly_Connected_Components{
    vector<vector<int>> edge;
    vector<int> dfn,low,bel;
    vector<int> stk;
    int idx,cnt,n;

    Strongly_Connected_Components(){}
    Strongly_Connected_Components(int _n){
        init(_n);
    }

    void init(int _n){
        n=_n;
        edge.assign(n,{});
        dfn.assign(n,-1);
        low.assign(n,0);
        bel.assign(n,-1);
        stk.clear();
        idx=cnt=0;
    }

    void dfs(int u){
        dfn[u]=low[u]=++idx;
        stk.push_back(u);
        for(auto v:edge[u]){
            if(dfn[v]==-1){
                dfs(v);
                low[u]=min(low[u],low[v]);
            }else if(bel[v]==-1){
                low[u]=min(low[u],dfn[v]);
            }
        }
        if(dfn[u]==low[u]){
            int v;
            do{
                v=stk.back();
                bel[v]=cnt;
                stk.pop_back();
            }while(u!=v);
            cnt++;
        }
    }

    void add(int u,int v){
        edge[u].push_back(v);
    }

    vector<int> work(){
        for(int i=0;i<n;i++){
            if(dfn[i]==-1)
                dfs(i);
        }
        return bel;
    }
};
