class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> s;
        int i=n-1;
        while(i>-1){
            if(!s.empty()){
                while(!s.empty() && s.top().first<=temperatures[i] ){
                    s.pop();
                }
                if(!s.empty()){
                    ans[i]=s.top().second-i;
                }
            }
            s.push({temperatures[i],i});
            i--;

        }
        return ans;
    }
};
