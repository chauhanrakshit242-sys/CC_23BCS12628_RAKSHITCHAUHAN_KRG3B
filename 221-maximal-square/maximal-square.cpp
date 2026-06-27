class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi =0;
        vector<int>curr(col+1,0);
        vector<int>next(col+1,0);
        for(int i = row -1;i>=0;i--)
        {
            for(int j =col -1;j>=0;j--)
            {
                if(matrix[i][j]=='1')
                {
                   curr[j]= 1 + min(curr[j+1],min(next[j+1],next[j]));
                   maxi = max(maxi ,curr[j]);
                }
                else
                {
                curr[j]=0;
                }
            }
            next=curr;
        }
        return maxi*maxi;
    }
};