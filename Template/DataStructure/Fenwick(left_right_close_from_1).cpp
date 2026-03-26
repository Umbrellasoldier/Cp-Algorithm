template<typename T>
struct Fenwick{
    vector<T> fenwick;
    int N;

    Fenwick(){}
    Fenwick(int n=0){
        init(n);
    }

    void init(int n){
        N=1<<(int(log2(n))+1);
        fenwick.assign(N,T{});
    }

    int lowbit(int x){
        return x&-x;
    }

    void add(int x,const T &k){
        while(x<N){
            fenwick[x]+=k;
            x+=lowbit(x);
        }
    }

    T sum(int x){
        T res{};
        while(x){
            res+=fenwick[x];
            x-=lowbit(x);
        }
        return res;
    }

    T range(int l,int r){
        T res=sum(r)-sum(l-1);
        return res;
    }
};