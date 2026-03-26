# 数据结构

$01Trie$

```cpp
#include <bits/stdc++.h>

using namespace std;
using i64=long long;

constexpr i64 inf=numeric_limits<i64>::max()/2;
constexpr int N=3100010;

struct _01Trie{
    int trie[N][2],idx=0,cnt[N]={0};

    void insert(int x){
        int p=0;
        for(int i=30;i>=0;i--){
            int u=x>>i&1;
            if(!trie[p][u])
                trie[p][u]=++idx;
            p=trie[p][u];
        }
        cnt[p]++;
        return;
    }

    int query_xormax(int x){
        int p=0,res=0;
        for(int i=30;i>=0;i--){
            int u=x>>i&1;
            if(trie[p][1-u]){
                res+=1<<i;
                p=trie[p][1-u];
            }else{
                p=trie[p][u];
            }
        }
        return res;
    }

    bool query(int x){
        int p=0;
        for(int i=30;i>=0;i--){
            int u=x>>i&1;
            if(!trie[p][u]){
                return false;
            }else{
                p=trie[p][u];
            }
        }
        return true;
    }

};
```

$可持久化Trie$

```cpp
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
```

$字符串Trie$
```
class Node:
    __slots__='son','cnt'

    def __init__(self):
        self.son={}
        self.cnt=0

class Trie:
    def __init__(self):
        self.root=Node()

    def insert(self,s:str)->None:
        cur=self.root
        cur.cnt+=1
        for c in s:
            if c not in cur.son:
                cur.son[c]=Node()
            cur=cur.son[c]
            cur.cnt+=1

    def query(self, word: str)->int:
        cur=self.root
        for c in word:
            if c not in cur.son:
                return 0
            cur=cur.son[c]
        return cur.cnt
```


```
#include <bits/stdc++.h>

using namespace std;
using i64=long long;

constexpr i64 inf=numeric_limits<i64>::max()/2;
constexpr int N=2600010;

struct string_Trie{
    int trie[N][26],idx=0,cnt[N]={0};

    void insert(string s){
        int p=0,m=s.size();
        for(int i=0;i<m;i++){
            int u=s[i]-'a';
            if(!trie[p][u])
                trie[p][u]=++idx;
            p=trie[p][u];
        }
        cnt[p]++;
        return;
    }

    bool query(string s){
        int p=0,m=s.size();
        for(int i=0;i<m;i++){
            int u=s[i]-'a';
            if(!trie[p][u]){
                return false;
            }else{
                p=trie[p][u];
            }
        }
        return true;
    }
    
};
```

$树状数组$
```
class Fenwick:
    def __init__(self,n:int):
        self.fenwick=[0]*(n+1)  # 使用下标 1 到 n

    # a[i] 增加 val
    # 1 <= i <= n
    # 时间复杂度 O(log n)
    def add(self,i:int,val:int)->None:
        t=self.fenwick
        while i<len(t):
            t[i]+=val
            i+=i&-i

    # 计算前缀和 a[1]+...+a[i]
    # 1 <= i <= n
    # 时间复杂度 O(log n)
    def sum(self,i:int)->int:
        t=self.fenwick
        res=0
        while i>0:
            res+=t[i]
            i&=i-1
        return res

    # 计算区间和 a[l]+...+a[r]
    # 1 <= l <= r <= n
    # 时间复杂度 O(log n)
    def query(self,l:int,r:int)->int:
        if r<l:
            return 0
        return self.pre(r)-self.pre(l-1)

```


```
#include <bits/stdc++.h>

using namespace std;
using i64=long long;

struct Fenwick{
	static constexpr int N=100010;
	i64 fenwick[N];

	int lowbit(int x){
		return x&-x;
	}

	void add(int x,i64 k){
		while(x<N){
			fenwick[x]+=k;
			x+=lowbit(x);
		}
	}

	i64 sum(int x){
		i64 res=0;
		while(x){
			res+=fenwick[x];
			x-=lowbit(x);
		}
		return res;
	}
}Fenwk;
```

