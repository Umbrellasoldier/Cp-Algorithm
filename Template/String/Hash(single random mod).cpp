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