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