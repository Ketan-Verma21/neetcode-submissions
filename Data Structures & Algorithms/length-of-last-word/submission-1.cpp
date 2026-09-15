class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        bool gg=false;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                ans++;
                gg=true;
            }
            else{
                if(gg){
                    return ans;
                }
            }
        }
        return ans;

    }
};