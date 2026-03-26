// 高精度大小比较
bool cmp(vector<int> &A,vector<int> &B){
    if(A.size()!=B.size())
        return A.size()>B.size();
    for(int i=A.size()-1;i>=0;i--)
        if(A[i]!=B[i])
            return A[i]>B[i];
    return true;
}

// 高精度+高精度
vector<int> add(vector<int> &A,vector<int> &B){
    if(A.size()<B.size())
        return add(B,A);
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size();i++){
        t+=A[i];
        if(i<B.size())
            t+=B[i];
        C.push_back(t%10);
        t/=10;
    }
    if(t)
        C.push_back(t);
    return C;
}

// 高精度-高精度
vector<int> sub(vector<int> &A,vector<int> &B){
    vector<int> C;
    for(int i=0,t=0;i<A.size();i++){
        t=A[i]-t;
        if(i<B.size())
            t-=B[i];
        C.push_back((t+10)%10);
        if(t<0)
            t=1;
        else
            t=0;
    }
    while(C.size()>1&&C.back()==0)
        C.pop_back();
    return C;
}

// 高精度×低精度
vector<int> mul(vector<int> &A,int b){
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size()||t;i++){
        if(i<A.size())
            t+=A[i]*b;
        C.push_back(t%10);
        t/=10;
    }
    while(C.size()>1&&C.back()==0)
        C.pop_back();
    return C;
}

// 高精度×高精度
vector<int> mul(vector<int> &A,vector<int> &B){
    vector<int> C(A.size()+B.size());
    for(int i=0;i<A.size();i++)
        for(int j=0;j<B.size();j++)
            C[i+j]+=A[i]*B[j];
    for(int i=0,t=0;i<C.size()||t;i++){
        t+=C[i];
        if(i>=C.size())
            C.push_back(t%10);
        else C[i]=t%10;
        t/=10;
    }
    while(C.size()>1&&C.back()==0)
        C.pop_back();
    return C;
}

// 高精度/低精度->商和余数
vector<int> div(vector<int> &A,int b,int &r){
    vector<int> C;
    r=0;
    for(int i=A.size()-1;i>=0;i--){
        r=r*10+A[i];
        C.push_back(r/b);
        r%=b;
    }
    reverse(C.begin(),C.end());
    while(C.size()>1&&C.back()==0)
        C.pop_back();
    return C;
}

// 高精度/高精度->商和余数
vector<int> div(vector<int> &A,vector<int> &B,vector<int> &r){
    vector<int> C;
    if(!cmp(A,B)){
        C.push_back(0);
        r=A;
        return C;
    }
    int t=0;
    vector<int> temp;
    for(int i=A.size()-1;i>=0;i--){
        temp.push_back(A[i]);
        reverse(temp.begin(),temp.end());
        while(temp.size()>1&&temp.back()==0) temp.pop_back();
        while(cmp(temp,B)){
            temp=sub(temp,B);
            t++;
        }
        reverse(temp.begin(),temp.end());
        C.push_back(t);
        t=0;
    }
    reverse(temp.begin(),temp.end());
    r=temp;
    reverse(C.begin(),C.end());
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}