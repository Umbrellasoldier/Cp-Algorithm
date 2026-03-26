template <typename T>
struct Segment_Tree{
    struct Node{
        int l,r,siz;
        T sum;
    };

    vector<Node> tr;

    Segment_Tree(){}
    Segment_Tree(const vector<T> &a){
        int n=a.size();
        tr.resize(n<<2);
        build(1,0,n-1,a);
    }

    Segment_Tree(int n){
        tr.resize(n<<2);
        build(1,0,n-1,vector<T>(n,0));
    }

    void init_data(int u,T val){
        tr[u].siz=1;
        tr[u].sum=val;
    }

    void merge(Node &u,Node &l,Node &r){
        u.siz=l.siz+r.siz;
        u.sum=l.sum+r.sum;
    }

    void build(int u,int l,int r,const vector<T> &a){
        tr[u].l=l,tr[u].r=r;
        if(l==r){
            init_data(u,a[l]);
            return;
        }
        int mid=l+r>>1;
        build(u<<1,l,mid,a),build(u<<1|1,mid+1,r,a);
        merge(tr[u],tr[u<<1],tr[u<<1|1]);
    }

    void modify_point(int u,int x,T y){
        if(tr[u].l==x&&tr[u].r==x){
            init_data(u,y);
            return;
        }
        int mid=tr[u].l+tr[u].r>>1;
        if(x<=mid){
            modify_point(u<<1,x,y);
        }else if(x>mid){
            modify_point(u<<1|1,x,y);
        }
        merge(tr[u],tr[u<<1],tr[u<<1|1]);
    }

    void modify_point(int x,T y){
        modify_point(1,x,y);
    }


    Node query(int u,int l,int r){
        if(l<=tr[u].l&&tr[u].r<=r){
            return tr[u];
        }
        int mid=tr[u].l+tr[u].r>>1;
        if(r<=mid)
            return query(u<<1,l,r);
        if(l>mid)
            return query(u<<1|1,l,r);
        Node res,left=query(u<<1,l,r),right=query(u<<1|1,l,r);
        merge(res,left,right);
        return res;
    }

    Node query(int l,int r){
        return query(1,l,r);
    }

};