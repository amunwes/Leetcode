class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, curr, target ,result);
        return result;

    }
private:
    void dfs(int index, vector<int>& candidates, vector<int>& curr, int target, vector<vector<int>>& result){
        if (target == 0){
            result.push_back(curr);
            return;
        }
        if( target < 0){
            return; 
        }
        for(int i = index; i< candidates.size(); i++){
            if( i > index && candidates[i] == candidates[i-1]){//check for duplicate candidate.
                continue;
            }
            curr.push_back(candidates[i]);
            dfs(i + 1, candidates, curr, target - candidates[i], result);
            curr.pop_back();

        }
        



    }
};