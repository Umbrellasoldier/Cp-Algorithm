class Manacher:
    def __init__(self,s:str):
        self.t='#'.join(['^']+list(s)+['$'])
        self.halfLen=[0]*(len(self.t)-1)
        self.halfLen[1]=1
        boxM=boxR=0
        for i in range(2,len(self.halfLen)):
            hl=1
            if i<boxR:
                hl=min(self.halfLen[boxM*2-i],boxR-i)
            while self.t[i-hl]==self.t[i+hl]:
                hl+=1
                boxM,boxR=i,i+hl
            self.halfLen[i]=hl

    #判断 s[l:r+1] 是否是回文串
    def isPalindrome(self,l:int,r:int)->bool:
        return self.halfLen[l+r+2]>r-l+1

    #返回以 s[mid] 为中心的奇数长度回文串个数/最长半径
    def halfLength_mid(self,mid:int)->int:
        return self.halfLen[mid*2+2]//2
    
    #返回以 s[right] 为右中心的偶数长度回文串个数/最长半径
    def halfLength_right(self,right:int)->int:
        return self.halfLen[right*2+1]//2

    #返回以 s[left] 为左中心的偶数长度回文串个数/最长半径
    def halfLength_left(self,left:int)->int:
        return self.halfLen[left*2+3]//2