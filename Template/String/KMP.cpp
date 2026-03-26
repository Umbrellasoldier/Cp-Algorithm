// 在文本串 text 中查找模式串 pattern，返回所有成功匹配的位置（pattern[0] 在 text 中的下标）
vector<int> kmp(string text,string pattern) {
    int n=text.size();
    int m=pattern.size();
    text=" "+text;
    pattern=" "+pattern;
    vector<int> nxt(m+1);
    for(int i=2,j=0;i<=m;i++){
        while(j&&pattern[i]!=pattern[j+1]){
            j=nxt[j];
        }
        if(pattern[i]==pattern[j+1]){
            j++;
        }
        nxt[i]=j;
    }

    vector<int> pos;
    for(int i=1,j=0;i<=n;i++){
        while(j&&text[i]!=pattern[j+1]){
            j=nxt[j];
        }
        if(text[i]==pattern[j+1]){
            j++;
        }
        if(j==m) {
            pos.push_back(i-m);
            j=nxt[j];
        }
    }
    return pos;
}