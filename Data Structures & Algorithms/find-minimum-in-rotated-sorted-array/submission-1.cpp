class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        int l=0, r=n-1;
        
        int ans=1e6;
        while(l<=r){
            if(nums[l]<nums[r]){
                ans=min(ans,nums[l]);
                break;
            }
            int mid=l+(r-l)/2;
            ans=min(ans,nums[mid]);
            
            if(nums[l]<=nums[mid]){
                l=mid+1;
            }   
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};
