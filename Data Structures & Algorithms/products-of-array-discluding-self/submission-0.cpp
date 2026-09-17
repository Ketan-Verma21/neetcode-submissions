class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size()), post(nums.size());
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]*nums[i];
        }
        post[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>-1;i--){
            post[i]=post[i+1]*nums[i];
        }
        vector<int> ans(nums.size());
        ans[0]=post[1];
        ans[nums.size()-1]=pre[nums.size()-2];
        for(int i=1;i<nums.size()-1;i++){
            ans[i]=pre[i-1]*post[i+1];
        }
        return ans;

    }
};
