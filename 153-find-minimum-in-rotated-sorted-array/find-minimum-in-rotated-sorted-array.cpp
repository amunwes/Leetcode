class Solution {
public:
    int findMin(vector<int>& nums) {
        int top = nums.size()-1;
        int bot = 0;
        int result;
        if(nums.size()<=1){
            return nums[0];
        }

        if(nums[0]<nums[top]){ // if this is true then the array is sorted and nums[0] is smallest
            return nums[0];
        }else{// otherwise we binary search.
            result = nums[top];
            while(bot <= top){
                int mid = bot + (top-bot)/2;
                if(nums[mid]<= result){
                    result = nums[mid];
                    top = mid-1;
                }else{
                    bot = mid+1;
                }

            }
        }
        return result;

        
    }
};