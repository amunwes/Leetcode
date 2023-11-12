class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int row = 0; row < m; row++){
            for (int col = 0; col < n; col++){
                if(board[row][col] == word[0]){
                    if(helper(board, word, 0, row, col, m, n)){
                        return true;
                    }
                }
            }
        }

        return false;
    }

    private:
        bool helper(vector<vector<char>>& board, string word, int index, int row, int col, int m, int n){
            //base cases
            if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] != word[index]){
                return false;
            }
            if (index == word.size()-1){
                return true;
            }
            // in bounds and matching letter so we x the cell out before traversing further
            board[row][col] = '#';
            if(helper(board, word, index+1, row - 1, col, m, n)  
            || helper(board, word, index+1, row + 1, col, m, n)  
            || helper(board, word, index+1, row, col - 1, m, n)  
            || helper(board, word, index+1, row, col + 1, m, n)){
                return true;
            }
            // if they failed then backtrack and undo
            board[row][col] = word[index];
            return false;
        }
};
