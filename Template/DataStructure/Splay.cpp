#include <bits/stdc++.h>

using namespace std;
using i64=long long;

constexpr int MAXN=100010;

struct Splay{
	int root,idx;
	struct Node{
		int ch[2],fa,size,cnt;
		i64 val;
		void init(i64 v,int p){
			val=v,fa=p;
			size=1,cnt=1;
		}
	}tr[MAXN];

	int chk(int x){
		return tr[tr[x].fa].ch[1]==x;
	}

	void pushup(int x){
		tr[x].size=tr[tr[x].ch[0]].size+tr[tr[x].ch[1]].size+tr[x].cnt;
	}

	void rotate(int x){
		int y=tr[x].fa,z=tr[y].fa,k=chk(x);
		tr[y].ch[k]=tr[x].ch[k^1],tr[x].ch[k^1]=y;
		tr[z].ch[chk(y)]=x,tr[x].fa=z;
		tr[x].ch[k^1]=y,tr[y].fa=x;
		pushup(y),pushup(x);
	}

	void splay(int x,int k){
		while(tr[x].fa!=k){
			int y=tr[x].fa,z=tr[y].fa;
			if(z!=k){
				if(chk(x)==chk(y))
					rotate(y);
				else
					rotate(x);
			}
			rotate(x);
		}
		if(!k)
			root=x;
	}

	void find(i64 x){
		if(!root)
			return;
		int u=root;
		while(tr[u].ch[x>tr[u].val]&&tr[u].val!=x)
			u=tr[u].ch[x>tr[u].val];
		splay(u,0);
	}

	void insert(i64 x){
		int u=root,p=0;
		while(u&&tr[u].val!=x){
			p=u,u=tr[u].ch[x>tr[u].val];
		}
		if(u){
			tr[u].cnt++;
		}else{
			u=++idx;
			if(p)
				tr[p].ch[x>tr[p].val]=u;
			tr[u].init(x,p);
		}
		splay(u,0);
	}

	int kth(int k){
		int u=root;
		while(true){
			if(tr[tr[u].ch[0]].size>=k){
				u=tr[u].ch[0];
			}else if(tr[tr[u].ch[0]].size+tr[u].cnt<k){
				k-=tr[tr[u].ch[0]].size+tr[u].cnt;
				u=tr[u].ch[1];
			}else{
				splay(u,0);
				return u;
			}
		}
	}

	int rank(i64 x){
		int res=0,u=root;
		while(u){
			if(tr[u].val>x){
				u=tr[u].ch[0];
			}else{
				res+=tr[tr[u].ch[0]].size;
				if(tr[u].val==x){
					splay(u,0);
					return res+1;
				}
				res+=tr[u].cnt;
				u=tr[u].ch[1];
			}
		}
		return res+1;
	}

	int pre(i64 x){
		find(x);
		if(tr[root].val<x)
			return root;
		int u=tr[root].ch[0];
		while(tr[u].ch[1])
			u=tr[u].ch[1];
		splay(u,0);
		return u;
	}

	int succ(i64 x){
		find(x);
		if(tr[root].val>x)
			return root;
		int u=tr[root].ch[1];
		while(tr[u].ch[0])
			u=tr[u].ch[0];
		splay(u,0);
		return u;
	}

	void remove(i64 x){
		int last=pre(x),next=succ(x);
		splay(last,0),splay(next,last);
		int del=tr[next].ch[0];
		if(tr[del].cnt>1){
			tr[del].cnt--;
			splay(del,0);
		}else{
			tr[next].ch[0]=0;
		}
		pushup(next),pushup(last);
	}


};