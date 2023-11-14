class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> grid(n, string(n, '.'));
        helper(0, grid, result);
        return result;
    }

private:
    unordered_set<int> cols;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;
    
    void helper(int row, vector<string>& grid, vector<vector<string>>& result){
        
        if(row == grid.size()){
            result.push_back(grid);
            return;
        }

        for(int col=0; col< grid[row].size(); col++){
            if (cols.find(col) != cols.end() ||
            posDiag.find(col+row)!= posDiag.end()||
            negDiag.find(col-row)!= negDiag.end()){
            continue;
            } 

            cols.insert(col);
            posDiag.insert(col+row);
            negDiag.insert(col-row);
            grid[row][col] = 'Q';
            
            helper(row+1, grid, result);

            cols.erase(col);
            posDiag.erase(col+row);
            negDiag.erase(col-row);
            grid[row][col] = '.';
        }
    }

};