$二维树状数组$
```
template<typename T>
struct Fenwick_2D{
    vector<vector<T>> fenwick;
    int N,M;

    Fenwick_2D(){}
    Fenwick_2D(int n,int m){
        init(n,m);
    }

    void init(int n,int m){
        N=1<<(int(log2(n))+1);
        M=1<<(int(log2(m))+1);
        fenwick.assign(N,vector<T>(M,T{}));
    }

    int lowbit(int x){
        return x&-x;
    }

    void add(int x,int y,const T &k){
        for(int i=x;i<N;i+=lowbit(i)){
            for(int j=y;j<M;j+=lowbit(j)){
                fenwick[i][j]+=k;
            }
        }
    }

    T sum(int x,int y){
        T res{};
        for(int i=x;i;i-=lowbit(i)){
            for(int j=y;j;j-=lowbit(j)){
                res+=fenwick[i][j];
            }
        }
        return res;
    }
};
```


$重链剖分$

```
#include <bits/stdc++.h>

using namespace std;
using i64=long long;

constexpr i64 inf=numeric_limits<i64>::max()/2;
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

```

Mo's
```
struct Mo_s{
    vector<int> nums;
    int block_size;
    int n,m;
    Mo_s(){}
    Mo_s(const vector<int> &v){
        nums=v;
        n=nums.size();
    }

    struct Query{
        int l,r,idx;
    };

    vector<int> query(vector<vector<int>> queries){
        m=queries.size();

        vector<int> ans(m);
        block_size=ceil(n/sqrt(m));

        vector<Query> Q;
        for(int i=0;i<m;i++){
            int l=queries[i][0],r=queries[i][1];
            Q.emplace_back(Query{l,r,i});
        }

        sort(Q.begin(),Q.end(),[&](auto x,auto y){
            if(x.l/block_size!=y.l/block_size)
                return x.l/block_size<y.l/block_size;
            return (x.l/block_size%2)?(x.r<y.r):(x.r>y.r);
        });

        const int N=1000000;
        vector<int> cnt(N+1);
        int res=0;
        
        auto add=[&](int x)->void{
            res+=(++cnt[x]==1);
        };
        auto del=[&](int x)->void{
            res-=(--cnt[x]==0);
        };
        for(int i=0,l=0,r=-1;i<m;i++){
            auto [L,R,idx]=Q[i];
            while(r<R){
                add(nums[++r]);
            }
            while(r>R){
                del(nums[r--]);
            }
            while(l<L){
                del(nums[l++]);
            }
            while(l>L){
                add(nums[--l]);
            }
            ans[idx]=res;
        }
        return ans;
    }
};
```

