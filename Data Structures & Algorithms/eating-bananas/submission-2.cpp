class Solution {
public:
    bool solve(int mid, vector<int> &piles, int n, int h){
        long long cnt=0;
        for(int i=0;i<n;i++){
            cnt+= (piles[i] + mid - 1LL)/mid;
        }
        return cnt<=h;

    }    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=-1, mini=INT_MAX;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
            mini=min(mini,piles[i]);
        }
        int l=1;
        int r=maxi;
        int ans=0;
        while(l<=r){
            int mid= l+(r-l)/2;
            if(solve(mid,piles,n,h)){                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;

    }
};
