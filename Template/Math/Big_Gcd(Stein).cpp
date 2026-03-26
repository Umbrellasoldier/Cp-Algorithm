// #pragma GCC optimize(3,"Ofast","inline",unroll-loops)
#include <bits/stdc++.h>

using namespace std;
using i64=long long;
using u64=unsigned long long;

constexpr i64 INF=numeric_limits<i64>::max()/2;
constexpr int inf=numeric_limits<int>::max()/2;

i64 stein(i64 a,i64 b){
    if(!a)
        return b;
    if(!b)
        return a;
    if((a&1==0)&&(b&1==0))
        return stein(a/2,b/2);
    if((a&1==0)&&(b&1==1))
        return stein(a/2,b);
    if((a&1==1)&&(b&1==0))
        return stein(a,b/2);
    if(a<=b)
        swap(a,b);
    return stein(b,a-b);
}