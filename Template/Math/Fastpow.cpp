i64 fastpow(i64 a,int b,int p) {
    i64 res=1%p;
    while(b){
        if(b&1){
            res=res*a%p;
        }
        a=a*a%p;
        b>>=1;
    }
    return res;
}