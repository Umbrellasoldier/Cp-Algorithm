constexpr int N=100010,MAXN=100010;

struct Node{
    int l,r;
    i64 sum,add;
};

struct Segment_Tree{
    i64 a[MAXN];
    Node tr[MAXN<<2];

    void merge(Node &u,Node &l,Node &r){
        u.sum=(l.sum+r.sum);
    }

    void init_data(int u,i64 val){
        tr[u].sum=val;
    }

    void init_tag(int u){
        tr[u].add=0;
    }

    void build(int u,int l,int r){
        tr[u].l=l,tr[u].r=r;
        init_tag(u);
        if(l==r){
            init_data(u,a[l]);
            return;
        }
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        merge(tr[u],tr[u<<1],tr[u<<1|1]);
    }

    void addtag(int u,i64 x){
        tr[u].add+=x;
        tr[u].sum+=(i64)(tr[u].r-tr[u].l+1)*x;
    }

    void push(int u){
        if(tr[u].add){
            addtag(u<<1,tr[u].add);
            addtag(u<<1|1,tr[u].add);
            init_tag(u);
        }
    }

    Node query(int u,int l,int r){
        if(l<=tr[u].l&&tr[u].r<=r){
            return tr[u];
        }
        push(u);// work if modify_range
        int mid=tr[u].l+tr[u].r>>1;
        if(r<=mid)
            return query(u<<1,l,r);
        if(l>mid)
            return query(u<<1|1,l,r);
        Node res,left=query(u<<1,l,r),right=query(u<<1|1,l,r);
        merge(res,left,right);
        return res;
    }

    void modify_range(int u,int l,int r,i64 x){
        if(l<=tr[u].l&&tr[u].r<=r){
            addtag(u,x);
            return;
        }
        push(u);
        int mid=tr[u].l+tr[u].r>>1;
        if(l<=mid)
            modify_range(u<<1,l,r,x);
        if(r>mid)
            modify_range(u<<1|1,l,r,x);
        merge(tr[u],tr[u<<1],tr[u<<1|1]);
    }
}T;


int a[N],siz[N],son[N],fa[N],dep[N],tp[N],idx[N],L[N],R[N];
vector<vector<int>> edge(N,vector<int>{});
vector<int> dfn(N,0);
int time_stamp;

// vector<vector<int>> chain(N,vector<int>{});

int dfs1(int u,int depth,int father){
    siz[u]=1,dep[u]=depth,fa[u]=father;
    for(auto v:edge[u]){
        if(v==father)
            continue;
        siz[u]+=dfs1(v,depth+1,u);
        if(!son[u]||(siz[v]>siz[son[u]]))
            son[u]=v;
    }
    return siz[u];
}

void dfs2(int u,int top){
    idx[u]=++time_stamp;
    dfn[time_stamp]=u;
    tp[u]=top;
    L[u]=time_stamp;
    // chain[top].push_back(u);
    if(son[u])
        dfs2(son[u],top);
    for(auto v:edge[u]){
        if(v==fa[u]||v==son[u])
            continue;
        dfs2(v,v);
    }
    R[u]=time_stamp;
}

void chain_add(int x,int y,int z){
    while(tp[x]!=tp[y]){
        if(dep[tp[x]]<dep[tp[y]])
            swap(x,y);
        T.modify_range(1,idx[tp[x]],idx[x],z);
        x=fa[tp[x]];
    }
    if(dep[x]>dep[y])
        swap(x,y);
    T.modify_range(1,idx[x],idx[y],z);
    return;
}

i64 chain_query(int x,int y){
    i64 res=0;
    while(tp[x]!=tp[y]){
        if(dep[tp[x]]<dep[tp[y]])
            swap(x,y);
        res+=T.query(1,idx[tp[x]],idx[x]).sum;
        x=fa[tp[x]];
    }
    if(dep[x]>dep[y])
        swap(x,y);
    res+=T.query(1,idx[x],idx[y]).sum;
    return res;

}

void tree_add(int x,int z){
    T.modify_range(1,L[x],R[x],z);
}

i64 tree_query(int x){
    i64 res=T.query(1,L[x],R[x]).sum;
    return res;
}

int lca(int x,int y){
    while(tp[x]!=tp[y]){
        if(dep[x]<dep[y])
            swap(x,y);
        x=fa[tp[x]];
    }
    return dep[x]<dep[y]?x:y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,root;

    dfs1(root,0,0);
    dfs2(root,root);

    for(int i=1;i<=time_stamp;i++)
        T.a[i]=a[dfn[i]];

    T.build(1,1,n);



    return 0;
}
