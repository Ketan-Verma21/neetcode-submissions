class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        map<int,int> column, row;
        int ans=0;
        for(int i=0;i<picture.size();i++){
            for(int j=0;j<picture[i].size();j++){
                if(picture[i][j]=='B'){
                    column[i]++;
                    row[j]++;
                }
            }
        }
        for(int i=0;i<picture.size();i++){
            for(int j=0;j<picture[i].size();j++){
                if(picture[i][j]=='B'){
                    if(row[j]==1 && column[i]==1){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
