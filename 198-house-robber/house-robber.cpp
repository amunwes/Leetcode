class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int temp;
        int first = 0;

        if(n<2){
            return nums[0];
        }
        
        int second = nums[0];
        int third = nums[1];

        for (int i = 2; i<nums.size(); i++){
            temp = third;
            third = nums[i] + max(first,second);
            first = second;
            second = temp;
        } 
        return max(second,third);
    }
};