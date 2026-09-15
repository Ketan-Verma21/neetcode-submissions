class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pt1=0;
        for(int i=0;i<t.size() && pt1<s.size();i++){
            if(s[pt1]==t[i]){
                pt1++;
            }
        }
        if(pt1!=s.size()) return false;
        return true;
    }
};