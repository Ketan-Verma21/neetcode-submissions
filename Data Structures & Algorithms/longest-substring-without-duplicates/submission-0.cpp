class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        map<char,int> mp;
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            while(mp[s[i]]>1){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,i-l+1);

        }
        return ans;
    }
};
