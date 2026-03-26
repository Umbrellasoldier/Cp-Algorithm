vector<int> inv;

void get_inv(int n,const int p){
    inv.assign(n+1,0);
    inv[1]=1;
    for(int i=2;i<=n;i++){
        inv[i]=((-(i64)inv[p%i]*(p/i))%p+p)%p;
    }
    return;
}