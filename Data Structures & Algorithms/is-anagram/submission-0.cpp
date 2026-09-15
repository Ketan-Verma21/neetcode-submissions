class Solution {
public:
    bool isAnagram(string s, string t) {
      vector<int> mp1(26,0),mp2(26,0);
      int temp;
      for(int i=0;i<s.size();i++){
        mp1[s[i]-'a']++;
      }
      for(int i=0;i<t.size();i++){
        mp2[t[i]-'a']++;
      }
      for(int i=0;i<26;i++){
        if(mp1[i]!=mp2[i]){
            return false;
        }
      }
      return true;
    }
};
