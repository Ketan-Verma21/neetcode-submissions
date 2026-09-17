class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi=-1;
        int n=heights.size();
        int l=0, r=n-1;
        while(l<r){
            int area= min(heights[l],heights[r])*(r-l);
            maxi=max(maxi,area);
            if(heights[l]<=heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxi;
    }
};
