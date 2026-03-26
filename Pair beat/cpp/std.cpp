/*
    对于一个数，我们有两种操作：
       ①：改变它的任意一位，使改变后的数小于原数（eg：0，1，2，... ,x）
       ②：删取任意位置的零，以及它右边的所有数
    问：两个人轮流玩，第一个人能不能把这个数删完?
    思路：由于两个人每次都是最优的，且每个人都可以改变任意一个位置的数，
          因此，必胜态和必败态是轮流的。因此我们可以枚举所有必败态，改变它
          的某一位使之成为必胜态。
*/
#include<bits/stdc++.h>
using namespace std;
int book[1000010];
int len(int x)
{
    int ans=0;
    while(x)
    {
        ans++;
        x/=10;
    }
    return ans;
}
void work(int x)
{
    int l=len(x);//求这个数的长度
    for(int i=l; i>=1; i--)//改变每一位的数
    {
        int y=x;
        int pos=1;
        for(int j=1; j<i; j++)//改变第 i 位上的数，因此求pos，用于下面只改变这一位的数
            pos*=10;
        int tmp=(x%(pos*10))/pos;//取x的第 i 位上的数
        for(int j=tmp; j<9; j++)//这个[tmp,9]
        {
            y=y+pos;//只有一位改变
            book[y]=1;//标记必胜态
        }
    }
    if(l!=6)//长度不足6位  后面补零
    {
        int y=x;
        int pos=1;
        for(int i=l; i<6; i++)
        {
            y=y*10;
            for(int j=0; j<pos; j++)//枚举后面的每一个数
                book[y+j]=1;
            pos*=10;
        }
    }
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
    cout<<(book[n]?"Yes":"No")<<"\n";

    return;

}
int main()
{
    book[0]=1;//0为必胜态
    for(int i=1; i<1000000; i++)//枚举1百万之内的所有数
        if(!book[i])//必败态
            work(i);
    int test=1;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}