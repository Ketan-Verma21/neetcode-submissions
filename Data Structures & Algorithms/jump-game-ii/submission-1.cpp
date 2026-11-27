class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        priority_queue<tuple<int,int>, vector<tuple<int,int>>, greater<tuple<int,int>>>pq;
        pq.push({0,0});
        vector<int> dist(n,1e9);
        dist[0]=0;
        while(!pq.empty()){
            auto [jump, i] = pq.top();
            pq.pop();
            if(jump>dist[i]) continue;
            if(i==n-1) break;
            for(int j=1;j<=nums[i];j++){
                int next= j+i;
                if(next>=n) break;
                if(dist[next]> jump+1){
                    dist[next]=jump+1;
                    pq.push({jump+1,next});
                }
            }
        }
        return dist[n-1];
    }
};
