template<class T>
struct MinCostFlow{
    struct _Edge{
        int to;
        T cap;
        T cost;
        _Edge(int to_,T cap_,T cost_):to(to_),cap(cap_),cost(cost_){}
    };
    const T inf=numeric_limits<T>::max()/2;
    int n;
    vector<_Edge> e;
    vector<vector<int>> g;
    vector<T> dis;
    vector<int> pre;
    vector<bool> vis;
    bool spfa(int s,int t){
        dis.assign(n,inf);
        pre.assign(n,-1);
        queue<int> que;
        dis[s]=0;
        que.push(s);
        while(!que.empty()){
            int u=que.front();
            que.pop();
            vis[u]=false;
            for(int i:g[u]){
                int v=e[i].to;
                T cap=e[i].cap;
                T cost=e[i].cost;
                if(cap>0&&dis[v]>dis[u]+cost){
                    dis[v]=dis[u]+cost;
                    pre[v]=i;
                    if(!vis[v]){
                        que.push(v);
                        vis[v]=true;
                    }
                }
            }
        }
        return dis[t]!=inf;
    }
    MinCostFlow(){}
    MinCostFlow(int n_){
        init(n_);
    }
    void init(int n_){
        n=n_;
        e.clear();
        g.assign(n,{});
        vis.assign(n,false);
    }
    void addEdge(int u,int v,T cap,T cost){
        g[u].push_back(e.size());
        e.emplace_back(v,cap,cost);
        g[v].push_back(e.size());
        e.emplace_back(u,0,-cost);
    }
    pair<T,T> flow(int s,int t){
        T flow=0;
        T cost=0;
        while(spfa(s,t)){
            T aug=inf;
            for(int i=t;i!=s;i=e[pre[i]^1].to){
                aug=min(aug,e[pre[i]].cap);
            }
            for(int i=t;i!=s;i=e[pre[i]^1].to){
                e[pre[i]].cap-=aug;
                e[pre[i]^1].cap+=aug;
            }
            flow+=aug;
            cost+=aug*dis[t];
        }
        return make_pair(flow,cost);
    }
    struct Edge{
        int from;
        int to;
        T cap;
        T cost;
        T flow;
    };
    vector<Edge> edges(){
        vector<Edge> a;
        for(int i=0;i<e.size();i+=2){
            Edge x;
            x.from=e[i+1].to;
            x.to=e[i].to;
            x.cap=e[i].cap+e[i+1].cap;
            x.cost=e[i].cost;
            x.flow=e[i+1].cap;
            a.push_back(x);
        }
        return a;
    }
};