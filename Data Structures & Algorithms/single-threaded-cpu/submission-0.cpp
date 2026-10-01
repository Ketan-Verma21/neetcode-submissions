class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq2;
        for(int i=0;i<tasks.size();i++){
            pq.push({tasks[i][0],{tasks[i][1],i}});
        }
        vector<int> ans;
        int time=0;
        while(true){
            if(pq.empty() && pq2.empty()){
                return ans;
            }
            while(!pq.empty() && pq.top().first <= time){
                pair<int,int> top= pq.top().second;
                pq2.push(top);
                pq.pop();
            }
            if(pq2.empty()){
                time++;
            }
            else{
                
                    pair<int,int> top= pq2.top();
                    pq2.pop();
                    ans.push_back(top.second);
                   time+=top.first;
                
            }

        }
        return ans;

    }
};