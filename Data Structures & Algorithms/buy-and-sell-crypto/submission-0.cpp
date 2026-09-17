class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
      vector<int> maxi(n+1,-1);
      for(int i=n-1;i>-1;i--){
        maxi[i]=max(maxi[i+1],prices[i]);
      } 
      int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(maxi[i+1]-prices[i]));
        }
        return ans;
    }
};
