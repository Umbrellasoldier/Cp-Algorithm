class Node:
    __slots__='son','cnt'

    def __init__(self):
        self.son={}
        self.cnt=0

class Trie:
    def __init__(self):
        self.root=Node()

    def insert(self,s:str)->None:
        cur=self.root
        cur.cnt+=1
        for c in s:
            if c not in cur.son:
                cur.son[c]=Node()
            cur=cur.son[c]
            cur.cnt+=1

    def query(self, word: str)->int:
        cur=self.root
        for c in word:
            if c not in cur.son:
                return 0
            cur=cur.son[c]
        return cur.cnt