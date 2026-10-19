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
        set<string> s;
        for(string it: wordList){
            s.insert(it);
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        int m= beginWord.length();
        while(!q.empty()){
            pair<string,int> front=q.front();
            q.pop();
            if(front.first==endWord){
                return front.second;
            }
            for(int i=0;i<m;i++){
                string new_str=front.first;
                for(char c='a';c<='z';c++){
                    if(c!=new_str[i])new_str[i]=c;
                    auto find=s.find(new_str);
                    if(find!=s.end()){
                        s.erase(find);
                        q.push({new_str,front.second+1});
                    }
                }
            }
           
        }
        return 0;

    }
};
