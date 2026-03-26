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
		build(1,0,n-1,a);
	}

	Segment_Tree(int n){
		tr.resize(n<<2);
		build(1,0,n-1,vector<T>(n,0));
	}

	void merge(Node &u,Node &l,Node &r){
		u.siz=l.siz+r.siz;
		u.sum=l.sum+r.sum;
	}

	void init_data(int u,T val){
        tr[u].siz=1;
		tr[u].sum=val;
	}

	void init_tag(int u){
		tr[u].tag=0;
	}

	void build(int u,int l,int r,const vector<T> &a){
		tr[u].l=l,tr[u].r=r;
		init_tag(u);
		if(l==r){
			init_data(u,a[l]);
			return;
		}
		int mid=l+r>>1;
		build(u<<1,l,mid,a),build(u<<1|1,mid+1,r,a);
		merge(tr[u],tr[u<<1],tr[u<<1|1]);
	}

	void addtag(int u,T x){
		tr[u].tag+=x;
		tr[u].sum+=x*tr[u].siz;
	}

	void push(int u){
		if(tr[u].tag){
			addtag(u<<1,tr[u].tag);
			addtag(u<<1|1,tr[u].tag);
			init_tag(u);
		}
	}

	Node query(int u,int l,int r){
		if(l>r){
			return Node();
		}
		if(l<=tr[u].l&&tr[u].r<=r){
			return tr[u];
		}
		push(u);
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

	void modify_range(int u,int l,int r,T x){
		if(l>r){
			return;
		}
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

	void modify_range(int l,int r,T x){
		modify_range(1,l,r,x);
	}

};