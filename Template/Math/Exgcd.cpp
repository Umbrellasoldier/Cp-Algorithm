i64 exgcd(i64 a,i64 b,i64 &x,i64 &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    i64 g=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return g;
}

i64 EXGCD(vector<i64> R,vector<i64> M){
    int n=R.size();
    i64 r1=R[0],m1=M[0];
    for(int i=1;i<n;i++){
        i64 r2=R[i],m2=M[i];
        i64 k1,k2;
        i64 g=exgcd(m1,m2,k1,k2);
        if((r2-r1)%g!=0){
            return -1;
        }
        if(g<0){
            g*=-1,k1*=-1,k2*=-1;
        }
        k1=(__int128)k1*(r2-r1)/g%(m2/g);
        if(k1<0){
            k1+=m2/g;
        }
        r1+=k1*m1,m1=lcm(m1,m2);
    }
    return r1;
}