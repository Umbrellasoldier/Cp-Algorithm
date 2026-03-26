struct Node{
	int l,r,siz;
	i64 sum;
};

struct Segment_Tree{
	vector<Node> tr;

	Segment_Tree(){}
	Segment_Tree(const vector<i64> &a){
		int n=a.size()-1;
		tr.resize(n<<2);
		build(1,1,n,a);
	}

	void merge(Node &u,Node &l,Node &r){
		u.siz=l.siz+r.siz;
		u.sum=l.sum+r.sum;
	}

	void init_data(int u,i64 val){
        tr[u].siz=1;
		tr[u].sum=val;
	}

	void build(int u,int l,int r,const vector<i64> &a){
		tr[u].l=l,tr[u].r=r;
		if(l==r){
			init_data(u,a[l]);
			return;
		}
		int mid=l+r>>1;
		build(u<<1,l,mid,a),build(u<<1|1,mid+1,r,a);
		merge(tr[u],tr[u<<1],tr[u<<1|1]);
	}

	void modify_point(int u,int x,i64 y){
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

};