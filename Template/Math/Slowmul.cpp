i64 slowmul(i64 a,i64 b,i64 p){
    i64 res=0;
    while(b){
        if(b&1){
            res=(res+a)%p;
        }
        a=a*2%p;
        b>>=1;
    }
    return res;
}