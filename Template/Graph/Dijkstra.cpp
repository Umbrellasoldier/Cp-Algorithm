template<typename T>
struct Dijkstra{
    vector<vector<pair<int,T>>> edge;
    vector<T> dis;
    vector<bool> vis;
    int n;

    Dijkstra(){}
    Dijkstra(int _n){
        n=_n;
        init(_n);
    }

    void init(int _n){
        edge.assign(_n,{});
        dis.assign(_n,numeric_limits<T>::max()/2);
        vis.assign(_n,false);
    }

    void add(int u,int v,T w){
        edge[u].push_back({v,w});
    }

    void work(int S){
        priority_queue<pair<T,int>,vector<pair<T,int>>,greater<pair<T,int>>> q;
        dis[S]=0;
        q.push({0,S});
        while(!q.empty()){
            auto [distance,u]=q.top();
            q.pop();
            if(vis[u])
                continue;
            vis[u]=true;
            for(auto [v,w]:edge[u]){
                if(dis[v]>distance+w){
                    dis[v]=distance+w;
                    q.push({dis[v],v});
                }
            }
        }
    }

    T dist(int u){
        return dis[u];
    }
};