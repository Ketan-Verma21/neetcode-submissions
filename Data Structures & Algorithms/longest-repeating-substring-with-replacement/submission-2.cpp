class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> mp;
        int n=s.length();
        int ans=0;
        int l=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            maxi=max(mp[s[i]],maxi);
            while(((i-l+1)-maxi)>k){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,i-l+1);

        }
        return ans;
    }
};
