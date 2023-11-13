class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() -1;
        int n = matrix[0].size() -1;

        int lowrow = 0;
        int highrow = m;
        int correctrow;
        // cheeky out of bounds check before starting to save iterations if the input isnt even valid
        if(target > matrix[m][n] || target < matrix[0][0]){
            return false;
        }

    
        //binary search for the right row
        while(lowrow <= highrow){
            int mid = lowrow + (highrow - lowrow)/2;

            if (matrix[mid][0] <= target && target <= matrix[mid][n] ){ // on the right row
                correctrow = mid;
                break;
            }
            else if (matrix[mid][n] < target){// if mid row is too small
                lowrow = mid+1;
            }
            else if (matrix[mid][0] > target){// if mid row is too large
                highrow = mid-1;
            }
        }
        // binary search the correct row for the target.
        int lowcol = 0;
        int highcol = n;
        while (lowcol <= highcol){
            int mid = lowcol + (highcol - lowcol)/2; 
            
            if (matrix[correctrow][mid] == target ){
                return true;
            }
            else if (matrix[correctrow][mid] < target){// if mid row is too small
                lowcol = mid+1;
            }
            else if (matrix[correctrow][mid] > target){// if mid row is too large
                highcol = mid-1;
            }
        
        }
        return false;
    }
};