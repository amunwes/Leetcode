class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == '1'){
                    count++;
                    sinkIsland(grid, i, j);
                }
            }
        }
        
        return count;
    }
private:
    void sinkIsland(vector<vector<char>>& grid, int i, int j){
        if(i >= grid.size() || j >= grid[i].size() || j < 0 || i < 0 || grid[i][j] == '0'){
            return;
        }
        
        
        grid[i][j] = '0';
        sinkIsland(grid, i+1, j);
        sinkIsland(grid, i-1, j);
        sinkIsland(grid, i, j+1);
        sinkIsland(grid, i, j-1);        


        return;

    }
};