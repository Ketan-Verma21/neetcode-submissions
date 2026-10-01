class Solution {
public:
    pair<int,char> _push(pair<int,char> &top, string &ans, int count){
        if(count==1){
            ans.push_back(top.second);
            top.first-=1;
        }
        else{
            ans.push_back(top.second);
            ans.push_back(top.second);
            top.first-=2;
        }
        return top;
    }
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        queue<pair<int,pair<int,char>>> q;
        if(a)pq.push({a,'a'}); 
        if(b)pq.push({b,'b'}); 
        if(c)pq.push({c,'c'});
        int time=0;
        string ans;
        while(true){
            if(pq.empty() && q.empty()){
                return ans;
            }
            while(!q.empty() && q.front().first<=time){
                pq.push(q.front().second);
                q.pop();
            }
            if(pq.empty()){
                return ans;
            }
            pair<int,char> top=pq.top();
            pq.pop();
            if(top.first>=2){
                if(!q.empty() && top.first < q.front().second.first){
                    top=_push(top,ans,1);
                }
                else{
                    top=_push(top,ans,2);
                }
              
            }
            else{
                top=_push(top,ans,1);
            }
            if(top.first>0){
                q.push({time+2,top});
            }
            time++;
        }
        return ans;
    }
};