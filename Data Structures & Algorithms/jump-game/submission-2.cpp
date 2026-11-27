class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n= nums.size();
        if(nums[0]==0 && n>1) return false;
        if(n==1) return true;
        int i=0;
        while(i<n-1){
            int a= nums[i];
            if(i+a >=n-1){
                return true;
            }
            int c= nums[i+a];
            if(c==0){
                int x=1;
                int j=i+a-1;
                while(j>-1 && nums[j]<=x){
                    j--;
                    x++;
                }
                if(j<0) return 0;
                else {
                    i=j;
                }
            }else{
                i=i+a;
            }
        }
        return true;
    }
};
