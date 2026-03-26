// #pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>

using namespace std;
using i64=long long;
using u64=unsigned long long;

constexpr i64 INF=numeric_limits<i64>::max()/2;
constexpr int inf=numeric_limits<int>::max()/2;

struct Strongly_Connected_Components{
    vector<vector<int>> edge,edgerev;
    vector<int> out,bel;
    vector<bool> vis;
    int n,cnt;

    Strongly_Connected_Components(){}
    Strongly_Connected_Components(int _n){
        init(_n);
    }

    void init(int _n){
        n=_n;
        edge.assign(n,{});
        edgerev.assign(n,{});
        out.clear();
        bel.assign(n,-1);
        vis.assign(n,false);
        cnt=0;
    }

    void dfs1(int u){
        vis[u]=true;
        for(auto v:edge[u]){
            if(!vis[v])
                dfs1(v);
        }
        out.push_back(u);
    }

    void dfs2(int u){
        bel[u]=cnt;
        for(auto v:edgerev[u]){
            if(bel[v]==-1)
                dfs2(v);
        }
    }

    void add(int u,int v){
        edge[u].push_back(v);
        edgerev[v].push_back(u);
    }

    vector<int> work(){
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs1(i);
        }
        reverse(out.begin(),out.end());
        for(auto u:out){
            if(bel[u]==-1){
                dfs2(u);
                cnt++;
            }
        }
        return bel;
    }
};
