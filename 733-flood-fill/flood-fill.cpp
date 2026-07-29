class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr ,int sc ,int color , int inic)
    {
        if(sr < 0 || sc < 0 || sr >= image.size()|| sc>=image[0].size()||image[sr][sc]!=inic)
        return ;
        image[sr][sc]=color;
        dfs(image,sr-1,sc,color,inic);
        dfs(image,sr+1,sc,color,inic);
        dfs(image,sr,sc+1,color,inic);
        dfs(image,sr,sc-1,color,inic);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inic=image[sr][sc];
        if(inic==color)
        return image;
        dfs(image,sr,sc,color,inic);
        return image;
    }
};