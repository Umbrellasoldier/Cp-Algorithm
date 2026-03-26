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