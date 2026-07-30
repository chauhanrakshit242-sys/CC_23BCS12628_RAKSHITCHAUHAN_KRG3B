class Solution {
public:
    void dfs(int i  , int  j , vector<vector<char>>& board,vector<vector<int>>& vis)
    {
        int n = board.size();
        int m = board[0].size();
        vis[i][j]=1;
        if( i-1 >=0 && board[i-1][j]=='O'&& !vis[i-1][j])
        {
            dfs(i-1,j,board,vis);
        }
        if( j-1 >=0 && board[i][j-1]=='O'&& !vis[i][j-1])
        {
            dfs(i,j-1,board,vis);
        }
        if( i+1 < n && board[i+1][j]=='O'&& !vis[i+1][j])
        {
            dfs(i+1,j,board,vis);
        }
        if( j+1 < m && board[i][j+1]=='O'&& !vis[i][j+1])
        {
            dfs(i,j+1,board,vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0 ;i <m;i++)
        {
            if(board[0][i]=='O'&& !vis[0][i])
            {
                dfs(0,i,board,vis);
            }
            if(board[n-1][i]=='O'&& !vis[n-1][i])
            {
                dfs(n-1,i,board,vis);
            }
        }
        for(int i = 0 ;i <n;i++)
        {
            if(board[i][0]=='O'&& !vis[i][0])
            {
                dfs(i,0,board,vis);
            }
            if(board[i][m-1]=='O'&& !vis[i][m-1])
            {
                dfs(i,m-1,board,vis);
            }
        }
        for(int i =0;i < n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(board[i][j]=='O' && vis[i][j]==0)
                {
                    board[i][j]='X';
                }
            }
        }
    }
};