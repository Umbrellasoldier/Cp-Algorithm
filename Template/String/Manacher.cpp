struct Manacher{
    string t;
    vector<int> half_len;

    Manacher(){};
    Manacher(string s){
        t="^";
        for(char c:s) {
            t+='#';
            t+=c;
        }
        t+="#$";
        half_len.resize((t.length() - 1));
        half_len[1] = 1;
        int box_m = 0, box_r = 0, max_i = 0;
        for (int i = 2; i < half_len.size(); i++) {
            int hl = 1;
            if (i < box_r) {
                hl = min(half_len[box_m * 2 - i], box_r - i);
            }
            while (t[i - hl] == t[i + hl]) {
                hl++;
                box_m = i;
                box_r = i + hl;
            }
            half_len[i] = hl;
            if (hl > half_len[max_i]) {
                max_i = i;
            }
        }
    }

    //判断 s[l:r+1] 是否是回文串
    bool isPalindrome(int l,int r){
        return half_len[l+r+2]>r-l+1;
    };

    //返回以 s[mid] 为中心的奇数长度回文串个数/最长半径
    int halfLength_mid(int mid){
        return half_len[mid*2+2]/2;
    }
    
    //返回以 s[right] 为右中心的偶数长度回文串个数/最长半径
    int halfLength_right(int right){
        return half_len[right*2+1]/2;
    }

    //返回以 s[left] 为左中心的偶数长度回文串个数/最长半径
    int halfLength_left(int left){
        return half_len[left*2+3]/2;
    }
};