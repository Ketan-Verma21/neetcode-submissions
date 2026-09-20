class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        int mini=1e6;
        pair<int,int> sub_str;
        int s_size= s.length(), t_size=t.length();
        if(t_size>s_size) return ans;
        vector<int> s_array(128,0), t_array(128,0);
        int need=0;
        for(int i=0;i<t_size;i++){
            t_array[t[i]]++;
        }
        for(int i=0;i<128;i++){
            if(t_array[i]) need++;
        }
        int l=0;
        int have=0;
        for(int r=0;r<s_size;r++){
            int c= s[r];
            s_array[c]++;
            if(t_array[c] && s_array[c]==t_array[c]){
                have++;
            }
            while(have==need){
                if((r-l+1)<mini){
                mini=(r-l+1);
                sub_str={l,r};
                }
                int d=s[l];
                s_array[d]--;
                if(t_array[d] && s_array[d]<t_array[d]){
                    have--;
                }
                l++;
            }
            
        }
        return mini == 1e6 ? "" : s.substr(sub_str.first, mini);

    }
};
