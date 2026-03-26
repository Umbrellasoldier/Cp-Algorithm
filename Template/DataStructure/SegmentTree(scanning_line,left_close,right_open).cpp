vector<int> y;

template <typename T>
struct Segment_Tree{
    struct Node{
        int l,r,siz;
        T sum;
        T tag;
    };
    
    vector<Node> tr;

    Segment_Tree(){}
    Segment_Tree(const vector<T> &a){
        int n=a.size();
        tr.resize(n<<2);
        build(1,0,n,a);
    }

    Segment_Tree(int n){
        tr.resize(n<<2);
        vector<T> a(n,0);
        build(1,0,n,a);
    }

    void merge(Node &u,Node &l,Node &r){
        u.siz=l.siz+r.siz;
        if(u.tag>0){
            u.sum=y[u.r]-y[u.l];
        }else if(u.l!=u.r-1){
            u.sum=l.sum+r.sum;
        }else{
            u.sum=0;
        }
    }

    void init_data(int u,T val){
        tr[u].siz=1;
        tr[u].sum=0;
        tr[u].tag=0;
    }

    void build(int u,int l,int r,const vector<T> &a){
        tr[u].l=l,tr[u].r=r;
        if(l==r-1){
            init_data(u,a[l]);
            return;
        }
        int mid=l+r>>1;
        build(u<<1,l,mid,a),build(u<<1|1,mid,r,a);
        merge(tr[u],tr[u<<1],tr[u<<1|1]);
    }

    void modify_range(int u,int l,int r,T x){
        if(l<=tr[u].l&&tr[u].r<=r){
            tr[u].tag+=x;
            merge(tr[u],tr[u<<1],tr[u<<1|1]);
            return;
        }
        int mid=tr[u].l+tr[u].r>>1;
        if(l<mid)
            modify_range(u<<1,l,r,x);
        if(r>mid)
            modify_range(u<<1|1,l,r,x);
        merge(tr[u],tr[u<<1],tr[u<<1|1]);
    }

    void modify_range(int l,int r,T x){
        modify_range(1,l,r,x);
    }
};