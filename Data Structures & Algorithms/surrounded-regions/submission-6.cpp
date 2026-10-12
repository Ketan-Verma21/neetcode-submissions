class Solution {
public:
    vector<vector<int>> vis;
    int n,m;
    vector<int> row={-1,0,1,0};
    vector<int> col={0,-1,0,1};
    bool check(int i,int j,vector<vector<char>> &board){
        return i<0 || i>=n || j<0 || j>=m || vis[i][j] || board[i][j]=='X';
    }
    bool dfs(int i,int j,vector<vector<char>> &board){
        if(i==0 || j==0 || i==n-1 || j==m-1){
            return true;
        }
        vis[i][j]=1;
        bool ans=false;
        for(int k=0;k<4;k++){
            int new_i=i+row[k];
            int new_j=j+col[k];
            if(!check(new_i,new_j,board)){
                ans= dfs(new_i,new_j,board) || ans;
            }
        }
        return ans;
    }
    void marker(int i,int j ,vector<vector<char>> &board){
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='X'){
            return;
        }
        board[i][j]='X';
        for(int k=0;k<4;k++){
            int new_i=i+row[k];
            int new_j=j+col[k];
            marker(new_i,new_j,board);
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
     
        n=board.size();
        m=board[0].size();
        vis.resize(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
            } if(board[n-1][i]=='O') q.push({n-1,i});
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
            } if(board[i][m-1]=='O') q.push({i,m-1});
        }
        while(!q.empty()){
            pair<int,int> front= q.front();
            q.pop();
            vis[front.first][front.second]=1;
            for(int i=0;i<4;i++){
                int new_i= front.first+ row[i];
                int new_j= front.second+col[i];
                if(!check(new_i,new_j,board)){
                    q.push({new_i,new_j});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(!vis[i][j] && board[i][j]=='O'){
        //             bool ans=dfs(i,j,board);
        //             if(!ans) marker(i,j,board);
        //         }
        //     }
        // }

    }
};