Mo's(modify)
```
struct Query{
    int l,r,t,idx;
};
struct Modify{
    int pos,x;
};

struct Mo_s{
    vector<int> nums;
    int block_size;
    int n,m;
    int cnt_query;
    Mo_s(){}
    Mo_s(const vector<int> &v){
        nums=v;
        n=nums.size();
    }

    vector<int> query(vector<Query> queries,vector<Modify> modifies){
        cnt_query=queries.size();

        vector<int> ans(cnt_query);
        block_size=cbrt((double)n*n)+1;
        
        sort(queries.begin(),queries.end(),[&](auto x,auto y){
            if(x.l/block_size!=y.l/block_size)
                return x.l/block_size<y.l/block_size;
            if(x.r/block_size!=y.r/block_size)
                return x.r/block_size<y.r/block_size;
            return x.t<y.t;
        });

        const int N=1000000;
        vector<int> cnt(N+1);
        int res=0;
        auto add=[&](int x)->void{
            res+=(++cnt[x]==1);
        };
        auto del=[&](int x)->void{
            res-=(--cnt[x]==0);
        };

        for(int i=0,l=0,r=-1,last=-1;i<cnt_query;i++){
            auto [L,R,t,idx]=queries[i];
            while(r<R){
                add(nums[++r]);
            }
            while(r>R){
                del(nums[r--]);
            }
            while(l<L){
                del(nums[l++]);
            }
            while(l>L){
                add(nums[--l]);
            }
            while(last<t){
                last++;
                auto [pos,x]=modifies[last];
                if(l<=pos&&r>=pos){
                    add(x);
                    del(nums[pos]);
                }
                swap(modifies[last].x,nums[pos]);
            }
            while(last>t){
                auto [pos,x]=modifies[last];
                if(l<=pos&&r>=pos){
                    add(x);
                    del(nums[pos]);
                }
                swap(modifies[last].x,nums[pos]);
                last--;
            }
            ans[idx]=res;
        }
        return ans;
    }
};

// vector<Query> queries;
// vector<Modify> modifies;
// int cnt_modify=-1,cnt_query=0;
// for(int i=0;i<m;i++){
//     char op;
//     cin>>op;
//     if(op=='Q'){
//         int l,r;
//         cin>>l>>r;
//         l--,r--;
//         queries.push_back({l,r,cnt_modify,cnt_query++});
//     }else{
//         int p,x;
//         cin>>p>>x;
//         p--;
//         modifies.push_back({p,x});
//         cnt_modify++;
//     }
// }
```
Mo's(backup)
```
struct Mo_s{
    vector<int> nums;
    int BLOCK;
    int n,m;
    Mo_s(){}
    Mo_s(const vector<int> &v){
        nums=v;
        n=nums.size();
    }

    struct Query{
        int l,r,threshold,idx;
    };

    vector<int> query(vector<vector<int>> queries){
        m=queries.size();

        vector<int> ans(m,-1);

        unordered_map<int,int> cnt;
        int max_cnt=0,min_val=0;

        int block_size=ceil(n/sqrt(m));

        auto add=[&](int x)->void{
            cnt[x]++;
            if(cnt[x]>max_cnt){
                max_cnt=cnt[x];
                min_val=x;
            }else if(cnt[x]==max_cnt){
                min_val=min(min_val,x);
            }
        };

        vector<Query> Q;
        for(int i=0;i<m;i++){
            int l=queries[i][0],r=queries[i][1],threshold=queries[i][2];
            if(r-l>block_size){
                Q.emplace_back(Query{l,r,threshold,i});
                continue;
            }
            for(int j=l;j<=r;j++){
                add(nums[j]);
            }
            if(max_cnt>=threshold){
                ans[i]=min_val;
            }
            for(int j=l;j<=r;j++){
                cnt[nums[j]]--;
            }
            max_cnt=0;
        }

        sort(Q.begin(),Q.end(),[&](auto x,auto y){
            if(x.l/block_size!=y.l/block_size)
                return x.l/block_size<y.l/block_size;
            return x.r<y.r;
        });

        for(int i=0,r=0;i<Q.size();i++){
            auto [L,R,threshold,idx]=Q[i];
            int l0=(L/block_size+1)*block_size;
            if(i==0||L/block_size>Q[i-1].l/block_size){
                r=l0;
                cnt.clear();
                max_cnt=0;
            }
            while(r<=R){
                add(nums[r++]);
            }
            int tmp_max_cnt=max_cnt,tmp_min_val=min_val;
            for(int j=L;j<l0;j++){
                add(nums[j]);
            }
            if(max_cnt>=threshold){
                ans[idx]=min_val;
            }
            max_cnt=tmp_max_cnt;
            min_val=tmp_min_val;
            for(int j=L;j<l0;j++){
                cnt[nums[j]]--;
            }
        }
        return ans;
    }
};
```

# 字符串

$字符串hash$

