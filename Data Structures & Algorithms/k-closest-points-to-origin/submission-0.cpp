class Solution {
public:
    priority_queue<pair<float,vector<int>>> pq;
    int capacity;
    void solve(vector<int> &v){
        float dist= sqrtf(v[0]*v[0]+ v[1]*v[1]);
        if(pq.size()==capacity){
            if(pq.top().first> dist){
                pq.pop();
                pq.push({dist,v});
            }
        }
        else{
            pq.push({dist,v});
        }
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        this->capacity=k;
        for(int i=0;i<points.size();i++){
            solve(points[i]);
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            vector<int> top= pq.top().second;
            ans.push_back(top);
            pq.pop();
        }
        return ans;

    }
};
