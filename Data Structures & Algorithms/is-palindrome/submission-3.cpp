class Solution {
public:
    bool isPalindrome(string s) {
        string res;

for (char c : s) {
    if (isalnum(c)) {
        res += tolower(c);
    }
}
    int n=res.length();
    for(int i=0;i<n;i++){
        if(res[i]!=res[n-i-1]){
            return false;
        }
    }
    return true;
    }
};
