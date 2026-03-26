#include <bits/stdc++.h>

using namespace std;
using i64=long long;

constexpr i64 inf=numeric_limits<i64>::max();
vector<int> f(1000010,-1);

void dfs(int x){
    vector<int> num;
    int y=x;
    while(y){
        num.push_back(y%10);
        y/=10;
    }
    reverse(num.begin(),num.end());
    for(int i=1,j=num[0];i<num.size();i++){
        if(num[i]==0){
            if(f[j]==0){
                f[x]=1;
                return;
            }
        }else{
            for(int k=0;k<num[i];k++){
                int l=j*10+k;
                for(int m=i+1;m<num.size();m++){
                    l=l*10+num[m];
                }
                if(f[l]==0){
                    f[x]=1;
                    return;
                }
            }
        }
        j=j*10+num[i];
    }
    f[x]=0;
    return;
}

void solve(){
    string s;
    cin>>s;
    if(s[0]=='0'){
        cout<<"Yes\n";
        return;
    }
    int n=0,m=s.size();
    for(int i=0;i<m;i++){
        n=n*10+(s[i]-'0');
    }
    cout<<(f[n]?"Yes":"No")<<"\n";

    return;

}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    for(int i=0;i<10;i++)
        f[i]=1;
    f[1]=0;
    for(int i=10;i<1000000;i++){
        dfs(i);
    }

    int test=1;
    cin>>test;
    while(test--){
        solve();
    }


    return 0;
}
