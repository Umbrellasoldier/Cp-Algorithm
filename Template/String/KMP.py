#在文本串text中查找模式串pattern，返回所有成功匹配的位置（pattern[0]在text中的下标）
def kmp(text:str,pattern:str)->List[int]:
    n=len(text)
    m=len(pattern)
    text=' '+text
    pattern=' '+pattern
    nxt=[0]*(m+1)
    j=0
    for i in range(2,m+1):
        while j and pattern[i]!=pattern[j+1]:
           j=nxt[j]
        if pattern[i]==pattern[j+1]:
            j+=1
        nxt[i]=j

    pos=[]
    j=0
    for i in range(1,n+1):
        while j and text[i]!=pattern[j+1]:
            j=nxt[j]
        if text[i]==pattern[j+1]:
            j+=1
        if j==m:
            pos.append(i-m)
            j=nxt[j]
    return pos

#字符集为整数
def kmp(text:List[int],pattern:List[int])->List[int]:
    n=len(text)
    m=len(pattern)
    text=[inf]+text
    pattern=[inf]+pattern
    nxt=[0]*(m+1)
    j=0
    for i in range(2,m+1):
        while j and pattern[i]!=pattern[j+1]:
           j=nxt[j]
        if pattern[i]==pattern[j+1]:
            j+=1
        nxt[i]=j

    pos=[]
    j=0
    for i in range(1,n+1):
        while j and text[i]!=pattern[j+1]:
            j=nxt[j]
        if text[i]==pattern[j+1]:
            j+=1
        if j==m:
            pos.append(i-m)
            j=nxt[j]
    return pos