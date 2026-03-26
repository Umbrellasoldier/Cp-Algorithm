class Fenwick:
    def __init__(self,n:int):
        self.fenwick=[0]*(n+1)  # 使用下标 1 到 n

    # a[i] 增加 val
    # 1 <= i <= n
    # 时间复杂度 O(log n)
    def add(self,i:int,val:int)->None:
        t=self.fenwick
        while i<len(t):
            t[i]+=val
            i+=i&-i

    # 计算前缀和 a[1]+...+a[i]
    # 1 <= i <= n
    # 时间复杂度 O(log n)
    def sum(self,i:int)->int:
        t=self.fenwick
        res=0
        while i>0:
            res+=t[i]
            i&=i-1
        return res

    # 计算区间和 a[l]+...+a[r]
    # 1 <= l <= r <= n
    # 时间复杂度 O(log n)
    def query(self,l:int,r:int)->int:
        if r<l:
            return 0
        return self.sum(r)-self.sum(l-1)