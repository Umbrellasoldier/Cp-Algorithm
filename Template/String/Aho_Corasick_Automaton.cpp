struct AhoCorasick{
    static constexpr int ALPHABET=26;
    struct Node{
        int len;
        int fail;
        array<int,ALPHABET> son;
        Node():len{0},fail{0},son{}{}
    };
    
    vector<Node> t;
    
    AhoCorasick(){
        init();
    }
    
    void init(){
        t.assign(2,Node());
        t[0].son.fill(1);
        t[0].len=-1;
    }
    
    int newNode(){
        t.emplace_back();
        return t.size()-1;
    }
    
    int add(const string &a){
        int p=1;
        for(auto c:a){
            int x=c-'a';
            if(t[p].son[x]==0){
                t[p].son[x]=newNode();
                t[t[p].son[x]].len=t[p].len+1;
            }
            p=t[p].son[x];
        }
        return p;
    }
    
    void build(){
        queue<int> q;
        q.push(1);
        
        while(!q.empty()){
            int x=q.front();
            q.pop();
            
            for(int i=0;i<ALPHABET;i++){
                if(t[x].son[i]==0){
                    t[x].son[i]=t[t[x].fail].son[i];
                }else{
                    t[t[x].son[i]].fail=t[t[x].fail].son[i];
                    q.push(t[x].son[i]);
                }
            }
        }
    }
    
    int son(int p,int x){
        return t[p].son[x];
    }
    
    int fail(int p){
        return t[p].fail;
    }
    
    int len(int p){
        return t[p].len;
    }
    
    int size(){
        return t.size();
    }
};