```
constexpr int N=100010;

bool isprime(i64 x){
    if(x<2)
        return false;
    for(int i=2;i<=x/i;i++){
        if(x%i==0)
            return false;
    }
    return true;
}

i64 findprime(i64 x){
    while(!isprime(x))
        x++;
    return x;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const i64 Base=131ll;
const i64 mod1=findprime(rng()%900000000+100000000);
const i64 mod2=findprime(rng()%900000000+100000000);

i64 Hash1[N],Hash2[N];
i64 p1[N],p2[N];


pair<i64,i64> get(int l,int r){
    i64 h1=(Hash1[r]-Hash1[l-1]*p1[r-l+1]%mod1+mod1)%mod1;
    i64 h2=(Hash2[r]-Hash2[l-1]*p2[r-l+1]%mod2+mod2)%mod2;
    return {h1,h2};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n=10;
    string s=" abcdefghij";

    p1[0]=p2[0]=1;
    for(int i=1;i<=n;i++){
        p1[i]=p1[i-1]*Base%mod1;
        p2[i]=p2[i-1]*Base%mod2;
    }

    for(int i=1;i<=n;i++){
        Hash1[i]=(Hash1[i-1]*Base%mod1+s[i]-'a'+1)%mod1;
        Hash2[i]=(Hash2[i-1]*Base%mod2+s[i]-'a'+1)%mod2;
    }

    return 0;
}
```

```
bool isprime(i64 x){
    if(x<2)
        return false;
    for(int i=2;i<=x/i;i++){
        if(x%i==0)
            return false;
    }
    return true;
}

i64 findprime(i64 x){
    while(!isprime(x))
        x++;
    return x;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct StringHash{
    const i64 base=131ll;
    const i64 mod=findprime(rng()%900000000+100000000);
    vector<i64> pre;
    vector<i64> Pow;
    StringHash(){};
    StringHash(string s){
        int n=s.size();
        pre.assign(n,0);
        pre[0]=s[0];
        for(int i=1;i<n;i++){
            pre[i]=(pre[i-1]*base%mod+s[i])%mod;
        }
        Pow.assign(n+1,0);
        Pow[0]=1ll;
        for(int i=1;i<=n;i++){
            Pow[i]=Pow[i-1]*base%mod;
        }
    };

    i64 get(int l,int r){
        return (pre[r]-(l?pre[l-1]:0)*Pow[r-l+1]%mod+mod)%mod;
    }

    bool is_same(int l1,int r1,int l2,int r2){
        return get(l1,r1)==get(l2,r2);
    }

    i64 get_any_s_hash(string s){
        int n=s.size();
        i64 h=0;
        for(int i=0;i<n;i++){
            h=(h*base+s[i])%mod;
        }
        return h;
    }
};
```

```
class StringHash:
    def __init__(self,s:str):
        self.base=int(1e18)+3
        self.mod=randint(int(8e17),int(9e17))
        n=len(s)
        self.POW=[0]*(n+1)
        self.POW[0]=1
        for i in range(1,n+1):
            self.POW[i]=self.POW[i-1]*self.base%self.mod
        self.preffix=[0]*n
        self.preffix[0]=ord(s[0])
        for i in range(1,n):
            self.preffix[i]=self.preffix[i-1]*self.base+ord(s[i])
            self.preffix[i]%=self.mod

    def get_pre_hash(self,l,r)->int:
        return (self.preffix[r]-(self.preffix[l-1] if l else 0)*self.POW[r-l+1]%self.mod)%self.mod

    def is_same(self,l1,r1,l2,r2)->bool:
        return self.get_pre_hash(l1,r1)==self.get_pre_hash(l2,r2)

    def get_any_s_hash(self,s:str)->int:
        n=len(s)
        h=0
        for i in range(n):
            h=h*self.base+ord(s[i])
            h%=self.mod
        return h


#---------------------------------------


from random import randint


def isprime(x):
    if x<2:
        return False
    i=2
    while i<=x//i:
        if x%i==0:
            return False
        i+=1
    return True

def findprime(x):
    while not isprime(x):
        x+=1
    return x


n=10
s=' abcdefghij'

mod1=findprime(randint(1000000000,10000000000))
mod2=findprime(randint(1000000000,10000000000))
Base=131

h1=[0]*(n+1);h2=[0]*(n+1)
for i in range(1,n+1):
    h1[i]=(h1[i-1]*Base+ord(s[i])-ord('a')+1)%mod1
    h2[i]=(h2[i-1]*Base+ord(s[i])-ord('a')+1)%mod2


p1=[0]*(n+1);p2=[0]*(n+1)
p1[0]=p2[0]=1
for i in range(1,n+1):
    p1[i]=p1[i-1]*Base%mod1
    p2[i]=p2[i-1]*Base%mod2

def get(l,r):
    return [(h1[r]-h1[l-1]*p1[r-l+1])%mod1,(h2[r]-h2[l-1]*p2[r-l+1])%mod2]

```

