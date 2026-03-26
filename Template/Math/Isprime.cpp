bool is_prime(i64 n){
    for(int i=2;i<=n/i;i++){
        if(n%i==0){
            return false;
        }
    }
    return n>=2;
}