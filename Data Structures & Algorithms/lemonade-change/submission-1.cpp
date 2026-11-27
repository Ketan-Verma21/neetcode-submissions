class Solution {
public:
    bool lemonadeChange(vector<int>& bill) {
        int n=bill.size();
        vector<pair<int,int>> mp={{5,0},{10,0},{20,0}};
        map<int,int> gg={{5,0},{10,1},{20,2}};
        for(int i=0;i<n;i++){
            int change= bill[i]-5;
            auto it= mp[gg[bill[i]]];
            mp[gg[bill[i]]]= {it.first,it.second+1};
            for(int j=2;j>-1;j--){
                if(change>=mp[j].first){
                    int a= change/mp[j].first;
                    if(a>mp[j].second){
                        a=mp[j].second;
                    }
                    change-= (a*mp[j].first);
                    mp[j].second-=a;
                }
            }
            if(change!=0) return false;
        }
        return true;

    }
};