class Solution {
public:
    void dfsMark(vector<vector<char>>& grid,int x, int y)
    {
        if(x<0 || x>=grid.size() || y<0 || y>=grid[x].size()) return; // 越界返回
        if(grid[x][y] == '0') return; // 水面返回
        grid[x][y] = '0';
        dfsMark(grid,x-1,y); // 全部覆盖为水
        dfsMark(grid,x+1,y);
        dfsMark(grid,x,y-1);
        dfsMark(grid,x,y+1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int nAns = 0;
        for(int i=0; i<grid.size(); ++i)
        {
            for(int j=0; j<grid[i].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    ++nAns;
                    dfsMark(grid,i,j);
                }
            }
        }
        return nAns;
    }
};