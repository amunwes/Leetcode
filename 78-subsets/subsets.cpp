class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> result;
        dfs(nums, 0, result, curr);
        return result;
    }
private:
    void dfs(vector<int>& nums, int i, vector<vector<int>>& result, vector<int> &curr){
        if (i >= nums.size()){
            result.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        dfs(nums, i + 1, result, curr);
        curr.pop_back();
        dfs(nums, i + 1, result, curr);
        
    }
};