$Border_Tree$

```
#include <bits/stdc++.h>

using namespace std;
using i64=long long;

constexpr i64 inf=numeric_limits<i64>::max()/2;
constexpr int N=1000010;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    char s[N];
    scanf("%s",s+1);
    int n=strlen(s+1);

    vector<int> nxt(n+1,0);
    for(int i=2,j=0;i<=n;i++){
        while(j&&s[i]!=s[j+1])
            j=nxt[j];
        if(s[i]==s[j+1])
            j++;
        nxt[i]=j;
    }

    vector<vector<int>> edge(n+2);
    for(int i=1;i<=n;i++){
        edge[nxt[i]+1].push_back(i+1);
    }

    vector<i64> depth(n+2,inf);
    vector<vector<int>> fa(n+2,vector<int>(20,0));

    auto bfs=[&](int root){
        depth[0]=0,depth[root]=1;
        queue<int> q;
        q.push(root);
        while(q.size()){
            int u=q.front();
            q.pop();
            for(auto v:edge[u]){
                depth[v]=depth[u]+1;
                fa[v][0]=u;
                q.push(v);
                for(int i=1;i<=20;i++)
                    fa[v][i]=fa[fa[v][i-1]][i-1];
            }
        }
        return;
    };

    bfs(1);


    auto lca=[&](int a,int b){
        if(depth[a]<depth[b])
            swap(a,b);
        for(int i=20;i>=0;i--)
            if(depth[fa[a][i]]>=depth[b])
                a=fa[a][i];
        if(a==b)
            return a;
        for(int i=20;i>=0;i--)
            if(fa[a][i]!=fa[b][i])
                a=fa[a][i],b=fa[b][i];
        return fa[a][0];
    };


    int m;
    scanf("%d",&m);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        a++,b++;
        int p=lca(a,b);
        if(p==a||p==b)
            p=fa[p][0];
        p--;
        printf("%d\n",p);
    }

    return 0;
}
```

$ACAM$

```
struct AhoCorasick{
    static constexpr int ALPHABET=26;
    struct Node{
        int len;
        int fail;
        array<int,ALPHABET> son;
        Node():len{0},fail{0},son{}{}
    };
    
    vector<Node> t;
    
    AhoCorasick(){
        init();
    }
    
    void init(){
        t.assign(2,Node());
        t[0].son.fill(1);
        t[0].len=-1;
    }
    
    int newNode(){
        t.emplace_back();
        return t.size()-1;
    }
    
    int add(const string &a){
        int p=1;
        for(auto c:a){
            int x=c-'a';
            if(t[p].son[x]==0){
                t[p].son[x]=newNode();
                t[t[p].son[x]].len=t[p].len+1;
            }
            p=t[p].son[x];
        }
        return p;
    }
    
    void build(){
        queue<int> q;
        q.push(1);
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            
            for(int i=0;i<ALPHABET;i++){
                if(t[x].son[i]==0){
                    t[x].son[i]=t[t[x].fail].son[i];
                }else{
                    t[t[x].son[i]].fail=t[t[x].fail].son[i];
                    q.push(t[x].son[i]);
                }
            }
        }
    }
    
    int son(int p,int x){
        return t[p].son[x];
    }
    
    int fail(int p){
        return t[p].fail;
    }
    
    int len(int p){
        return t[p].len;
    }
    
    int size(){
        return t.size();
    }
};
```

$Two_Sat$

