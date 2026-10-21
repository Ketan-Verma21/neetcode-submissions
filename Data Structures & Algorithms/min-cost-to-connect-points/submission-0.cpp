class DSU{
    private:
    vector<int> par, rank;
    int findParent(int x){
        if(par[x]==x) return x;
        return par[x]=findParent(par[x]);
    }
    public:
    DSU(int n): par(n), rank(n){
        ans=0;
        for(int i=0;i<n;i++){
            par[i]=i;
        }

    }
    int ans;
    void _union(int i, int j,int dist){
        i=findParent(i);
        j=findParent(j);
        if(i!=j){
            ans+=dist;
            if(rank[i]>=rank[j]){
                par[j]=i;
                rank[i]++;
            }
            else{
                par[i]=j;
                rank[j]++;
            }
        }
    }
    

};
class Solution {
public:
    
    int minCostConnectPoints(vector<vector<int>>& points) {
    
        vector<vector<int>> edges;
        int n= points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist= abs(points[i][0]- points[j][0])+abs(points[i][1]- points[j][1]);
                edges.push_back({dist,i,j});
            }
        }
        DSU ds(n);
        sort(edges.begin(), edges.end());
        for(vector<int> it:edges){
            int dist = it[0];
            int i= it[1];
            int j= it[2];
            ds._union(i,j,dist);
        }
        return ds.ans;


    }
};
