class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int size = 9;
        
        for (auto i : board){
            if (i.size() != board.size() ){
                cout << "invalid sudoku, the grid is not 9x9";
                return false;
            }
        }
        bool row[size][size] = {false};
        bool col[size][size] = {false};
        bool box[size][size] = {false};       
        // initialize our 9x9 arrays to false, each of the 9 values have not been seen in any section.
        
        // iterates through the coordinates of the sudoku
        for (int r = 0; r < size; r++){
            for (int c = 0; c < size; c++ ){
                if (board[r][c] == '.')
                    continue; //if empty, skip to next loop

                //convert the board character into int index, '1' becomes 0
                int val = board[r][c] - '0' - 1;
                // figure out what section were in based on the rows and columns then make the index.
                int section = r/3 *3 + c/3;
                
                // check if any of our maps have been hit already for the current number were looking at.
                if (row[r][val] || col[c][val] || box[section][val])
                    return false;
                else{ // set the maps to have seen the value 
                    row[r][val] = true;
                    col[c][val] = true;
                    box[section][val] = true;
                }

            }
        }
        // if we got past all the elements without returning false it must be a valid sudoku
        return true;

    }
};