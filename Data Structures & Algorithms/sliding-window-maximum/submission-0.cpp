class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int maxi=-1e6;
        multiset<int> ms;
        for(int i=0;i<k;i++){
            ms.insert(nums[i]);
        }
        ans.push_back(*ms.rbegin());
        for(int i=k;i<nums.size();i++){
            ms.insert(nums[i]);
            ms.erase(ms.find(nums[i-k]));
            ans.push_back(*ms.rbegin());
        }
        return ans;
    }
};
