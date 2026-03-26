#include <bits/stdc++.h>

using namespace std;
using i64=long long;

constexpr i64 inf=numeric_limits<i64>::max()/2;
constexpr int N=1000010;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    char s[N];
    scanf("%s",s+1);
    int n=strlen(s+1);

    vector<int> nxt(n+1,0);
    for(int i=2,j=0;i<=n;i++){
        while(j&&s[i]!=s[j+1])
            j=nxt[j];
        if(s[i]==s[j+1])
            j++;
        nxt[i]=j;
    }

    vector<vector<int>> edge(n+2);
    for(int i=1;i<=n;i++){
        edge[nxt[i]+1].push_back(i+1);
    }

    vector<i64> depth(n+2,inf);
    vector<vector<int>> fa(n+2,vector<int>(20,0));

    auto bfs=[&](int root){
        depth[0]=0,depth[root]=1;
        queue<int> q;
        q.push(root);
        while(q.size()){
            int u=q.front();
            q.pop();
            for(auto v:edge[u]){
                depth[v]=depth[u]+1;
                fa[v][0]=u;
                q.push(v);
                for(int i=1;i<=20;i++)
                    fa[v][i]=fa[fa[v][i-1]][i-1];
            }
        }
        return;
    };

    bfs(1);


    auto lca=[&](int a,int b){
        if(depth[a]<depth[b])
            swap(a,b);
        for(int i=20;i>=0;i--)
            if(depth[fa[a][i]]>=depth[b])
                a=fa[a][i];
        if(a==b)
            return a;
        for(int i=20;i>=0;i--)
            if(fa[a][i]!=fa[b][i])
                a=fa[a][i],b=fa[b][i];
        return fa[a][0];
    };


    int m;
    scanf("%d",&m);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        a++,b++;
        int p=lca(a,b);
        if(p==a||p==b)
            p=fa[p][0];
        p--;
        printf("%d\n",p);
    }

    return 0;
}