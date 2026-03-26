struct Node{
    Node* son[62]{};
    int cnt=0;
};

struct Trie {
    Node* root=new Node();

    int query(string s){
        Node* cur=root;
        for(char c:s){
            c-='a';
            if(cur->son[c]==nullptr){
                return 0;
            }
            cur=cur->son[c];
        }
        return cur->cnt;
    }

    void insert(string s){
        Node* cur=root;
        cur->cnt++;
        for(char c:s){
            c-='a';
            if(cur->son[c]==nullptr){
                cur->son[c]=new Node();
            }
            cur=cur->son[c];
            cur->cnt++;
        }
    }
};