class Solution {
public:
    int n,m;
    bool check(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n=grid.size();
        m= grid[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
      
        pq.push({grid[0][0], {0,0}});
        vector<int> row={-1,0,1,0}, col={0,-1,0,1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[0][0]=1;
        while(!pq.empty()){
            auto cord= pq.top().second;
            int maxi=pq.top().first;
            pq.pop();
            if(cord == make_pair(n - 1, m - 1)){
                return maxi;
            }
            for(int k=0;k<4;k++){
                int new_i= cord.first+row[k];
                int new_j= cord.second+col[k];
                if(check(new_i,new_j) && !vis[new_i][new_j]){
                    vis[new_i][new_j]=1;
                    pq.push({max(maxi, grid[new_i][new_j]),{new_i,new_j}});
                }

            }
        }
        return 0;

    }
};
