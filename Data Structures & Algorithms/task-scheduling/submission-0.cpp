class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        map<char,int> mp;
        for(char c:tasks){
            mp[c]++;
        }
        for(auto it:mp){
            pq.push(it.second);
        }
        int time=0;
        while(true){
            if(pq.empty () && q.empty()) break;
            if(!q.empty() && time== q.front().second){
                pq.push(q.front().first);
                q.pop();
            }
            if(pq.empty() && !q.empty() && time!=q.front().second){
                time++;
                continue;
            }
            int top= pq.top();
            time++;
            pq.pop();
            top--;
            if(top>0) q.push({top, time+n});
        }
        return time;
    }
};
