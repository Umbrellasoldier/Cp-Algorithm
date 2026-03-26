class SparseTable:
    def __init__(self,arr):
        n=len(arr)
        self.LOG2=[-1]*(n+1)
        for i in range(1,n+1):
            self.LOG2[i]=self.LOG2[i>>1]+1
        N=int(log2(n))+1

        self.f_max=[[0]*N for i in range(n)]
        for j in range(N):
            i=0
            while i+(1<<j)-1<n:
                if not j:
                    self.f_max[i][j]=arr[i]
                else:
                    if self.f_max[i][j-1]>=self.f_max[i+(1<<j-1)][j-1]:
                        self.f_max[i][j]=self.f_max[i][j-1]
                    else:
                        self.f_max[i][j]=self.f_max[i+(1<<j-1)][j-1]
                i+=1

        # self.f_min=[[0]*N for i in range(n)]
        # for j in range(N):
        #     i=0
        #     while i+(1<<j)-1<n:
        #         if not j:
        #             self.f_min[i][j]=arr[i]
        #         else:
        #             if self.f_min[i][j-1]<=self.f_min[i+(1<<j-1)][j-1]:
        #                 self.f_min[i][j]=self.f_min[i][j-1]
        #             else:
        #                 self.f_min[i][j]=self.f_min[i+(1<<j-1)][j-1]
        #         i+=1

        # self.f_gcd=[[0]*N for i in range(n)]
        # for j in range(N):
        #     i=0
        #     while i+(1<<j)-1<n:
        #         if not j:
        #             self.f_gcd[i][j]=arr[i]
        #         else:
        #             self.f_gcd[i][j]=gcd(self.f_gcd[i][j-1],self.f_gcd[i+(1<<j-1)][j-1])
        #         i+=1

    def query_max(self,l,r):
        k=self.LOG2[r-l+1]
        if self.f_max[l][k]>=self.f_max[r-(1<<k)+1][k]:
            x=self.f_max[l][k]
        else:
            x=self.f_max[r-(1<<k)+1][k]
        return x

    # def query_min(self,l,r):
    #     k=self.LOG2[r-l+1]
    #     if self.f_min[l][k]<=self.f_min[r-(1<<k)+1][k]:
    #         x=self.f_min[l][k]
    #     else:
    #         x=self.f_min[r-(1<<k)+1][k]
    #     return x

    # def query_gcd(self,l,r):
    #     k=self.LOG2[r-l+1]
    #     x=gcd(self.f_gcd[l][k],self.f_gcd[r-(1<<k)+1][k])
    #     return x