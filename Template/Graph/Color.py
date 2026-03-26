class Color:
    def __init__(self,n):
        self.n=n
        self.adj=[[] for i in range(n)]
        self.color=[-1]*n

    def add(self,i,j):
        self.adj[i].append(j)
        self.adj[j].append(i)

    def bfs(self,u,c):
        q=deque()
        q.append([u,c])
        self.color[u]=c
        while q:
            u,c=q.popleft()
            for v in self.adj[u]:
                if self.color[v]==-1:
                    q.append([v,c^1])
                    self.color[v]=c^1
                elif self.color[v]==c:
                    return False
        return True

    def coloring(self):
        for i in range(self.n):
            if self.color[i]==-1:
                if not self.bfs(i,0):
                    return False
        return True