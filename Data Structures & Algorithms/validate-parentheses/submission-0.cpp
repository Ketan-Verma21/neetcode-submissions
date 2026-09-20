class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
        int i=0;
        map<char,char> opp;
        opp[']']='[';
        opp['}']='{';
        opp[')']='(';
        while(i<s.length()){
            if(ss.empty()){
                ss.push(s[i]);             
            }
            else
            {
                if(s[i]=='(' || s[i]=='['|| s[i]=='{' ){
                    ss.push(s[i]);
                }
                else{
                    if(ss.top()==opp[s[i]]){
                        ss.pop();
                       
                    }
                    else{
                        return false;
                    }
                }

            }
            i++;
        }
        if(ss.empty()) return true;
        return false;
    }
};
