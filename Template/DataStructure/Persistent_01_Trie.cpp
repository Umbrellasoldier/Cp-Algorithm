#include <bits/stdc++.h>

using namespace std;
using i64=long long;

constexpr i64 inf=numeric_limits<i64>::max()/2;
constexpr int N=600010,M=25,MAXN=N*M;

struct Persistent_01_Trie{
	int a[N]={0};
	int trie[MAXN][2],cnt[MAXN]={-1};
	int root[N],idx=0;

	void Insert(int i){
		root[i]=++idx;
		if(i){
			insert(i,M,root[i-1],root[i]);
		}else{
			insert(0,M,0,root[0]);
		}
	}

	void insert(int i,int k,int p,int q){
		if(k<0){
			cnt[q]=i;
			return;
		}
		int u=a[i]>>k&1;
		if(p){
			trie[q][1-u]=trie[p][1-u];
		}
		trie[q][u]=++idx;
		insert(i,k-1,trie[p][u],trie[q][u]);
		cnt[q]=max(cnt[trie[q][0]],cnt[trie[q][1]]);
	}

	int query(int l,int r,int x){
		int res=0;
		for(int i=M;i>=0;i--){
			int u=x>>i&1;
			if(cnt[trie[r][1-u]]>=l){
				res+=1<<i;
				r=trie[r][1-u];
			}else{
				r=trie[r][u];
			}
		}
		return res;
	}


}Ptrie;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin>>n>>m;

	Ptrie.Insert(0);

	for(int i=1;i<=n;i++){
		cin>>Ptrie.a[i];
		Ptrie.a[i]^=Ptrie.a[i-1];
		Ptrie.Insert(i);
	}

	while(m--){
		string c;
		cin>>c;
		if(c=="A"){
			cin>>Ptrie.a[++n];
			Ptrie.a[n]^=Ptrie.a[n-1];
			Ptrie.Insert(n);
		}else{
			int l,r,x;
			cin>>l>>r>>x;
			cout<<Ptrie.query(l-1,Ptrie.root[r-1],x^Ptrie.a[n])<<"\n";
		}
	}


	return 0;
}