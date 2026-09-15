class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
      map<string,string> num_gen;
      map<string,vector<string>> rev_num;
      vector<vector<string>> ans;
      char a,b;
      for(int i=0;i<strings.size();i++){
        string key="0";
        for(int j=0;j<strings[i].size()-1;j++){
            a=strings[i][j];
            b=strings[i][j+1];
            key+=('a'+((b-a)+26)%26);
        }
        rev_num[key].push_back(strings[i]);
      }
      for(auto it: rev_num){
        ans.push_back(it.second);
      }
      return ans;

    }
};
