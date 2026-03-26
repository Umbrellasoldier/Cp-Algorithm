# 计算并返回z数组，其中z[i]=|LCP(s[i:], s)|
def z_function(s:str)->List[int]:
    n=len(s)
    z=[0]*n
    box_l=box_r=0
    for i in range(1,n):
        if i<=box_r:
            z[i]=min(z[i-box_l],box_r-i+1)
        while i+z[i]<n and s[z[i]]==s[i+z[i]]:
            box_l,box_r=i,i+z[i]
            z[i]+=1
    z[0]=n
    return z


#返回text中所有成功匹配pattern的位置（pattern[0]在text中的下标）
def match(text:str,pattern:str)->List[int]:
    z=z_function(pattern)
    n=len(text)
    m=len(pattern)
    p=[0]*n
    for i in range(min(n,m)):
        if text[i]==pattern[i]:
            p[0]+=1
        else:
            break
    pos=[]
    if p[0]==m:
        pos.append(0)
    box_l=box_r=0
    for i in range(1,n):
        if i<=box_r:
            p[i]=min(z[i-box_l],box_r-i+1)
        while p[i]<m and i+p[i]<n and pattern[p[i]]==text[i+p[i]]:
            box_l,box_r=i,i+p[i]
            p[i]+=1
        if p[i]==m:
            pos.append(i)
    return pos