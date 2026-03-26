template<typename T>
struct SparseTable{
    vector<vector<T>> f_max;
    vector<vector<T>> f_min;
    vector<vector<T>> f_gcd;

    SparseTable(){}
    SparseTable(const vector<T> &v){
        init(v);
    }

    void init(const vector<T> &v){
        int n=v.size(),m=log2(n);
        f_max.assign(n,vector<T>(m+1));
        f_min.assign(n,vector<T>(m+1));
        f_gcd.assign(n,vector<T>(m+1));
        for(int j=0;j<=m;j++){
            for(int i=0;i+(1<<j)-1<n;i++){
                f_max[i][j]=(j!=0?max(f_max[i][j-1],f_max[i+(1<<(j-1))][j-1]):v[i]);
                f_min[i][j]=(j!=0?min(f_min[i][j-1],f_min[i+(1<<(j-1))][j-1]):v[i]);
                f_gcd[i][j]=(j!=0?gcd(f_gcd[i][j-1],f_gcd[i+(1<<(j-1))][j-1]):v[i]);
            }
        }
    }

    T query_max(int l,int r){
        int k=log2(r-l+1);
        return max(f_max[l][k],f_max[r-(1<<k)+1][k]);
    }

    T query_min(int l,int r){
        int k=log2(r-l+1);
        return min(f_min[l][k],f_min[r-(1<<k)+1][k]);
    }

    T query_gcd(int l,int r){
        int k=log2(r-l+1);
        return gcd(f_gcd[l][k],f_gcd[r-(1<<k)+1][k]);
    }
};