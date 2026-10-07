class Solution {
public:
    int avg_len;
    bool solve(int i, vector<int> &nums, vector<int> &temp){
        if(i==nums.size()){
            for(int k=0;k<4;k++){
                if(temp[k]!=avg_len) return false;
            }
            return true;
        }
        bool ans=false;
        for(int j=0;j<4;j++){
            if(temp[j]+nums[i] <= avg_len){
                temp[j]+=nums[i];
                ans= solve(i+1,nums,temp) || ans;
                temp[j]-=nums[i];
            }
        }
        return ans;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(auto it:matchsticks){
            sum+=it;
        }
        if(sum%4!=0){
            return false;
        }
        
        avg_len=sum/4;
        vector<int> temp(4,0);
        return solve(0,matchsticks,temp);
    }
};