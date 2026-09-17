class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(10,vector<int>(10,0)),column(10,vector<int>(10,0));
        map<pair<int,int>,vector<int>> square;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                vector<int> gg(10,0);
                square[{i,j}]=gg;
            }
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char numm=board[i][j];
                if(numm!='.'){
                    int num=numm-'0'; 
                    if(row[j][num]!=1 && column[i][num]!=1 && square[{i/3,j/3}][num]!=1){
                        row[j][num]=1;
                        column[i][num]=1;
                        square[{i/3,j/3}][num]=1;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
