struct Disjoint_Set_Unoin{
    vector<int> fa,siz,d;
    
    Disjoint_Set_Unoin(){}
    Disjoint_Set_Unoin(int n){
        init(n);
    }
    
    void init(int n){
        fa.resize(n);
        for(int i=0;i<n;i++)
            fa[i]=i;
        siz.assign(n,1);
        d.assign(n,0);
    }
    
    int find(int x){
        if(x!=fa[x]){
            int t=find(fa[x]);
            d[x]+=d[fa[x]];
            fa[x]=t;
        }
        return fa[x];
    }
    
    bool same(int x, int y){
        return find(x)==find(y);
    }
    

    bool merge(int x, int y,int z){ // d[x]=d[y]+z
        int px=find(x),py=find(y);
        if(px==py){
            return false;
        }
        d[px]=z-d[x]+d[y];
        siz[py]+=siz[px];
        fa[px]=py;
        return true;
    }
    
    int size(int x){
        return siz[find(x)];
    }

    int dep(int x){
        find(x);
        return d[x];
    }
};