```
#include <bits/stdc++.h>

using namespace std;
using i64=long long;

constexpr i64 INF=numeric_limits<i64>::max()/2;
constexpr int inf=numeric_limits<int>::max()/2;

struct Two_Sat{
    vector<vector<int>> edge;
    vector<bool> vis;
    vector<int> S;
    int cnt,n;

    Two_Sat(){}
    Two_Sat(int _n){
        init(_n);
    }

    void init(int _n){
        n=_n;
        edge.resize(2*n,vector<int>{});
        vis.resize(2*n);
        S.resize(n);
    }

    void addClause(int x,int y){
        edge[x].push_back(y);
    }

    bool satisfiable(){
        auto dfs=[&](auto dfs,int u)->bool{
            if(vis[u^1])
                return false;
            if(vis[u])
                return true;
            vis[u]=true;
            S[cnt++]=u;
            for(auto v:edge[u]){
                if(!dfs(dfs,v))
                    return false;
            }
            return true;
        };

        for(int i=0;i<2*n;i+=2){
            if(!vis[i]&&!vis[i+1]){
                cnt=0;
                if(!dfs(dfs,i)){
                    while(cnt){
                        vis[S[--cnt]]=false;
                    }
                    if(!dfs(dfs,i+1)){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    void answer(){
        for(int i=0;i<n;i++){
            if(vis[2*i]){
                cout<<0<<" ";
            }else{
                cout<<1<<" ";
            }
        }
    }
};
```

$SCC$

```
// #pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>

using namespace std;
using i64=long long;
using u64=unsigned long long;

constexpr i64 INF=numeric_limits<i64>::max()/2;
constexpr int inf=numeric_limits<int>::max()/2;

struct Strongly_Connected_Components{
    vector<vector<int>> edge;
    vector<int> dfn,low,bel;
    vector<int> stk;
    int idx,cnt,n;

    Strongly_Connected_Components(){}
    Strongly_Connected_Components(int _n){
        init(_n);
    }

    void init(int _n){
        n=_n;
        edge.assign(n,{});
        dfn.assign(n,-1);
        low.assign(n,0);
        bel.assign(n,-1);
        stk.clear();
        idx=cnt=0;
    }

    void dfs(int u){
        dfn[u]=low[u]=++idx;
        stk.push_back(u);
        for(auto v:edge[u]){
            if(dfn[v]==-1){
                dfs(v);
                low[u]=min(low[u],low[v]);
            }else if(bel[v]==-1){
                low[u]=min(low[u],dfn[v]);
            }
        }
        if(dfn[u]==low[u]){
            int v;
            do{
                v=stk.back();
                bel[v]=cnt;
                stk.pop_back();
            }while(u!=v);
            cnt++;
        }
    }

    void add(int u,int v){
        edge[u].push_back(v);
    }

    vector<int> work(){
        for(int i=0;i<n;i++){
            if(dfn[i]==-1)
                dfs(i);
        }
        return bel;
    }
};

```

```
// #pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>

using namespace std;
using i64=long long;
using u64=unsigned long long;

constexpr i64 INF=numeric_limits<i64>::max()/2;
constexpr int inf=numeric_limits<int>::max()/2;

struct Strongly_Connected_Components{
    vector<vector<int>> edge,edgerev;
    vector<int> out,bel;
    vector<bool> vis;
    int n,cnt;

    Strongly_Connected_Components(){}
    Strongly_Connected_Components(int _n){
        init(_n);
    }

    void init(int _n){
        n=_n;
        edge.assign(n,{});
        edgerev.assign(n,{});
        out.clear();
        bel.assign(n,-1);
        vis.assign(n,false);
        cnt=0;
    }

    void dfs1(int u){
        vis[u]=true;
        for(auto v:edge[u]){
            if(!vis[v])
                dfs1(v);
        }
        out.push_back(u);
    }

    void dfs2(int u){
        bel[u]=cnt;
        for(auto v:edgerev[u]){
            if(bel[v]==-1)
                dfs2(v);
        }
    }

    void add(int u,int v){
        edge[u].push_back(v);
        edgerev[v].push_back(u);
    }

    vector<int> work(){
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs1(i);
        }
        reverse(out.begin(),out.end());
        for(auto u:out){
            if(bel[u]==-1){
                dfs2(u);
                cnt++;
            }
        }
        return bel;
    }
};
```

