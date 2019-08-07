int neposition[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
class Solution {
public:
    void dfs(vector<vector<int>>& image,int row,int col,vector<vector<int>>& book,int sr,int sc,int oldColor,int newColor)
    {
        image[sr][sc]=newColor;
        book[sr][sc]=1;
        for(int k=0;k<4;++k)
        {
            int newsr=sr+neposition[k][0];
            int newsc=sc+neposition[k][1];
            if(newsr>=row||newsr<0||newsc>=col||newsc<0)
                continue;
            
            if(image[newsr][newsc]==oldColor&&book[newsr][newsc]==0)
            {
                dfs(image,row,col,book,newsr,newsc,oldColor,newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.empty())
            return image;
        int row=image.size();
        int col=image[0].size();
        vector<vector<int>> book;
        book.resize(row);
        for(int i=0;i<row;++i)
        {
            book[i].resize(col,0);
        }
        int oldColor=image[sr][sc];
        dfs(image,row,col,book,sr,sc,oldColor,newColor);
        return image;
    }
};