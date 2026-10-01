class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        queue<pair<int,pair<int,char>>> q;

        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        for(auto it: mp){
            pq.push({it.second,it.first});
        }
        int time=0;
        string ans;
        while(true){
            if(pq.empty() && q.empty()){
                return ans;
            }
            while(!q.empty() && time>= q.front().first){
                pq.push(q.front().second);
                q.pop();
            }
            if(pq.empty()){
                return "";
            }
            pair<int,char> top=pq.top();
            pq.pop();
            ans.push_back(top.second);
            top.first--;
            if(top.first>0){
                q.push({time+2,{top.first,top.second}});
            }
            time++;

        }
        return ans;
    }
};