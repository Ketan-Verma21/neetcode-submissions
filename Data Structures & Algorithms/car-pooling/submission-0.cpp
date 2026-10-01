class Solution {
public:
    bool comp(vector<vector<int>>& a, vector<vector<int>>& b){
        return a[1]<b[1];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // sort(trips.begin(),trips.end(),comp);

        map<int,int> enter, exit;
        int maxi=-1e9; int mini= 1e9;
        for(int i=0;i<trips.size();i++){
            maxi=max(maxi,trips[i][2]);
            mini=min(mini,trips[i][1]);
            enter[trips[i][1]]+=trips[i][0];
            exit[trips[i][2]]+=trips[i][0];
        }
        int time=mini;
        int pass=0;
        while(time<=maxi){
            pass+=(enter[time]-exit[time]);
            if(pass>capacity) return false;
            time++;
        }
        return pass==0;
    }
};