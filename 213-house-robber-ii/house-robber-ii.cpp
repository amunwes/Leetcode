class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();  
        if(n==1)
            return nums[0];

        int rob1 = robber(nums, 0, n-2);
        int rob2 = robber(nums, 1, n-1);
        return max(rob1, rob2);
    }
private:
    int robber(vector<int>& nums, int start, int end){
        int prev1, prev2, curr;
        prev1 = prev2 = curr = 0;

        for (int i = start; i<=end; i++){
            int temp = curr;
            curr = nums[i] + max(prev1, prev2);
            prev1 = prev2;
            prev2 = temp;
        }
        return(max(prev2,curr));
    }
};