class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> a(n,0), b(n,0);
        for(int i=0;i<trust.size();i++){
            a[trust[i][0]-1]++;
            b[trust[i][1]-1]++;
        }
        int judge=-1;
        for(int i=0;i<n;i++){
           if(a[i]==0) judge=i+1;
        }
        if(judge!=-1){
            if(b[judge-1]!=n-1){
                judge=-1;
            }
        }
        return judge;
    }
};