class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq2;
        for(int i=0;i<profits.size();i++){
            pq2.push({capital[i],profits[i]});
        }
      
        while(k--){
            while(!pq2.empty() && w>= pq2.top().first){
                pq.push(pq2.top().second);
                pq2.pop();
            }
            if(pq.empty()){
                return w;
            }
            w+=pq.top();
            pq.pop();
        }


        return w;

    }
};