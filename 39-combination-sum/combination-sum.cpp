class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        int currSum = 0;
        dfs(candidates, target, result, curr, currSum, 0);
        return result;
    }
private:
    void dfs(vector<int>& candidates, int& target, vector<vector<int>>& result, vector<int>& curr, int& currSum, int index){
        for (int i = index; i<candidates.size(); i++ ){
            currSum += candidates[i];
            curr.push_back(candidates[i]);
            
            if (currSum == target){
                result.push_back(curr);
            }
            if(currSum < target){
                dfs(candidates, target, result, curr, currSum, i);
            }

            currSum -= curr.back();
            curr.pop_back();        

        }
    }
};