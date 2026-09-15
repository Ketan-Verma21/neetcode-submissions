class Solution {
public:
    int appendCharacters(string s, string t) {
        int pt=0;
        for(int i=0;i<s.size() && pt<t.size();i++){
            if(s[i]==t[pt]){
                pt++;
            }
        }
        return t.size()-pt;
    }
};