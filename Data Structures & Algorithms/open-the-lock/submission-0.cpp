class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target=="0000") return 0;
        queue<pair<string,int>> q;
        set<string> s(deadends.begin(),deadends.end()), vis;
        if(s.find("0000")!=s.end()) return -1;
        q.push({"0000",0});
        vis.insert("0000");
        while(!q.empty()){
            pair<string,int> front= q.front();
            q.pop();
            if(front.first==target) return front.second;
            
            for(int i=0;i<4;i++){
                for(int j:{-1,1}){
                    string new_s= front.first;
                    char c=new_s[i];
                    new_s[i]= (c-'0'+j+10)%10 + '0';
                    if(vis.find(new_s)== vis.end() && s.find(new_s)==s.end()){
                        vis.insert(new_s);
                        q.push({new_s,front.second+1});
                    }
                }
            }
        }
        return -1;

    }
};