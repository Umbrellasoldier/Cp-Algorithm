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