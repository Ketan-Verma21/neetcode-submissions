class Solution {
public:
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool flag=false;
        for(string it:wordList){
            if(it==endWord){
                flag=true;
                break;
            }
        }
        if(!flag) return 0;
        unordered_set<string> s(wordList.begin(),wordList.end());
        unordered_map<string,int> vis_front, vis_back;
        queue<pair<string,int>>q,qb;
        q.push({beginWord,1});
        qb.push({endWord,1});
        int m= beginWord.length();
        vis_front[beginWord]=1;
        vis_back[endWord]=1;
        while(!q.empty() && !qb.empty()){
            if(q.size()>qb.size()){
                swap(q,qb);
                swap(vis_front, vis_back);
            }
            auto front= q.front();
            q.pop();
            for(int i=0;i<m;i++){
                string new_str=front.first;
                for(char c='a';c<='z';c++){
                    if(c!=new_str[i]){
                        new_str[i]=c;
                        if(s.find(new_str)==s.end()) continue;
                        if(vis_back.find(new_str)!=vis_back.end()){
                            return vis_front[front.first]+vis_back[new_str];
                        }
                        if(vis_front.find(new_str)==vis_front.end()){
                            vis_front[new_str]=vis_front[front.first]+1;
                            q.push({new_str,0});
                        }

                    }
                    
                }
            }
           
        }
        return 0;

    }
};
