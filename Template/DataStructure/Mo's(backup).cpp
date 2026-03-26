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