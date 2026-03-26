#include <bits/stdc++.h>

using i64=long long;

constexpr int MAXN=1010;

struct Segment_Tree_2D{
	int n,m;
	i64 a[MAXN][MAXN];
	struct Node{
		int xl,xr,yl,yr;
		int sum;
	}tr_2D[MAXN*4][MAXN*4];

	void merge(Node &u,Node &l,Node &r){
		u.sum=l.sum+r.sum;
	}

	void build_y(int ux,int lx,int rx,int uy,int ly,int ry){
		tr_2D[ux][uy]={lx,rx,ly,ry};
		if(ly==ry){
			if(lx==rx)
				tr_2D[ux][uy].sum=a[lx][ly];
			else
				merge(tr_2D[ux][uy],tr_2D[ux<<1][uy],tr_2D[ux<<1|1][uy]);
			return;
		}
		int mid=ly+ry>>1;
		build_y(ux,lx,rx,uy<<1,ly,mid),build_y(ux,lx,rx,uy<<1|1,mid+1,ry);
		merge(tr_2D[ux][uy],tr_2D[ux][uy<<1],tr_2D[ux][uy<<1|1]);
	}

	void build_x(int ux,int lx,int rx){
		if(lx!=rx){
			int mid=lx+rx>>1;
			build_x(ux<<1,lx,mid),build_x(ux<<1|1,mid+1,rx);
		}
		build_y(ux,lx,rx,1,1,m);
	}

	Node query_y(int ux,int uy,int ly,int ry){
		if(ly<=tr_2D[ux][uy].yl&&tr_2D[ux][uy].yr<=ry){
			return tr_2D[ux][uy];
		}
		int mid=tr_2D[ux][uy].yl+tr_2D[ux][uy].yr>>1;
		if(ry<=mid)
			return query_y(ux,uy<<1,ly,ry);
		if(ly>mid)
			return query_y(ux,uy<<1|1,ly,ry);
		Node res,left=query_y(ux,uy<<1,ly,ry),right=query_y(ux,uy<<1|1,ly,ry);
		merge(res,left,right);
		return res;
	}

	Node query_x(int ux,int lx,int rx,int ly,int ry){
		if(lx<=tr_2D[ux][1].xl&&tr_2D[ux][1].xr<=rx){
			return query_y(ux,1,ly,ry);
		}
		int mid=tr_2D[ux][1].xl+tr_2D[ux][1].xr>>1;
		if(rx<=mid)
			return query_x(ux<<1,lx,rx,ly,ry);
		if(lx>mid)
			return query_x(ux<<1|1,lx,rx,ly,ry);
		Node res,left=query_x(ux<<1,lx,rx,ly,ry),right=query_x(ux<<1|1,lx,rx,ly,ry);
		merge(res,left,right);
		return res;
	}

	void modify_y(int ux,int uy,int x,int y,i64 val){
		if(tr_2D[ux][uy].yl==tr_2D[ux][uy].yr){
			if(tr_2D[ux][uy].xl==tr_2D[ux][uy].xr){
				tr_2D[ux][uy].sum=val;
			}else{
				merge(tr_2D[ux][uy],tr_2D[ux<<1][uy],tr_2D[ux<<1|1][uy]);
			}
			return;
		}
		int mid=tr_2D[ux][uy].yl+tr_2D[ux][uy].yr>>1;
		if(y<mid)
			modify_y(ux,uy<<1,x,y,val);
		else
			modify_y(ux,uy<<1|1,x,y,val);
	}

	void modify_x(int ux,int x,int y,i64 val){
		if(tr_2D[ux][1].xl!=tr_2D[ux][1].xr){
			int mid=tr_2D[ux][1].xl+tr_2D[ux][1].xr>>1;
			if(x<=mid)
				modify_x(ux<<1,x,y,val);
			else
				modify_x(ux<<1|1,x,y,val);
		}
		modify_y(ux,1,x,y,val);
	}

}SegTr_2D;