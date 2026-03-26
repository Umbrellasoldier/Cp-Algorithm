constexpr int N=200010;

struct BigInt {
    int a[N],Base=10;
    BigInt(int x=0):a{}{
        for(int i=0;x;i++){
            a[i]=x%Base;
            x/=Base;
        }
    }
    BigInt &operator*=(int x){
        for(int i=0;i<N;i++){
            a[i]*=x;
        }
        for(int i=0;i<N-1;i++){
            a[i+1]+=a[i]/Base;
            a[i]%=Base;
        }
        return *this;
    }
    BigInt &operator/=(int x){
        for(int i=N-1;i>=0;i--){
            if(i){
                a[i-1]+=a[i]%x*Base;
            }
            a[i]/=x;
        }
        return *this;
    }
    BigInt &operator+=(const BigInt &x){
        for(int i=0;i<N;i++){
            a[i]+=x.a[i];
            if(a[i]>=Base){
                a[i+1]+=a[i]/Base;
                a[i]%=Base;
            }
        }
        return *this;
    }
};

ostream &operator<<(ostream &o, const BigInt &a){
    int t=N-1;
    while(a.a[t]==0){
        t--;
    }
    for(int i=t;i>=0;i--){
        o<<a.a[i];
    }
    return o;
}