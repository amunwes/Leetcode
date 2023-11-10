class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // simple 2 sum, compare 2 different indexes if target is too low or 2 high we increment 
        // the corresponding index until we reach the solution or the 2 index's meet
        
        int i = 0, j = numbers.size() -1;
        vector<int> result ;
        int sum = numbers[i] + numbers[j];
        result = {i+1,j+1};
        
        while (i != j && sum != target ){
            
            sum = numbers[i] + numbers[j];
            
            if (sum > target)
                j--;
            else if (sum < target)
                i++;
            else{
                result = {i+1,j+1};
            }

        }
        return result;
    }
};