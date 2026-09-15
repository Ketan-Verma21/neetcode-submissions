class Solution {
public:
    int shortestWay(string source, string target) {
        int i=0,j=0;
        int cnt=1;
        map<char,int> mp1,mp2;
        for(int i=0;i<source.length();i++){
            mp1[source[i]]=1;
        }
        for(int i=0;i<target.length();i++){
            mp2[target[i]]=1;
        }
        for(auto it:mp2){
            if(mp1[it.first]!=1){
                return -1;
            }
        }
        while(j<target.length()){
            if(i==source.length()){
                        cnt++;
                        i=0;
            }
            if(source[i]==target[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return cnt;
    }
};
