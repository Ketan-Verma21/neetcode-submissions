class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& sp) {
        vector<pair<int,int>> gg;
        int n=sp.size();
        for(int i=0;i<n;i++){
            gg.push_back({pos[i],sp[i]});
        }
        sort(gg.begin(),gg.end());
        stack<float> s;
        for(int i=n-1;i>-1;i--){
            s.push(((float)(target-gg[i].first))/gg[i].second);
            if(s.size()>=2){
                float top= s.top();
                s.pop();
                if(top>s.top()){
                    s.push(top);
                }
            }
        }
        return s.size();

    }
};
