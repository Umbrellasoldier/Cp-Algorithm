template<typename T>
struct SPFA{
    vector<vector<pair<int,T>>> G;
    vector<T> dis;
    vector<bool> vis;
    int n;

    SPFA(){}
    SPFA(int _n){
        n=_n;
        init(_n);
    }

    void init(int _n){
        G.assign(_n,{});
        dis.assign(_n,numeric_limits<T>::max()/2);
        vis.assign(_n,false);
    }

    void add(int u,int v,T w){
        G[u].push_back({v,w});
    }

    void work(int S){
        queue<int> q;
        dis[S]=0;
        vis[S]=true;
        q.push(S);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            vis[u]=false;
            for(auto [v,w]:G[u]){
                if(dis[u]+w<dis[v]){
                    dis[v]=dis[u]+w;
                    if(!vis[v]){
                        q.push(v);
                        vis[v]=true;
                    }
                }
            }
        }
    }

    T dist(int u){
        return dis[u];
    }
};