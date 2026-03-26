template<typename T>
struct Info {
    T value;

    Info():value(T{}){}
    Info(T val):value(val){}

    Info &operator+=(const Info &other){
        value+=other.value;
        return *this;
    }
};

template<typename T>
struct Fenwick{
    vector<Info<T>> fenwick;
    int N;

    Fenwick(){}
    Fenwick(int n){
        init(n);
    }

    void init(int n){
        N=1<<(int(log2(n))+1);
        fenwick.assign(N,Info<T>{});
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
        Info<T> res{};
        while(x){
            res+=fenwick[x];
            x-=lowbit(x);
        }
        return res;
    }
};
