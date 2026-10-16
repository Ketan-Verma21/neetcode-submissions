class Solution {
public:
    vector<int> par;
    vector<int> rank;
    int findParent(int a){
        if(par[a]==a){
            return a;
        }
        return par[a]=findParent(par[a]);
    }
    bool _union(int a,int b){
        a= findParent(a);
        b=findParent(b);
        if(a!=b){
            if(rank[a]>=rank[b]){
                par[b]=a;
                rank[a]++;
            }
            else{
                par[a]=b;
                rank[b]++;
            }
            return false;
        }
        else{   
            return true;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        par.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
        for(vector<int> it:edges){
            int a= it[0];
            int b=it[1];
            bool ans= _union(a,b);
            if(ans) return it;
        }
        return {};
    }
};
