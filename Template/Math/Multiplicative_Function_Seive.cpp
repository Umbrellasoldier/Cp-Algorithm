constexpr int N=1E7;

bool isprime[N+1];
int f[N+1];
int cnt[N+1];
int primes[N+1];
int tot=0;

int calc_f(int p,int c){
    return c+1;
}

void get_f(){
    fill(isprime+2,isprime+N+1,true);
    f[1]=1;
    for(int i=2;i<=N;i++){
        if(isprime[i]){
            primes[++tot]=i;
            f[i]=calc_f(i,1);
            cnt[i]=1;
        }
        for(int j=1;j<tot;j++){
            int p=primes[j];
            if(i*p>N){
                break;
            }
            isprime[i*p]=false;
            if(i%p==0){
                cnt[i*p]=cnt[i]+1;
                f[i*p]=f[i]/calc_f(p,cnt[i])*calc_f(p,cnt[i]+1);
                break;
            }
            cnt[i*p]=1;
            f[i*p]=f[i]*calc_f(p,1);
        }
    }
}