$LCA$

```
vector<int> depth(n);
const int log_n=17;
vector<vector<int>> pa(n,vector<int>(log_n,-1));
auto dfs=[&](auto dfs,int u,int fa,int d)->void{
    depth[u]=d;
    pa[u][0]=fa;
    for(int i=1;i<log_n;i++){
        int p=pa[u][i-1];
        if(p!=-1)
            pa[u][i]=pa[p][i-1];
    }
    for(auto v:G[u]){
        if(v==fa){
            continue;
        }
        dfs(dfs,v,u,d+1);
    }

};
dfs(dfs,0,-1,0);

auto lca=[&](int u,int v)->int{
    if(depth[u]<depth[v])
        swap(u,v);
    for(int i=log_n-1;i>=0;i--){
        int p=pa[u][i];
        if(p!=-1&&depth[p]>=depth[v])
            u=p;
    }
    if(u==v)
        return u;
    for(int i=log_n-1;i>=0;i--){
        int pu=pa[u][i];
        int pv=pa[v][i];
        if(pu!=-1&&pv!=-1&&pu!=pv){
            u=pu;
            v=pv;
        }
    }
    return pa[u][0];
};
```

$Dijkstra$

```
struct Dijkstra{
    vector<vector<pair<int,i64>>> edge;
    vector<i64> dis;
    vector<bool> vis;
    int n;

    Dijkstra(){}
    Dijkstra(int _n){
        n=_n;
        init(_n);
    }

    void init(int _n){
        edge.assign(_n,{});
        dis.resize(_n);
        vis.resize(_n);
    }

    void add(int u,int v,i64 w){
        edge[u].push_back({v,w});
    }

    void work(int S){
        dis.assign(n,INF);
        vis.assign(n,false);
        priority_queue<pair<i64,int>,vector<pair<i64,int>>,greater<pair<i64,int>>> q;
        dis[S]=0;
        q.push({0,S});
        while(!q.empty()){
            auto [distance,u]=q.top();
            q.pop();
            if(vis[u])
                continue;
            vis[u]=true;
            for(auto [v,w]:edge[u]){
                if(dis[v]>distance+w){
                    dis[v]=distance+w;
                    q.push({dis[v],v});
                }
            }
        }
    }
};
```

$KMP$

```
#在文本串text中查找模式串pattern，返回所有成功匹配的位置（pattern[0]在text中的下标）
def kmp(text:str,pattern:str)->List[int]:
    n=len(text)
    m=len(pattern)
    text=' '+text
    pattern=' '+pattern
    nxt=[0]*(m+1)
    j=0
    for i in range(2,m+1):
        while j and pattern[i]!=pattern[j+1]:
           j=nxt[j]
        if pattern[i]==pattern[j+1]:
            j+=1
        nxt[i]=j

    pos=[]
    j=0
    for i in range(1,n+1):
        while j and text[i]!=pattern[j+1]:
            j=nxt[j]
        if text[i]==pattern[j+1]:
            j+=1
        if j==m:
            pos.append(i-m)
            j=nxt[j]
    return pos

#字符集为整数
def kmp(text:List[int],pattern:List[int])->List[int]:
    n=len(text)
    m=len(pattern)
    text=[inf]+text
    pattern=[inf]+pattern
    nxt=[0]*(m+1)
    j=0
    for i in range(2,m+1):
        while j and pattern[i]!=pattern[j+1]:
           j=nxt[j]
        if pattern[i]==pattern[j+1]:
            j+=1
        nxt[i]=j

    pos=[]
    j=0
    for i in range(1,n+1):
        while j and text[i]!=pattern[j+1]:
            j=nxt[j]
        if text[i]==pattern[j+1]:
            j+=1
        if j==m:
            pos.append(i-m)
            j=nxt[j]
    return pos
```

