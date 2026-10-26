class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n,INT_MAX);
        cost[src]=0;
        for(int i=0;i<=k;i++){
            vector<int> temp=cost;
            for(auto it:flights){
                int a= it[0];
                int b= it[1];
                int cst= it[2];
                if(cost[a]!= INT_MAX)temp[b]= min(temp[b], cost[a]+cst);
            }
            cost=temp;
        }
        return cost[dst]== INT_MAX ? -1 : cost[dst];
    }
};