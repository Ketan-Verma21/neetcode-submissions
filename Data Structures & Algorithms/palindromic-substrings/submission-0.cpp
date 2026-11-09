class Solution {
public:
int left_lim= 0;
        int right_lim;
    bool check(int i, int j){
        return i>=left_lim && j<=right_lim;
    }
    int countSubstrings(string s) {
        int n= s.length();
        int ans=0;
        right_lim=2*n-1;
        string pattern="";
        int j=0;
        int hash_count=0;
        for(int i=0;i<2*n+1;i++){
            if(i%2==0){
                pattern.push_back('#');
                hash_count++;
            }
            else{
                pattern.push_back(s[j]);
                j++;
            }
        }
        // cout<<pattern<<endl;
        for(int i=0;i<2*n+1;i++){
            int left= i;
            int right= i;
            int hash_count=0;
            while(check(left,right) && pattern[left]==pattern[right]){
                if(pattern[left]!='#')ans++;
                left--;
                right++;
            }
            
        }
        return ans;
    }
};
