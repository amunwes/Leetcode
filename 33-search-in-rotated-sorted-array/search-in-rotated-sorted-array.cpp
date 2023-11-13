class Solution {
public:
    int search(vector<int>& nums, int target) {
        int top = nums.size()-1;
        int bot = 0;
        int result = -1;
                
            // unsorted binary search.
        while(bot <= top){
            int mid = bot + (top-bot)/2;

            if(nums[mid]==target){//bingo
                return mid;
            }
            else if(nums[bot]<=nums[mid]){// if low and mid are in order
                //if target is between low and mid
                if(nums[bot]<=target && target<=nums[mid]){
                    //bring the upper down to where we tested.
                    top = mid-1;
                }else{//otherwise bring the bottom up cause its not in this section.
                    bot = mid+1;
                }
            }else{//mid isnt in order with bot so it must be in order with top
                if(nums[mid]<=target && target<=nums[top])// check if its in the range
                    bot = mid+1;
                else{
                    top = mid-1;
                }
            }

        }
        
        return -1;
    }
};