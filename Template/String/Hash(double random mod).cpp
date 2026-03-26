constexpr int N=100010;

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
const i64 Base=131ll;
const i64 mod1=findprime(rng()%900000000+100000000);
const i64 mod2=findprime(rng()%900000000+100000000);

i64 Hash1[N],Hash2[N];
i64 p1[N],p2[N];


pair<i64,i64> get(int l,int r){
	i64 h1=(Hash1[r]-Hash1[l-1]*p1[r-l+1]%mod1+mod1)%mod1;
	i64 h2=(Hash2[r]-Hash2[l-1]*p2[r-l+1]%mod2+mod2)%mod2;
	return {h1,h2};
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n=10;
    string s=" abcdefghij";

    p1[0]=p2[0]=1;
    for(int i=1;i<=n;i++){
    	p1[i]=p1[i-1]*Base%mod1;
    	p2[i]=p2[i-1]*Base%mod2;
    }

    for(int i=1;i<=n;i++){
    	Hash1[i]=(Hash1[i-1]*Base%mod1+s[i]-'a'+1)%mod1;
    	Hash2[i]=(Hash2[i-1]*Base%mod2+s[i]-'a'+1)%mod2;
    }

    return 0;
}