$Z_function$

```
# 计算并返回z数组，其中z[i]=|LCP(s[i:], s)|
def z_function(s:str)->List[int]:
    n=len(s)
    z=[0]*n
    box_l=box_r=0
    for i in range(1,n):
        if i<=box_r:
            z[i]=min(z[i-box_l],box_r-i+1)
        while i+z[i]<n and s[z[i]]==s[i+z[i]]:
            box_l,box_r=i,i+z[i]
            z[i]+=1
    z[0]=n
    return z


#返回text中所有成功匹配pattern的位置（pattern[0]在text中的下标）
def match(text:str,pattern:str)->List[int]:
    z=z_function(pattern)
    n=len(text)
    m=len(pattern)
    p=[0]*n
    for i in range(min(n,m)):
        if text[i]==pattern[i]:
            p[0]+=1
        else:
            break
    pos=[]
    if p[0]==m:
        pos.append(0)
    box_l=box_r=0
    for i in range(1,n):
        if i<=box_r:
            p[i]=min(z[i-box_l],box_r-i+1)
        while p[i]<m and i+p[i]<n and pattern[p[i]]==text[i+p[i]]:
            box_l,box_r=i,i+p[i]
            p[i]+=1
        if p[i]==m:
            pos.append(i)
    return pos
```

$Manacher$
```
class Manacher:
    def __init__(self,s:str):
        self.t='#'.join(['^']+list(s)+['$'])
        self.halfLen=[0]*(len(self.t)-1)
        self.halfLen[1]=1
        boxM=boxR=0
        for i in range(2,len(self.halfLen)):
            hl=1
            if i<boxR:
                hl=min(self.halfLen[boxM*2-i],boxR-i)
            while self.t[i-hl]==self.t[i+hl]:
                hl+=1
                boxM,boxR=i,i+hl
            self.halfLen[i]=hl

    #判断 s[l:r+1] 是否是回文串
    def isPalindrome(self,l:int,r:int)->bool:
        return self.halfLen[l+r+2]>r-l+1

    #返回以 s[mid] 为中心的奇数长度回文串个数/最长半径
    def halfLength_mid(self,mid:int)->int:
        return self.halfLen[mid*2+2]//2
    
    #返回以 s[right] 为右中心的偶数长度回文串个数/最长半径
    def halfLength_right(self,right:int)->int:
        return self.halfLen[right*2+1]//2

    #返回以 s[left] 为左中心的偶数长度回文串个数/最长半径
    def halfLength_left(self,left:int)->int:
        return self.halfLen[left*2+3]//2
```

```
struct Manacher{
    string t;
    vector<int> half_len;

    Manacher(){};
    Manacher(string s){
        t="^";
        for(char c:s) {
            t+='#';
            t+=c;
        }
        t+="#$";
        half_len.resize((t.length() - 1));
        half_len[1] = 1;
        int box_m = 0, box_r = 0, max_i = 0;
        for (int i = 2; i < half_len.size(); i++) {
            int hl = 1;
            if (i < box_r) {
                hl = min(half_len[box_m * 2 - i], box_r - i);
            }
            while (t[i - hl] == t[i + hl]) {
                hl++;
                box_m = i;
                box_r = i + hl;
            }
            half_len[i] = hl;
            if (hl > half_len[max_i]) {
                max_i = i;
            }
        }
    }

    //判断 s[l:r+1] 是否是回文串
    bool isPalindrome(int l,int r){
        return half_len[l+r+2]>r-l+1;
    };

    //返回以 s[mid] 为中心的奇数长度回文串个数/最长半径
    int halfLength_mid(int mid){
        return half_len[mid*2+2]/2;
    }
    
    //返回以 s[right] 为右中心的偶数长度回文串个数/最长半径
    int halfLength_right(int right){
        return half_len[right*2+1]/2;
    }

    //返回以 s[left] 为左中心的偶数长度回文串个数/最长半径
    int halfLength_left(int left){
        return half_len[left*2+3]/2;
    }
};
```