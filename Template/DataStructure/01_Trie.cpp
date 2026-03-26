struct Node{
    Node* son[2]{};
    int cnt=0;
};

struct Trie {
    Node* root=new Node();

    int query(int x){
        Node* cur=root;
        for(int i=30;i>=0;i--){
            int j=(x>>i)&1;
            if(cur->son[j]==nullptr){
                return 0;
            }
            cur=cur->son[j];
        }
        return cur->cnt;
    }

    void insert(int x){
        Node* cur=root;
        cur->cnt++;
        for(int i=30;i>=0;i--){
            int j=(x>>i)&1;
            if(cur->son[j]==nullptr){
                cur->son[j]=new Node();
            }
            cur=cur->son[j];
            cur->cnt++;
        }
    }
};