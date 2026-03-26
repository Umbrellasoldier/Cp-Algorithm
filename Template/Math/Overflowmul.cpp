i64 overflowmul(u64 a,u64 b,u64 p){
    a%=p,b%=p;
    u64 c=(long double)a*b/p;
    u64 x=a*b,y=c*p;
    i64 ans=((i64)(x%p)-(i64)(y%p)+p)%p;
    return ans;
}