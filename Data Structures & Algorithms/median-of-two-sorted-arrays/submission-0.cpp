class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            swap(nums1,nums2);
        }
        int n=nums1.size();
        int m=nums2.size();
        int total_left= (n+m)/2;
        int l=-1, r=n-1;
        int a_left, a_right, b_left, b_right;
        while(true){
            int i= l+(r-l)/2;
            int j= total_left-i-2;
            a_left= i>=0 ?nums1[i]: INT_MIN;
            a_right=i+1<n ?nums1[i+1]: INT_MAX;
            b_left=j>=0? nums2[j]: INT_MIN;
            b_right=j+1<m ?nums2[j+1]:INT_MAX;
            if(b_left<= a_right && a_left<=b_right){
                if((n+m)%2){
                    return min(a_right, b_right);
                }
                else{
                    return (max(a_left, b_left)+min(a_right, b_right))/(double)2;
                }
            }
            else if(b_left> a_right){
                l=i+1;
            }
            else{
                r=i-1;
            }
        }
        return 0;
    }
};
